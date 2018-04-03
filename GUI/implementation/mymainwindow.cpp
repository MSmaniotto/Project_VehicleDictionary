#include "GUI/header/mymainwindow.h"



MyMainWindow::MyMainWindow(User_list& users, account* actual_user, QWidget* parent): accounts(users), activeuser(*actual_user){
    setWindowTitle("VehicleDictionary");
    setParent(parent);
    listaVeicoli=*(new Vehicle_list);
    if(!listaVeicoli.XmlImporter()){
        QMessageBox avviso;
        avviso.setText("non vi sono veicoli presenti nel database, si prega di contattare l'amministratore per popolarlo");
        avviso.setWindowTitle("Database vuoto");
        avviso.exec();
    }

    setFixedSize(640,320);

  myGrid=new QGridLayout();

    buttonLayout=new QGridLayout();

    VehicleTypemenu=new QMenu; //menu per la selezione del tipo di veicolo di interesse
        VehicleTypemenu->addAction("Automobile");
        VehicleTypemenu->addAction("Autocarro");
        VehicleTypemenu->addAction("Motociclo");

    VehicleBrandMenu=new QMenu;

    VehicleNamesMenu=new QMenu;

    VehicleSelect=new myButton(); //pulsante che cambia scritta in base ai signal ricevuti da QMenu
        VehicleSelect->setText("Scegli tipologia veicolo");
        VehicleSelect->setFixedSize(150, 30);
        VehicleSelect->ChangeMenu(VehicleTypemenu);
        connect(VehicleTypemenu, SIGNAL(triggered(QAction*)), VehicleSelect, SLOT(setAction(QAction*)));
        connect(VehicleTypemenu, SIGNAL(triggered(QAction*)), this, SLOT(addmenu_brand_list(QAction*)));


    typelabel=new QLabel();
        typelabel->setText("                 Tipologia:");

    VehicleBrand=new myButton(this);
        VehicleBrand->setText("Scegli marchio veicolo");
        VehicleBrand->setFixedSize(150, 30);
        VehicleBrand->ChangeMenu(VehicleBrandMenu);
        VehicleBrand->setEnabled(false);

        connect(VehicleBrandMenu, SIGNAL(triggered(QAction*)), VehicleBrand, SLOT(setAction(QAction*)));
        connect(VehicleBrandMenu, SIGNAL(triggered(QAction*)), this, SLOT(addmenu_NameOfVehicles(QAction*)));


    brandlabel=new QLabel("                 Marchio:", this);
        brandlabel->setBuddy(VehicleBrand);

    VehicleName=new myButton(this);
        VehicleName->setText("Scegli nome veicolo");
        VehicleName->setFixedSize(150, 30);
        VehicleName->ChangeMenu(VehicleNamesMenu);
        VehicleName->setEnabled(false);

        connect(VehicleNamesMenu, SIGNAL(triggered(QAction*)), VehicleName, SLOT(setAction(QAction*)));
        connect(VehicleNamesMenu, SIGNAL(triggered(QAction*)), this, SLOT(refreshlist(QAction*)));

    namelabel=new QLabel("              Nome:", this);
        namelabel->setBuddy(VehicleName);
        namelabel->setMargin(10);

    vehicles_list=new QListWidget;
    connect(vehicles_list, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(openVehicleShow()));

    istruzioni=new QLabel;
    istruzioni->setText("-------------------------------------------------------------------\nistruzioni: una volta selezionata la tipologia,\n il marchio e il nome del veicolo desiderato\n cliccare due volte sul veicolo che compare a destra\n per far comparire le sue caratteristiche complete");



    buttonLayout->addWidget(typelabel, 1, 0);
    buttonLayout->addWidget(VehicleSelect, 1, 1);
    buttonLayout->addWidget(brandlabel, 2, 0);
    buttonLayout->addWidget(VehicleBrand, 2, 1);
    buttonLayout->addWidget(namelabel, 3, 0);
    buttonLayout->addWidget(VehicleName, 3, 1);
    buttonLayout->addWidget(vehicles_list,1,4,5,1);


    accountAdmin* admin=dynamic_cast<accountAdmin*>(actual_user);
    accountPremium* premium=dynamic_cast<accountPremium*>(actual_user);
    description=new QLabel;
    if(!admin && !premium){
        description->setText("Pannello utente base");
        QLabel* info=new QLabel;
        info->setText(QString::fromStdString("ciao "+actual_user->getname()+" "+actual_user->getsurname()+"\n                                                       tempo rimanente: "));
        countdowntimer* timer=new countdowntimer(this, 1, 0);
        timer->getTimer()->start(1000);
        timer->setMaximumWidth(50);
        buttonLayout->addWidget(info, 6, 0, 2, 2);
        buttonLayout->addWidget(timer, 6, 2, 1, 1);
        buttonLayout->addWidget(istruzioni,10,0,2,3);
    }


    if(premium && !admin){
        description->setText("Pannello utente Premium");
        QLabel* info=new QLabel;
        info->setText(QString::fromStdString("ciao "+actual_user->getname()+" "+actual_user->getsurname()+"\nHai tutto il tempo che desideri per usare l'applicazione!"));
        buttonLayout->addWidget(info, 8, 0, 1, 2);
        buttonLayout->addWidget(istruzioni,10,0,2,3);
    }


    if(admin){
        description->setText("Pannello Amministratore");

        this->setWindowTitle("ADMIN SCREEN");

        QPushButton* create_vehicles=new QPushButton;
            create_vehicles->setText("aggiungi veicolo");
            create_vehicles->setMinimumSize(150, 70);
            connect(create_vehicles, SIGNAL(clicked(bool)), this, SLOT(openVehicleChooserToAdd()));
            connect(create_vehicles, SIGNAL(clicked(bool)), this, SLOT(reset()));

        QPushButton* all_users=new QPushButton;
            all_users->setText("aggiungi utente");
            all_users->setMinimumSize(150, 70);
            connect(all_users, SIGNAL(clicked(bool)), this, SLOT(openUsers_panel()));

            deletevehicle=new QPushButton;
            deletevehicle->setEnabled(false);
            deletevehicle->setText("rimuovi veicolo");
            connect(deletevehicle, SIGNAL(clicked(bool)),this, SLOT(callvehicleremover()));

            modifyvehicle=new QPushButton;
            modifyvehicle->setEnabled(false);
            modifyvehicle->setText("modifica veicolo");
            connect(modifyvehicle, SIGNAL(clicked(bool)), this, SLOT(callvehiclemodify()));

            connect(vehicles_list, SIGNAL(clicked(QModelIndex)), this, SLOT(enable_buttons()));

        buttonLayout->addWidget(create_vehicles, 6, 0, 2, 1);
        buttonLayout->addWidget(all_users, 6,1,2,2);
        buttonLayout->addWidget(deletevehicle,6,4,1,2);
        buttonLayout->addWidget(modifyvehicle,7,4,1,2);
    }
    buttonLayout->addWidget(description,5,0);

    myGrid->addLayout(buttonLayout, 0, 0);


    myGrid->setColumnStretch(1, 50);
    myGrid->setColumnMinimumWidth(0, 100);
    myGrid->setAlignment(Qt::AlignTop);
    this->setLayout(myGrid);
}

