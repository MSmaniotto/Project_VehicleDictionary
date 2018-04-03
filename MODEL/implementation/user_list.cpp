#include "MODEL/header/user_list.h"

User_list::User_list(){}

QString User_list::StarterWord="Account";
QString User_list::UserFile="users.xml";


const account* User_list::search(std::string ID) const{
    for(auto it=begin(); it!=end(); it++){
        if((*it)->getID()==ID){
            return *it;
        }
    }
    return 0;
}

void User_list::modifyaccount(std::string ID, std::string password, std::string name, std::string surname){
    auto it=begin();
    bool stop=false;
    while(it!=end() &&!stop){
        if((*it)->getID()==ID)
            stop=true;
    }

    if(password!=((*it)->getpassword()))
        (const_cast<account&>(**it)).setpassword(password);
    if(name!=((*it)->getname()))
        (const_cast<account&>(**it)).setname(name);
    if(surname!=((*it)->getsurname()))
        (const_cast<account&>(**it)).setsurname(surname);
}

bool User_list::insertAccount(account *acc){
    if(!search(acc->getID())){
        push_back(acc->copia());
        XmlExporter();
        return true;
    }
    return false;
}

void User_list::deleteaccount(std::string ID){
    bool found=false;
    for(auto it=begin(); !found && it!=end(); it++){
        if((*it)->getID()==ID){
            it=erase(it);
            it--;
            found=true;
        }
    }
    if(found){
        XmlExporter();
    }
}

bool User_list::XmlImporter(){
    if(size())
        erase(begin(), end());
    bool done=false;

    QFile file(UserFile);
    if(file.open(QFile::ReadOnly)){// | QFile::Text)){
        QXmlStreamReader input(&file);

        while(input.readNextStartElement()){
            if(input.name()==StarterWord){
                while(input.readNextStartElement()){
                    QString ID=0, password=0, name=0, surname=0, typeaccount=0;
                    ID=import(input, "ID");
                    password=import(input, "password");
                    name=import(input, "name");
                    surname=import(input, "surname");
                    typeaccount=import(input, "status");

                    if(!ID.isNull() && !password.isNull()){
                        account* ac;
                        if(typeaccount.toStdString()=="admin")
                            ac=new accountAdmin(ID.toStdString(), password.toStdString(), name.toStdString(), surname.toStdString(), typeaccount.toStdString());
                        if(typeaccount.toStdString()=="premium_User")
                            ac=new accountPremium(ID.toStdString(), password.toStdString(), name.toStdString(), surname.toStdString(), typeaccount.toStdString());
                        else
                            ac=new account(ID.toStdString(), password.toStdString(), name.toStdString(), surname.toStdString(), typeaccount.toStdString());

                        bool b=insertAccount(ac);

                        if(!done)
                            done=b;
                        delete ac;
                    }
                    input.skipCurrentElement();
                }
            }
        }
        file.close();
    }
    return done;
}

void User_list::XmlExporter() const{
    QFile file(UserFile);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlout(&file);

    xmlout.setAutoFormatting(true);
    xmlout.writeStartDocument();
    xmlout.writeStartElement(StarterWord);
    for(auto it=begin(); it!=end(); it++){

        (*it)->XmlWriter(xmlout);

    }
    xmlout.writeEndElement();
    xmlout.writeEndDocument();
    file.close();
}

void User_list::createAdmin(){
    account* admin=new account("admin", "admin", "admin", "admin", "admin");
    insertAccount(admin);
}

User_list::~User_list(){
    if(size())
        erase(begin(), end());
}
