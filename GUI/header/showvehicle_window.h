#ifndef SHOWVEHICLE_WINDOW_H
#define SHOWVEHICLE_WINDOW_H
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include "MODEL/header/veicolo_autocarro.h"
#include "MODEL/header/veicolo_automobile.h"
#include "MODEL/header/veicolo_motociclo.h"



class showVehicle_window:public QDialog
{
private:
    const Veicolo* vehicle;
    QGridLayout* layout;
    QLabel* produttore;
        QLabel* produttore_label;
    QLabel* nomeCommerciale;
        QLabel* nomeCommerciale_label;
    QLabel* versione;
        QLabel* versione_label;
    QLabel* carburante;
        QLabel* carburante_label;
    QLabel* cavalli;
        QLabel* cavalli_label;
    QLabel* Nruote;
        QLabel* Nruote_label;
    QLabel* cilindrata;
        QLabel* cilindrata_label;
    QLabel* posti;
        QLabel* posti_label;
    QLabel* consumoMedio;
        QLabel* consumoMedio_label;
    QLabel* norma_antinquinamento;
        QLabel* norma_antinquinamento_label;
    QLabel* cambio;
        QLabel* cambio_label;
    QLabel* inizioproduzione_date;
        QLabel* inizioproduzione_label;
    QLabel* fineproduzione_date;
        QLabel* fineproduzione_label;
    void addCarAttributes();
    void addCamionAttributes();
    void addMotorbikeAttributes();
public:
    showVehicle_window(const Veicolo*);
    ~showVehicle_window();
};

#endif // SHOWVEHICLE_WINDOW_H
