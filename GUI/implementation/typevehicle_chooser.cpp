#include "GUI/header/typevehicle_chooser.h"

typevehicle_chooser::typevehicle_chooser(QWidget* parent): QDialog(parent){
    layout=new QGridLayout;
    setWindowTitle("scelta veicolo");
    car=new QPushButton;
        car->setText("Automobile");
        connect(car, SIGNAL(clicked(bool)), parent, SLOT(openCarAdder()));
        connect(car, SIGNAL(clicked(bool)), this, SLOT(close()));
    camion=new QPushButton;
        camion->setText("Autocarro");
        connect(camion, SIGNAL(clicked(bool)), parent, SLOT(openCamionAdder()));
        connect(camion, SIGNAL(clicked(bool)), this, SLOT(close()));
    motorbike=new QPushButton;
        motorbike->setText("Motociclo");
        connect(motorbike, SIGNAL(clicked(bool)), parent, SLOT(openMotorbikeAdder()));
        connect(motorbike, SIGNAL(clicked(bool)), this, SLOT(close()));
    description=new QLabel;
        description->setText("scegliere tipo di veicolo da aggiungere");

    layout->addWidget(description,0,0);
    layout->addWidget(car,1,1,2,2);
    layout->addWidget(camion,1,3,2,2);
    layout->addWidget(motorbike,1,5,2,2);

    setLayout(layout);
    show();
}
