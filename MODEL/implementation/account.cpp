#include "MODEL/header/account.h"


//metodi e costruttori account
std::string account::getID()const{
    return ID;
}

std::string account::getpassword()const{
    return password;
}

std::string account::getname()const{
    return name;
}

std::string account::getsurname()const{
    return surname;
}

std::string account::getStatus()const{
    return status;
}

account::account(){}

account::account(std::string m, std::string pw, std::string n, std::string s, std::string Status="common"):ID(m), password (pw), name(n), surname(s), status(Status){}

bool account::operator !=(const account& acc){
    if(this->getID()==acc.getID())
         return false;
    return true;
}

void account::setID(const std::string& strID){
    if(ID!=strID)
        ID=strID;
}

void account::setStatus(const std::string& strStatus){
    if(status!=strStatus)
        status=strStatus;
}

void account::setname(const std::string& n){
    if(this->getname()!=n)
        name=n;
}

void account::setsurname(const std::string& s){
    if(getsurname()!=s)
        surname=s;
}

void account::setpassword(const std::string &pw){
    if(getpassword()!=pw)
        password=pw;
}

void account::XmlWriter(QXmlStreamWriter &out)const{
    out.writeStartElement(QString::fromStdString(status));
    out.writeTextElement("ID", QString::fromStdString(ID));
    out.writeTextElement("password", QString::fromStdString(password));
    out.writeTextElement("name", QString::fromStdString(name));
    out.writeTextElement("surname", QString::fromStdString(surname));
    out.writeTextElement("status", QString::fromStdString(status));
    out.writeEndElement();
}

account* account::copia()const{
    return new account(*this);
}


accountPremium::accountPremium(std::string id, std::string pw, std::string na, std::string surn, std::string Status="Premium"):account(id, pw, na, surn, Status){}

accountPremium* accountPremium::copia()const{
    return new accountPremium(*this);
}

accountAdmin::accountAdmin(std::string id, std::string pw, std::string na, std::string surn, std::string Status="Admin"):accountPremium(id, pw, na, surn, Status){}

accountAdmin* accountAdmin::copia()const{
    return new accountAdmin(*this);
}
