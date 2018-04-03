#include "GUI/header/modifyvehicle_window.h"

modifyVehicle_window::modifyVehicle_window(Veicolo & mod, QWidget* parent, bool& b):QDialog(parent), vehicle(mod), change_done(b){
    insertcommonfeatures();
}

void modifyVehicle_window::insertcommonfeatures(){
    setWindowTitle("pannello modifica veicolo");
    layout=new QGridLayout;
    description=new QLabel;
    description->setText("modificare i dati desiderati");

    produttore=new QLineEdit;
        produttore->setText(QString::fromStdString(vehicle.getProduttore()));
    produttore_label=new QLabel;
        produttore_label->setText("marchio:");
    nomeCommerciale=new QLineEdit;
        nomeCommerciale->setText(QString::fromStdString(vehicle.getNome()));
    nomeCommerciale_label=new QLabel;
        nomeCommerciale_label->setText("nome commerciale:");
    versione=new QLineEdit;
        versione->setText(QString::fromStdString(vehicle.getVersione()));
    versione_label=new QLabel;
        versione_label->setText("versione:");
    carburante=new myButton;
        carburante->setText(QString::fromStdString(vehicle.getCarburante()));
    carburante_label=new QLabel;
        carburante_label->setText("carburante:");
    cavalli=new QLineEdit;
        cavalli->setText(QString::fromStdString(std::to_string(vehicle.getPotenza())));
    cavalli_label=new QLabel;
        cavalli_label->setText("cavalli:");
    Nruote=new myButton;
        Nruote->setText(QString::fromStdString(std::to_string(vehicle.getNumeroruote())));
    Nruote_label=new QLabel;
        Nruote_label->setText("numero ruote:");
    cilindrata=new QLineEdit;
        cilindrata->setText(QString::fromStdString(std::to_string(vehicle.getCubatura())));
    cilindrata_label=new QLabel;
        cilindrata_label->setText("cilindrata:");
    posti=new myButton;
        posti->setText(QString::fromStdString(std::to_string(vehicle.getpasseggeri())));
    posti_label=new QLabel;
        posti_label->setText("posti auto omologati:");
    consumoMedio=new QLineEdit;
        consumoMedio->setText(QString::fromStdString(std::to_string(vehicle.getConsumoMedio())));
    consumoMedio_label=new QLabel;
        consumoMedio_label->setText("consumo medio:");
    norma_antinquinamento=new myButton;
        norma_antinquinamento->setText(QString::fromStdString(vehicle.getNormaAntinquinamento()));
    norma_antinquinamento_label=new QLabel;
        norma_antinquinamento_label->setText("norma antinquinamento:");
    cambio=new myButton;
        cambio->setText(QString::fromStdString(vehicle.getCambio()));
    cambio_label=new QLabel;
        cambio_label->setText("tipo di cambio:");

    inizioproduzione_label=new QLabel;
        inizioproduzione_label->setText("data inizio produzione (dd/mm/yyyy):");

    inizioproduzione_day=new QLineEdit;
        inizioproduzione_day->setText(QString::fromStdString(std::to_string(vehicle.getInizioProduzione().day())));
    inizioproduzione_month=new QLineEdit;
        inizioproduzione_month->setText(QString::fromStdString(std::to_string(vehicle.getInizioProduzione().month())));
    inizioproduzione_year=new QLineEdit;
        inizioproduzione_year->setText(QString::fromStdString(std::to_string(vehicle.getInizioProduzione().year())));

    fineproduzione_day=new QLineEdit;
        fineproduzione_day->setText((QString::fromStdString(std::to_string(vehicle.getInizioProduzione().day()))));
    fineproduzione_month=new QLineEdit;
        fineproduzione_month->setText((QString::fromStdString(std::to_string(vehicle.getInizioProduzione().month()))));
    fineproduzione_year=new QLineEdit;
        fineproduzione_year->setText((QString::fromStdString(std::to_string(vehicle.getInizioProduzione().year()))));


    fineproduzione_label=new QLabel;
        fineproduzione_label->setText("data fine produzione (dd/mm/yyyy):");

        Nruote_edit=new QMenu;
        connect(Nruote_edit, SIGNAL(triggered(QAction*)),Nruote, SLOT(setAction(QAction*)));
        carburante_edit=new QMenu;
        connect(carburante_edit, SIGNAL(triggered(QAction*)), carburante, SLOT(setAction(QAction*)));
        posti_edit=new QMenu;
        connect(posti_edit, SIGNAL(triggered(QAction*)), posti, SLOT(setAction(QAction*)));
        norma_antinquinamento_edit=new QMenu;

        norma_antinquinamento_edit->addAction("euro 0");
        norma_antinquinamento_edit->addAction("euro 1");
        norma_antinquinamento_edit->addAction("euro 2");
        norma_antinquinamento_edit->addAction("euro 3");
        norma_antinquinamento_edit->addAction("euro 4");
        norma_antinquinamento->setMenu(norma_antinquinamento_edit);
        connect(norma_antinquinamento_edit, SIGNAL(triggered(QAction*)),norma_antinquinamento, SLOT(setAction(QAction*)));

        cambio_edit=new QMenu;
        connect(cambio_edit, SIGNAL(triggered(QAction*)), cambio, SLOT(setAction(QAction*)));

        changer=new QPushButton;
        changer->setText("modifica");
        connect(changer, SIGNAL(clicked(bool)), this, SLOT(modify()));

        layout->addWidget(description,0,0);
        layout->addWidget(changer,0,1);
        layout->addWidget(produttore_label, 1, 0);
        layout->addWidget(produttore, 1,1);
        layout->addWidget(nomeCommerciale_label, 2,0);
        layout->addWidget(nomeCommerciale, 2, 1);
        layout->addWidget(versione_label,3,0);
        layout->addWidget(versione, 3, 1);
        layout->addWidget(carburante_label,4,0);
        layout->addWidget(carburante,4,1);
        layout->addWidget(cavalli_label,5,0);
        layout->addWidget(cavalli,5,1);
        layout->addWidget(Nruote_label,6,0);
        layout->addWidget(Nruote,6,1);
        layout->addWidget(cilindrata_label,7,0);
        layout->addWidget(cilindrata,7,1);
        layout->addWidget(posti_label,8,0);
        layout->addWidget(posti,8,1);
        layout->addWidget(consumoMedio_label,9,0);
        layout->addWidget(consumoMedio, 9, 1);
        layout->addWidget(norma_antinquinamento_label,10,0);
        layout->addWidget(norma_antinquinamento,10,1);
        layout->addWidget(cambio_label,11,0);
        layout->addWidget(cambio,11,1);
        layout->addWidget(inizioproduzione_label,12,0);
        layout->addWidget(inizioproduzione_day,12,1);
        layout->addWidget(inizioproduzione_month,12,2);
        layout->addWidget(inizioproduzione_year,12,3);
        layout->addWidget(fineproduzione_label,13,0);
        layout->addWidget(fineproduzione_day,13,1);
        layout->addWidget(fineproduzione_month,13,2);
        layout->addWidget(fineproduzione_year,13,3);

        setLayout(layout);
        exec();
}