void MyMainWindow::openUsers_panel(){
    users_panel* panel=new users_panel(this, accounts);
    panel->show();
}

void MyMainWindow::openCarAdder(){
    std::string car="Automobile";
    addvehicle_window* addcar=new addvehicle_window(car, this, listaVeicoli);
    addcar->show();
}

void MyMainWindow::openVehicleChooserToAdd(){
    typevehicle_chooser* chooser=new typevehicle_chooser(this);
    chooser->show();
}

void MyMainWindow::openCamionAdder(){
    std::string camion="Autocarro";
    addvehicle_window* addcamion=new addvehicle_window(camion, this, listaVeicoli);
    addcamion->show();
}

void MyMainWindow::openMotorbikeAdder(){
    std::string moto="Motociclo";
    addvehicle_window* addmotorbike=new addvehicle_window(moto, this, listaVeicoli);
    addmotorbike->show();
}

void MyMainWindow::openVehicleShow(){
    int row=vehicles_list->currentIndex().row();
    auto it=selection.begin();
    //row=row-1;
    while(row&&it!=selection.end())
        it=it++;
    const Veicolo* v=*it;
    showVehicle_window* showWindow= new showVehicle_window(v);
    showWindow->show();
}

void MyMainWindow::addmenu_NameOfVehicles(QAction* activeAction){
    resetVehicleNamesMenu();

    for(auto it=listaVeicoli.begin(); it!=listaVeicoli.end();it++){
        if((*it)->getProduttore()==activeAction->text().toStdString()){
            bool found=false;
            if(!VehicleNamesMenu->actions().empty()){
                for(auto itna= vehicles_added.begin(); itna!=vehicles_added.end(); itna++){
                    if(*itna==((*it)->getNome()))
                        found=true;
                }
            }

            if(!found){
                VehicleNamesMenu->addAction(QString::fromStdString((*it)->getNome()));
                std::string* str=new std::string;
                *str=(*it)->getNome();
                vehicles_added.push_back(*str);
            }
        }
    }
    VehicleName->setEnabled(true);
    vehicles_added.clear();
}

