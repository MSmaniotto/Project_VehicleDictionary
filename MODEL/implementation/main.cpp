#include <QApplication>
#include "GUI/header/mymainwindow.h"
#include "GUI/header/login_window.h"
#include "MODEL/header/user_list.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    User_list* users=new User_list;


    if(!users->XmlImporter()){
        users->createAdmin();
        users->XmlExporter();
    }

    bool go_on=false;

    account acc;
    new login_window(*users, go_on, acc);


    if(go_on){
        MyMainWindow* win;
        if(acc.getStatus()=="common_User")
            win=new MyMainWindow(*users, &acc);
        if(acc.getStatus()=="admin")
            win=new MyMainWindow(*users, new accountAdmin(acc.getID(), acc.getpassword(), acc.getname(), acc.getsurname(), acc.getStatus()));
        if(acc.getStatus()=="premium_User")
            win=new MyMainWindow(*users, new accountPremium(acc.getID(), acc.getpassword(), acc.getname(), acc.getsurname(), acc.getStatus()));
        win->show();
        return app.exec();
    }
    return 0;
}