void modifyVehicle_window::modifyproduttore(){
    if(vehicle.getProduttore()!=produttore->text().toStdString()){
        vehicle.setProduttore(produttore->text().toStdString());
        change_done=true;
    }
}

void modifyVehicle_window::modifynomecommerciale(){
    if(vehicle.getNome()!=nomeCommerciale->text().toStdString()){
        vehicle.setNomeCommerciale(nomeCommerciale->text().toStdString());
        change_done=true;
    }
}

void modifyVehicle_window::modifyversione(){
    if(vehicle.getVersione()!=versione->text().toStdString()){
        vehicle.setVersione(versione->text().toStdString());
        change_done=true;
    }
}

void modifyVehicle_window::modifycarburante(){
    if(vehicle.getCarburante()!=carburante->text().toStdString()){
        vehicle.setCarburante(carburante->text().toStdString());
        change_done=true;
    }
}

void modifyVehicle_window::modifycavalli(){
    if(vehicle.getPotenza()!=cavalli->text().toInt()){
        vehicle.setCavalli(cavalli->text().toInt());
        change_done=true;
    }
}

void modifyVehicle_window::modifyNruote(){
    if(vehicle.getNumeroruote()!=Nruote->text().toInt()){
        vehicle.setNruote(Nruote->text().toInt());
        change_done=true;
    }
}

void modifyVehicle_window::modifycilindrata(){
    if(vehicle.getCubatura()!=cilindrata->text().toInt()){
        vehicle.setCilindrata(cilindrata->text().toInt());
        change_done=true;
    }
}

void modifyVehicle_window::modifyposti(){
    if(vehicle.getpasseggeri()!=posti->text().toInt()){
        vehicle.setPosti(posti->text().toInt());
        change_done=true;
    }
}

void modifyVehicle_window::modifyconsumoMedio(){
    if(vehicle.getConsumoMedio()!=consumoMedio->text().toDouble()){
        vehicle.setConsumoMedio(consumoMedio->text().toDouble());
        change_done=true;
    }
}

void modifyVehicle_window::modifynorma_antinquinamento(){
    if(vehicle.getNormaAntinquinamento()!=norma_antinquinamento->text().toStdString()){
        vehicle.setNorma_antinquinamento(norma_antinquinamento->text().toStdString());
        change_done=true;
    }
}

void modifyVehicle_window::modifycambio(){
    if(vehicle.getCambio()!=cambio->text().toStdString()){
        vehicle.setCambio(cambio->text().toStdString());
        change_done=true;
    }
}

void modifyVehicle_window::modifyinizioproduzione(){
    if(vehicle.getInizioProduzione().day()!=inizioproduzione_day->text().toInt() || vehicle.getInizioProduzione().month()!=inizioproduzione_month->text().toInt() || vehicle.getInizioProduzione().year()!=inizioproduzione_year->text().toInt()){
        int day=inizioproduzione_day->text().toInt();
        int month=inizioproduzione_month->text().toInt();
        int year=inizioproduzione_year->text().toInt();
        QDate* inizio=new QDate(day, month, year);
        vehicle.setInizioproduzione(*inizio);
        change_done=true;
    }
}

void modifyVehicle_window::modifyfineproduzione(){
    if(vehicle.getFineProduzione().day()!=fineproduzione_day->text().toInt() || vehicle.getFineProduzione().month()!=fineproduzione_month->text().toInt() || vehicle.getFineProduzione().year()!=fineproduzione_year->text().toInt()){
        int day=fineproduzione_day->text().toInt();
        int month=fineproduzione_month->text().toInt();
        int year=fineproduzione_year->text().toInt();
        QDate* fine=new QDate(day, month, year);
        vehicle.setFineproduzione(*fine);
        change_done=true;
    }
}

void modifyVehicle_window::modify(){
     modifyproduttore();
     modifynomecommerciale();
     modifyversione();
     modifycarburante();
     modifycavalli();
     modifyNruote();
     modifycilindrata();
     modifyposti();
     modifyconsumoMedio();
     modifynorma_antinquinamento();
     modifycambio();
     modifyinizioproduzione();
     modifyfineproduzione();
     close();
}
