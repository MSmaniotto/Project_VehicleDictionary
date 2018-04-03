#include "GUI/header/login_window.h"

login_window::login_window(User_list& UL, bool& done, account& accountvalue): lista(UL), ok(done), datapusher(accountvalue){
    setWindowTitle("Login");

    layout=new QGridLayout(this);
    ID=new QLabel();
        ID->setText("ID:");

    IDinput=new QLineEdit();

    pass=new QLabel();
        pass->setText("Password:");

    Passinput=new QLineEdit();
        Passinput->setEchoMode(QLineEdit::Password);

    loginbutton=new QPushButton();
        loginbutton->setText("login");
        connect(loginbutton, SIGNAL(clicked()), this, SLOT(login_action()));

    layout->addWidget(ID, 0, 0);
    layout->addWidget(IDinput, 0, 1);
    layout->addWidget(pass, 1, 0);
    layout->addWidget(Passinput, 1, 1);
    layout->addWidget(loginbutton, 2, 0, 1, 2);

    this->setLayout(layout);
    this->setFixedSize(200, 100);

    exec();
    accountvalue=datapusher;

}

void login_window::login_action(){
    const account* user=lista.search(IDinput->text().toStdString());
    if(user && user->getpassword()==Passinput->text().toStdString()){

        this->ok=true;

        datapusher.setID(user->getID());
        datapusher.setpassword(user->getpassword());
        datapusher.setname(user->getname());
        datapusher.setsurname(user->getsurname());
        datapusher.setStatus(user->getStatus());

        this->close();
    }
    else
    {
        QMessageBox* error=new QMessageBox;
        error->setWindowTitle("errore");
        error->setText("ID o password non corrette; riprova!");
        error->exec();
        Passinput->clear();
    }
}