void MyMainWindow::refreshlist(QAction* activeAction){
    if(vehicles_list->count())
        vehicles_list->clear();
    selection= listaVeicoli.search(VehicleBrand->text().toStdString(), activeAction->text().toStdString());
    if(selection.size()){
        for(auto it=selection.begin(); it!=selection.end(); it++){
            std::string str=std::to_string((*it)->getPotenza())+" CV";
            if(str=="0 CV")
                str="";
            QListWidgetItem* item=new QListWidgetItem(QString::fromStdString((*it)->getNome()+"  "+(*it)->getCarburante()+"  "+str));
            vehicles_list->addItem(item);
        }
    }
}

void MyMainWindow::addmenu_brand_list(QAction* act){
resetVehicleBrandMenu();

    for(auto it=listaVeicoli.begin(); it!=listaVeicoli.end();it++){
        bool ok=false;
        if(act->text().toStdString()=="Automobile"&& dynamic_cast<const automobile*>(*it))
            ok=true;


        if(act->text().toStdString()=="Autocarro"&& dynamic_cast<const autocarro*>(*it))
            ok=true;


        if(act->text().toStdString()=="Motociclo"&& dynamic_cast<const motociclo*>(*it))
            ok=true;


        if(ok){
            bool found=false;
            if(!VehicleBrandMenu->actions().empty()){
                for(auto itbr=vehicles_added.begin(); itbr!=vehicles_added.end(); itbr++){
                    std::string str=(*it)->getProduttore();
                    if(*itbr==str)
                        found=true;
                }
            }

            if(!found){
                QAction* act=new QAction(QString::fromStdString((*it)->getProduttore()), this);
                VehicleBrandMenu->addAction(act);
                std::string* str=new std::string;
                *str=(*it)->getProduttore();
                vehicles_added.push_back(*str);
            }
        }
    }
    if(!VehicleBrandMenu->actions().count()){
        QMessageBox avviso;
        avviso.setText("non vi sono veicoli di questo tipo nel database, si prega di contattare l'amministratore per popolarlo");
        avviso.setWindowTitle("Database vuoto");
        avviso.exec();
    }
    else{
        VehicleBrand->setEnabled(true);
    }
    vehicles_added.clear();
}

void MyMainWindow::reset(){
    QAction* act=new QAction(this);
    act->setText("Scegli tipologia veicolo");
    VehicleSelect->setAction(act);
    resetVehicleBrandMenu();
    listaVeicoli.XmlExporter();
}

void MyMainWindow::resetVehicleBrandMenu(){
    if(!VehicleBrandMenu->actions().empty()){
        VehicleBrandMenu->clear();
        if(vehicles_list->count())
            vehicles_list->clear();
        QAction* act=new QAction(this);
        act->setText("scegli marchio veicolo");
        VehicleBrand->setAction(act);
        VehicleBrand->setEnabled(false);
    }
    resetVehicleNamesMenu();
}

void MyMainWindow::resetVehicleNamesMenu(){
    if(!VehicleNamesMenu->actions().empty()){
        VehicleNamesMenu->clear();
        if(vehicles_list->count())
            vehicles_list->clear();
        QAction* act=new QAction(this);
        act->setText("Scegli nome veicolo");
        VehicleName->setAction(act);
        VehicleName->setEnabled(false);
    }
}

void MyMainWindow::enable_buttons(){
    if(activeuser.getStatus()=="admin")
        deletevehicle->setEnabled(true);
        modifyvehicle->setEnabled(true);
}

void MyMainWindow::callvehicleremover(){
    QMessageBox* alert=new QMessageBox;

    int reply = QMessageBox::question(alert,"Rimuovi", "Vuoi davvero rimuovere il veicolo "+vehicles_list->currentItem()->text()+"?","Si","No");
    if(reply==0)
    {
        auto it=selection.begin();
        int i=vehicles_list->currentIndex().row();
        while(i!=0){
            it++;
            i--;
        }

        listaVeicoli.deleteVehicle(const_cast<Veicolo&> (**it));
        reset();
    }

}

MyMainWindow::~MyMainWindow(){
    delete vehicles_list;
}

void MyMainWindow::callvehiclemodify(){
    auto it=selection.begin();
    int i=vehicles_list->currentIndex().row();
    while(i!=0){
        it++;
        i--;
    }
    bool ok=false;

    Veicolo& vehiclemod=const_cast<Veicolo&>(**it);

    new modifyVehicle_window(vehiclemod, this, ok);
    if(ok)
        reset();
}
