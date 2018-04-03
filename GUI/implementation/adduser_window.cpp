#include "GUI/header/adduser_window.h"

AddUser_Window::AddUser_Window(User_list& accounts, QDialog* parent):QDialog(parent), list(accounts)
{

    layout=new QGridLayout;
    setWindowTitle("pannello aggiunta utente");

    explaination=new QLabel;
        explaination->setText("inserire dati nuovo account");
    IDlabel=new QLabel;
        IDlabel->setText("ID");

    ID_allarm=new QLabel;
        ID_allarm->setText("ID già in uso");
        ID_allarm->setStyleSheet("QLabel { background-color : red;}");
        ID_allarm->hide();

    ID_insert=new QLineEdit;

    passlabel=new QLabel;
        passlabel->setText("password");
    pass_insert=new QLineEdit;

    namelabel=new QLabel;
        namelabel->setText("name");
    name_insert=new QLineEdit;

    surnamelabel=new QLabel;
        surnamelabel->setText("surname");
    surname_insert=new QLineEdit;

    typeaccountlabel=new QLabel;
        typeaccountlabel->setText("status");


    statusmenu=new QMenu;
        statusmenu->addAction("admin");
        statusmenu->addAction("premium_User");
        statusmenu->addAction("common_User");


    typeaccount_chooser=new myButton;
        typeaccount_chooser->setMenu(statusmenu);
        typeaccount_chooser->setText("Selezionare status nuovo utente");
        connect(statusmenu, SIGNAL(triggered(QAction*)), typeaccount_chooser, SLOT(setAction(QAction*)));


    adder=new QPushButton;
        adder->setText("aggiungi utente");
        connect(adder, SIGNAL(clicked(bool)), this, SLOT(checker_adder()));
        connect(adder, SIGNAL(clicked(bool)), parent, SLOT(refresh()));

    setWindowTitle("Pannello Aggiunta Utente");

    layout->addWidget(explaination, 0, 0);
    layout->addWidget(IDlabel, 1, 0);
    layout->addWidget(ID_insert,1, 1);
    layout->addWidget(ID_allarm, 1, 2);
    layout->addWidget(passlabel, 2, 0);
    layout->addWidget(pass_insert, 2, 1);
    layout->addWidget(namelabel, 3, 0);
    layout->addWidget(name_insert, 3, 1);
    layout->addWidget(surnamelabel, 4, 0);
    layout->addWidget(surname_insert, 4, 1);
    layout->addWidget(typeaccountlabel, 5, 0);
    layout->addWidget(typeaccount_chooser, 5, 1);
    layout->addWidget(adder, 6, 0);

    setLayout(layout);

    this->show();
}

void AddUser_Window::checker_adder(){
    if(!list.search(ID_insert->text().toStdString())){
        account* newaccount;
        if(typeaccount_chooser->text().toStdString()=="admin"){
                newaccount= new accountAdmin(ID_insert->text().toStdString(), pass_insert->text().toStdString(),
                                         name_insert->text().toStdString(), surname_insert->text().toStdString(),
                                         typeaccount_chooser->text().toStdString());
        }
        if(typeaccount_chooser->text().toStdString()=="premium_User"){
            newaccount= new accountPremium(ID_insert->text().toStdString(), pass_insert->text().toStdString(),
                                     name_insert->text().toStdString(), surname_insert->text().toStdString(),
                                     typeaccount_chooser->text().toStdString());
        }

        else{
            newaccount= new account(ID_insert->text().toStdString(), pass_insert->text().toStdString(),
                                     name_insert->text().toStdString(), surname_insert->text().toStdString(),
                                     typeaccount_chooser->text().toStdString());
        }

        list.insertAccount(newaccount);
        QMessageBox* added=new QMessageBox;
            added->setText("account aggiunto correttamente");
            added->exec();
            this->close();
    }
    else{
        QMessageBox* alreadyexists=new QMessageBox;
            alreadyexists->setWindowTitle("ERRORE");
            alreadyexists->setText("ID già in uso, si prega di sceglierne un altro");
            alreadyexists->exec();
            this->ID_insert->clear();
            ID_allarm->show();
    }
}
