#include "GUI/header/showvehicle_window.h"

showVehicle_window::showVehicle_window(const Veicolo* v):vehicle(v){
        layout=new QGridLayout;
        QString title=QString::fromStdString(vehicle->getProduttore()+" "+vehicle->getNome());
        setWindowTitle(title);
        produttore=new QLabel;
            produttore->setText(QString::fromStdString(vehicle->getProduttore()));
        produttore_label=new QLabel;
            produttore_label->setText("marchio:");
        nomeCommerciale=new QLabel;
            nomeCommerciale->setText(QString::fromStdString(vehicle->getNome()));
        nomeCommerciale_label=new QLabel;
            nomeCommerciale_label->setText("nome commerciale:");
        versione=new QLabel;
            versione->setText(QString::fromStdString(vehicle->getVersione()));
        versione_label=new QLabel;
            versione_label->setText("versione:");
        carburante=new QLabel;
            carburante->setText(QString::fromStdString(vehicle->getCarburante()));
        carburante_label=new QLabel;
            carburante_label->setText("carburante:");
        cavalli=new QLabel;
            cavalli->setText(QString::fromStdString(std::to_string(vehicle->getPotenza())));
        cavalli_label=new QLabel;
            cavalli_label->setText("cavalli:");
        Nruote=new QLabel;
            Nruote->setText(QString::fromStdString(std::to_string(vehicle->getNumeroruote())));
        Nruote_label=new QLabel;
            Nruote_label->setText("numero ruote:");
        cilindrata=new QLabel;
            cilindrata->setText(QString::fromStdString(std::to_string(vehicle->getCubatura())));
            if(cilindrata->text().toStdString()=="0"){
                cilindrata->setText("");
            }
        cilindrata_label=new QLabel;
            cilindrata_label->setText("cilindrata:");
        posti=new QLabel;
            posti->setText(QString::fromStdString(std::to_string(vehicle->getpasseggeri())));
            if(posti->text().toStdString()=="0")
                posti->setText("");
        posti_label=new QLabel;
            posti_label->setText("posti auto omologati:");
        consumoMedio=new QLabel;
            consumoMedio->setText(QString::fromStdString(std::to_string(vehicle->getConsumoMedio())));
            if(consumoMedio->text().toStdString()=="0,000000")
                consumoMedio->setText("");
        consumoMedio_label=new QLabel;
            consumoMedio_label->setText("consumo medio:");
        norma_antinquinamento=new QLabel;
            norma_antinquinamento->setText(QString::fromStdString(vehicle->getNormaAntinquinamento()));
        norma_antinquinamento_label=new QLabel;
            norma_antinquinamento_label->setText("norma antinquinamento:");
        cambio=new QLabel;
            cambio->setText(QString::fromStdString(vehicle->getCambio()));
        cambio_label=new QLabel;
            cambio_label->setText("tipo di cambio:");

        inizioproduzione_label=new QLabel;
            inizioproduzione_label->setText("data inizio produzione:");

        inizioproduzione_date=new QLabel;
            inizioproduzione_date->setText(QString::fromStdString(std::to_string(vehicle->getInizioProduzione().day())+'/'+std::to_string(vehicle->getInizioProduzione().month())+'/'+std::to_string(vehicle->getInizioProduzione().year())));
            if(inizioproduzione_date->text().toStdString()=="0/0/0")
                inizioproduzione_date->setText("");

        fineproduzione_date=new QLabel;
            fineproduzione_date->setText(QString::fromStdString(std::to_string(vehicle->getFineProduzione().day())+'/'+std::to_string(vehicle->getFineProduzione().month())+'/'+std::to_string(vehicle->getFineProduzione().year())));
            if(fineproduzione_date->text().toStdString()=="0/0/0")
                fineproduzione_date->setText("");

        fineproduzione_label=new QLabel;
            fineproduzione_label->setText("data fine produzione:");

        if(dynamic_cast<const automobile*>(vehicle))
            addCarAttributes();
        if(dynamic_cast<const autocarro*>(vehicle))
            addCamionAttributes();
        if(dynamic_cast<const motociclo*>(vehicle))
            addMotorbikeAttributes();

        layout->addWidget(produttore_label, 0, 0);
        layout->addWidget(produttore, 0,1);
        layout->addWidget(nomeCommerciale_label, 0,2);
        layout->addWidget(nomeCommerciale, 0, 3);
        layout->addWidget(versione_label,1,0);
        layout->addWidget(versione, 1, 1);
        layout->addWidget(carburante_label,1,2);
        layout->addWidget(carburante,1,3);
        layout->addWidget(cavalli_label,2,0);
        layout->addWidget(cavalli,2,1);
        layout->addWidget(Nruote_label,2,2);
        layout->addWidget(Nruote,2,3);
        layout->addWidget(cilindrata_label,3,0);
        layout->addWidget(cilindrata,3,1);
        layout->addWidget(posti_label,3,2);
        layout->addWidget(posti,3,3);
        layout->addWidget(consumoMedio_label,4,0);
        layout->addWidget(consumoMedio, 4, 1);
        layout->addWidget(norma_antinquinamento_label,4,2);
        layout->addWidget(norma_antinquinamento,4,3);
        layout->addWidget(cambio_label,5,0);
        layout->addWidget(cambio,5,1);
        layout->addWidget(inizioproduzione_label,6,0);
        layout->addWidget(inizioproduzione_date,6,1);
        layout->addWidget(fineproduzione_label,6,2);
        layout->addWidget(fineproduzione_date,6,3);

        setLayout(layout);
        show();
}

