#include "GUI/header/modifyuser_window.h"


modifyUser_window::modifyUser_window(QWidget* parent, account& user, bool& change):QDialog(parent), acc(user), change_done(change){
    layout=new QGridLayout;
    setWindowTitle("pannello modifica utenti");
    description=new QLabel;
    description->setText("modificare i dati desiderati; non sono ammesse password nulle");
    ID=new QLabel;
        ID->setText("ID:");
    ID_show=new QLabel;
        ID_show->setText(QString::fromStdString(acc.getID()));
    password=new QLabel;
        password->setText("password:");
    password_change=new QLineEdit;
        password_change->setText(QString::fromStdString(acc.getpassword()));
    name=new QLabel;
        name->setText("name:");
    name_change=new QLineEdit;
        name_change->setText(QString::fromStdString(acc.getname()));
    surname=new QLabel;
        surname->setText("surname:");
    surname_change=new QLineEdit;
        surname_change->setText(QString::fromStdString(acc.getsurname()));
    changer=new QPushButton;
        changer->setText("modifica");
        connect(changer, SIGNAL(clicked(bool)), this, SLOT(accountrefresher()));


    layout->addWidget(description,0,0);
    layout->addWidget(ID,1,0);
    layout->addWidget(ID_show,1,1);
    layout->addWidget(password,2,0);
    layout->addWidget(password_change,2,1);
    layout->addWidget(name,3,0);
    layout->addWidget(name_change,3,1);
    layout->addWidget(surname,4,0);
    layout->addWidget(surname_change,4,1);
    layout->addWidget(changer,5,0,1,2);
    setLayout(layout);

}

void modifyUser_window::passwordchanger(){
    if(acc.getpassword()!=password_change->text().toStdString()){
        acc.setpassword(password_change->text().toStdString());
    }
}

void modifyUser_window::namechanger(){
    if(acc.getname()!=name_change->text().toStdString()){
        acc.setname(name_change->text().toStdString());
    }
}

void modifyUser_window::surnamechanger(){
    if(acc.getsurname()!=surname_change->text().toStdString()){
        acc.setsurname(surname_change->text().toStdString());
    }
}

void modifyUser_window::accountrefresher(){
    passwordchanger();
    namechanger();
    surnamechanger();
    change_done=true;
    this->close();
}
