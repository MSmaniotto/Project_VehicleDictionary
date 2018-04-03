#ifndef MODIFYVEHICLE_WINDOW_H
#define MODIFYVEHICLE_WINDOW_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include "mybutton.h"
#include "MODEL/header/veicolo_autocarro.h"
#include "MODEL/header/veicolo_automobile.h"
#include "MODEL/header/veicolo_motociclo.h"

class modifyVehicle_window:public QDialog
{
    Q_OBJECT
private:
    Veicolo& vehicle;
    bool& change_done;
    QLabel* description;
    QPushButton* changer;

    QGridLayout* layout;
    QLineEdit* produttore;
        QLabel* produttore_label;
    QLineEdit* nomeCommerciale;
        QLabel* nomeCommerciale_label;
    QLineEdit* versione;
        QLabel* versione_label;
    myButton* carburante;
        QLabel* carburante_label;
    QLineEdit* cavalli;
        QLabel* cavalli_label;
    myButton* Nruote;
        QLabel* Nruote_label;
    QLineEdit* cilindrata;
        QLabel* cilindrata_label;
    myButton* posti;
        QLabel* posti_label;
    QLineEdit* consumoMedio;
        QLabel* consumoMedio_label;
    myButton* norma_antinquinamento;
        QLabel* norma_antinquinamento_label;
    myButton* cambio;
        QLabel* cambio_label;
    QLineEdit* inizioproduzione_day;
    QLineEdit* inizioproduzione_month;
    QLineEdit* inizioproduzione_year;
        QLabel* inizioproduzione_label;
    QLineEdit* fineproduzione_day;
    QLineEdit* fineproduzione_month;
    QLineEdit* fineproduzione_year;
        QLabel* fineproduzione_label;

    myButton* option1;
    QLabel* option1_label;
    myButton* option2;
    QLabel* option2_label;
    QLineEdit* option3;
    QLabel* option3_label;
    QLineEdit* option4;
    QLabel* option4_label;

    QMenu* Nruote_edit;
    QMenu* carburante_edit;
    QMenu* posti_edit;
    QMenu* norma_antinquinamento_edit;
    QMenu* cambio_edit;
    void insertcommonfeatures();

    void modifyproduttore();
    void modifynomecommerciale();
    void modifyversione();
    void modifycarburante();
    void modifycavalli();
    void modifyNruote();
    void modifycilindrata();
    void modifyposti();
    void modifyconsumoMedio();
    void modifynorma_antinquinamento();
    void modifycambio();
    void modifyinizioproduzione();
    void modifyfineproduzione();

public:
    modifyVehicle_window(Veicolo&, QWidget*, bool&);
public slots:
    void modify();
};
/*
class modifyCar_window:public modifyVehicle_window{
    Q_OBJECT
private:
    automobile& car;
    void modifycarrozzeria();
    void modifyposizionemotore();
    void modifyallestimento();
public:
    modifyCar_window(automobile&, QWidget*, bool&);
public slots:
    void modify();
};

class modifyCamion_window:public modifyVehicle_window{
    Q_OBJECT
private:
    autocarro& camion;
    void modifycabina();
    void modifycostochilometrico();
    void modifyportata();
    void modifyassi();
public:
    modifyCamion_window(autocarro&, QWidget*, bool&);

public slots:
    void modify();
};

class modifyMotorbike_window:public modifyVehicle_window{
    Q_OBJECT
private:
    motociclo& moto;
    void modifytipologia();
    void modifypatentenecessaria();
public:
    modifyMotorbike_window(motociclo&, QWidget*, bool&);
public slots:
    void modify();
};*/



#endif // MODIFYVEHICLE_WINDOW_H
