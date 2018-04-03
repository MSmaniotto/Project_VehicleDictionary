#ifndef ADDVEHICLE_WINDOW_H
#define ADDVEHICLE_WINDOW_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QDate>
#include <QMessageBox>
#include "MODEL/header/vehicle_list.h"
#include "GUI/header/mybutton.h"

class addvehicle_window:public QDialog
{
    Q_OBJECT
private:
    std::string typeofvehicle;
    Vehicle_list& vehicles;
    QGridLayout* layout;
    QLabel* descriptor;
    QLabel* marchio;
    QLabel* nome;
    QLabel* cavalli;
    QLabel* Nruote;
    QLabel* cilindrata;
    QLabel* versione;
    QLabel* carburante;
    QLabel* posti;
    QLabel* consumoMedio;
    QLabel* norma_antinquinamento;
    QLabel* cambio;
    QLabel* inizioproduzione;
    QLabel* fineproduzione;
    QLineEdit* marchio_edit;
    QLineEdit* nome_edit;
    QLineEdit* cavalli_edit;
    myButton* Nruote_edit;
    QLineEdit* cilindrata_edit;
    QLineEdit* versione_edit;
    myButton* carburante_edit;
    myButton* posti_edit;
    QLineEdit* consumoMedio_edit;
    myButton* norma_antinquinamento_edit;
    QMenu* norma_antinquinamento_choose;
    myButton* cambio_edit;
    QLineEdit* inizioproduzione_editday;
    QLineEdit* inizioproduzione_editmonth;
    QLineEdit* inizioproduzione_edityear;
    QLineEdit* fineproduzione_editday;
    QLineEdit* fineproduzione_editmonth;
    QLineEdit* fineproduzione_edityear;

    QPushButton* add;

    myButton* option1;
    myButton* option2;
    QLineEdit* option3;
    QLineEdit* option4;

    //widget opzionali per l'aggiunta di caratteristiche specifiche del veicolo
    //nel caso si dovessero aggiungere ulteriori widget conviene controllare la posizione nel layout del pulsante add

    void caritems();
    void camionitems();
    void motorbikeitems();
    void createwindow();

public:
    addvehicle_window(std::string&, QWidget*, Vehicle_list&);
public slots:
    void addbuttons(std::string& tipologia);
    void addvehicle();
};

#endif // ADDVEHICLE_WINDOW_H