void showVehicle_window::addCarAttributes(){
    const automobile* car=dynamic_cast<const automobile*>(vehicle);
    QLabel* carrozzeria_label=new QLabel;
        carrozzeria_label->setText("tipo carrozzeria");
    QLabel* carrozzeria=new QLabel;
        carrozzeria->setText(QString::fromStdString(car->getcarrozzeria()));
    QLabel* PosizioneMotore_label=new QLabel;
        PosizioneMotore_label->setText("posizione motore");
    QLabel* PosizioneMotore=new QLabel;
        PosizioneMotore->setText(QString::fromStdString(car->getPosizioneMotore()));
    QLabel* allestimento_label=new QLabel;
        allestimento_label->setText("allestimento");
    QLabel* allestimento=new QLabel;
        allestimento->setText(QString::fromStdString(car->getallestimento()));

    layout->addWidget(carrozzeria_label,8,0);
    layout->addWidget(carrozzeria,8,1);
    layout->addWidget(PosizioneMotore_label,8,2);
    layout->addWidget(PosizioneMotore,8,3);
    layout->addWidget(allestimento_label,9,0);
    layout->addWidget(allestimento,9,1);
}

void showVehicle_window::addCamionAttributes(){
    const autocarro* camion=dynamic_cast<const autocarro*> (vehicle);
    QLabel* cabina_label=new QLabel;
        cabina_label->setText("tipo cabina:");
    QLabel* cabina=new QLabel;
        cabina->setText(QString::fromStdString(camion->getCabina()));
    QLabel* costochilometrico_label=new QLabel;
        costochilometrico_label->setText("costo chilometrico:");
    QLabel* costochilometrico=new QLabel;
        costochilometrico->setText(QString::fromStdString(std::to_string(camion->getcostochilometrico())));
    QLabel* portata_label=new QLabel;
        portata_label->setText("portata massima:");
    QLabel* portata=new QLabel;
        portata->setText(QString::fromStdString(std::to_string(camion->getportata())));
    QLabel* assi_label=new QLabel;
        assi_label->setText("numero assi:");
    QLabel* assi=new QLabel;
        assi->setText(QString::fromStdString(std::to_string(camion->getassi())));
    layout->addWidget(cabina_label,8,0);
    layout->addWidget(cabina, 8, 1);
    layout->addWidget(costochilometrico_label,8,2);
    layout->addWidget(costochilometrico,8,3);
    layout->addWidget(portata_label,9,0);
    layout->addWidget(portata,9,1);
    layout->addWidget(assi_label,9,2);
    layout->addWidget(assi,9,3);
}

void showVehicle_window::addMotorbikeAttributes(){
    const motociclo* moto=dynamic_cast<const motociclo*>(vehicle);
    QLabel* tipologia_label=new QLabel;
        tipologia_label->setText("tipologia telaio:");
    QLabel* tipologia=new QLabel;
        tipologia->setText(QString::fromStdString(moto->gettipologia()));
    QLabel* patentenecessaria_label=new QLabel;
        patentenecessaria_label->setText("patente necessaria:");
    QLabel* patentenecessaria=new QLabel;
        patentenecessaria->setText(QString::fromStdString(moto->getpatentenecessaria()));

    layout->addWidget(tipologia_label,8,0);
    layout->addWidget(tipologia,8,1);
    layout->addWidget(patentenecessaria_label,8,2);
    layout->addWidget(patentenecessaria,8,3);

}

showVehicle_window::~showVehicle_window(){
    delete vehicle;
}
