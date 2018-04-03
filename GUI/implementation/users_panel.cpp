#include "GUI/header/users_panel.h"


users_panel::users_panel(QWidget* parent, User_list& users):QDialog(parent),accounts(users){
    layout=new QGridLayout;
    setWindowTitle("pannello modifica utenti");

    add=new QPushButton;
        add->setText("aggiungi utente");
        connect(add, SIGNAL(clicked(bool)), this, SLOT(openUserAdder()));
    remover=new QPushButton;
        remover->setText("rimuovi utente");
        remover->setEnabled(false);

    modify=new QPushButton;
        modify->setText("modifica utente");
        modify->setEnabled(false);
    connect(remover, SIGNAL(clicked(bool)), this, SLOT(callaccountremover()));
    connect(modify, SIGNAL(clicked(bool)), this, SLOT(callaccountmodify()));
    items=new QListWidget;
    connect(items, SIGNAL(clicked(QModelIndex)), this, SLOT(enable_modify()));

    layout->addWidget(add,1,0);
    layout->addWidget(remover,2,0);
    layout->addWidget(modify,3,0);
    layout->addWidget(items,1, 1, 3, 1);
    populate();
    setLayout(layout);
}

void users_panel::populate(){
    auto it=accounts.begin();
    bool stop=false;
    while(!stop)
    {
        if((it)==accounts.end())
            stop=true;
        else{
            items->addItem(QString::fromStdString((*(it))->getID()));
            ++it;
        }
    }
}

void users_panel::refresh(){
    items->clear();
    populate();
}

void users_panel::callaccountremover(){
    QMessageBox* alert=new QMessageBox;

    int reply = QMessageBox::question(alert,"Rimuovi", "Vuoi davvero rimuovere l'utente "+items->currentItem()->text()+"?","Si","No");
    if(reply==0)
    {
        accounts.deleteaccount(items->currentItem()->text().toStdString());
        items->takeItem(items->currentIndex().row());
    }
}

void users_panel::callaccountmodify(){
    bool changed=false;
    try{const account& to_be_modified=*(accounts.search(items->currentItem()->text().toStdString()));
        modifyUser_window* panel=new modifyUser_window(this, const_cast<account&>(to_be_modified), changed);
        panel->exec();
        if(changed)
            accounts.XmlExporter();
    }
    catch (empty_error err){
        QMessageBox* error=new QMessageBox;
            error->setText("errore imprevisto, impossibile modificare l'account");
            error->exec();
            return;
    }
}

void users_panel::openUserAdder(){
    AddUser_Window* window=new AddUser_Window(accounts, this);
    window->show();
}

void users_panel::enable_modify(){
    modify->setEnabled(true);
    remover->setEnabled(true);
}

