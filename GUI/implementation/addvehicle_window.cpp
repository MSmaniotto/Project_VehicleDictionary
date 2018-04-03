#include "GUI/header/addvehicle_window.h"


void addvehicle_window::addbuttons(std::string& tipologia){
    setWindowTitle("pannello aggiunta veicolo");
    QMenu* Nruote_choose=new QMenu;
    connect(Nruote_choose, SIGNAL(triggered(QAction*)),Nruote_edit, SLOT(setAction(QAction*)));
    QMenu* carburante_choose=new QMenu;
    connect(carburante_choose, SIGNAL(triggered(QAction*)), carburante_edit, SLOT(setAction(QAction*)));
    QMenu* posti_choose=new QMenu;
    connect(posti_choose, SIGNAL(triggered(QAction*)), posti_edit, SLOT(setAction(QAction*)));    
    QMenu* cambio_choose=new QMenu;
    connect(cambio_choose, SIGNAL(triggered(QAction*)), cambio_edit, SLOT(setAction(QAction*)));

    if(tipologia=="Automobile"){
        Nruote_choose->addAction("3");
        Nruote_choose->addAction("4");
        Nruote_choose->addAction("6");
        Nruote_edit->setMenu(Nruote_choose);

        carburante_choose->addAction("benzina");
        carburante_choose->addAction("diesel");
        carburante_choose->addAction("ibrida");
        carburante_choose->addAction("elettrica");
        carburante_choose->addAction("metano");
        carburante_choose->addAction("GPL");
        carburante_edit->setMenu(carburante_choose);


        posti_choose->addAction("1");
        posti_choose->addAction("2");
        posti_choose->addAction("3");
        posti_choose->addAction("4");
        posti_choose->addAction("5");
        posti_choose->addAction("7");
        posti_choose->addAction("9");
        posti_edit->setMenu(posti_choose);

        norma_antinquinamento_choose->addAction("euro 5");
        norma_antinquinamento_choose->addAction("euro 6");

        cambio_choose->addAction("manuale");
        cambio_choose->addAction("automatico");
        cambio_choose->addAction("sequenziale");
        cambio_choose->addAction("innesti frontali");
        cambio_choose->addAction("monomarcia");
        cambio_edit->setMenu(cambio_choose);


        QLabel* carrozzeria=new QLabel;
            carrozzeria->setText("* carrozzeria:");
        option1=new myButton;
            QMenu* carrozzeria_choose=new QMenu;
            carrozzeria_choose->addAction("berlina");
            carrozzeria_choose->addAction("station wagon");
            carrozzeria_choose->addAction("citycar");
            carrozzeria_choose->addAction("sportiva");
            carrozzeria_choose->addAction("suv");
            carrozzeria_choose->addAction("cabrio");
            carrozzeria_choose->addAction("altro");
            option1->setMenu(carrozzeria_choose);
            connect(carrozzeria_choose, SIGNAL(triggered(QAction*)), option1, SLOT(setAction(QAction*)));

        QLabel* posizionemotore=new QLabel;
            posizionemotore->setText("* posizione motore:");
        option2=new myButton;
            QMenu* motore_choose=new QMenu;
            motore_choose->addAction("anteriore");
            motore_choose->addAction("centrale");
            motore_choose->addAction("posteriore");
            option2->setMenu(motore_choose);
            connect(motore_choose, SIGNAL(triggered(QAction*)), option2, SLOT(setAction(QAction*)));

        QLabel* allestimento=new QLabel;
            allestimento->setText("allestimento:");
        option3=new QLineEdit;

        layout->addWidget(carrozzeria, 15, 0);
        layout->addWidget(option1, 15, 1);
        layout->addWidget(posizionemotore, 16, 0);
        layout->addWidget(option2, 16, 1);
        layout->addWidget(allestimento, 17, 0);
        layout->addWidget(option3, 17, 1);
    }

    if(tipologia=="Autocarro"){
        Nruote_choose->addAction("4");
        Nruote_choose->addAction("6");
        Nruote_edit->setMenu(Nruote_choose);

        carburante_choose->addAction("diesel");
        carburante_choose->addAction("elettrico");
        carburante_edit->setMenu(carburante_choose);

        posti_choose->addAction("2");
        posti_choose->addAction("3");
        posti_edit->setMenu(posti_choose);


        norma_antinquinamento_choose->addAction("euro 5");
        norma_antinquinamento_choose->addAction("euro 6");

        cambio_choose->addAction("manuale");
        cambio_choose->addAction("automatico");
        cambio_edit->setMenu(cambio_choose);

        QLabel* cabina=new QLabel;
            cabina->setText("* cabina:");
        option1=new myButton;
            QMenu* cabina_choose=new QMenu;
            cabina_choose->addAction("furgonata");
            cabina_choose->addAction("singola");
            cabina_choose->addAction("doppia");
            cabina_choose->addAction("XL");
            option1->setMenu(cabina_choose);
            connect(cabina_choose, SIGNAL(triggered(QAction*)), option1, SLOT(setAction(QAction*)));

        QLabel* costochilometrico=new QLabel;
            costochilometrico->setText("costo chilometrico:");
        option3=new QLineEdit;
        QLabel* portata=new QLabel;
            portata->setText("portata:");
        option4=new QLineEdit;
        QLabel* assi=new QLabel;
            assi->setText("* assi:");
        option2=new myButton;
            QMenu* assi_choose=new QMenu;
            assi_choose->addAction("4");
            assi_choose->addAction("6");
            option2->setMenu(assi_choose);
            connect(assi_choose, SIGNAL(triggered(QAction*)), option2, SLOT(setAction(QAction*)));

        layout->addWidget(cabina, 15, 0);
        layout->addWidget(option1, 15, 1);
        layout->addWidget(costochilometrico, 16, 0);
        layout->addWidget(option3, 16, 1);
        layout->addWidget(portata, 17, 0);
        layout->addWidget(option4, 17, 1);
        layout->addWidget(assi, 18, 0);
        layout->addWidget(option2, 18, 1);
    }
    if(tipologia=="Motociclo"){
        Nruote_choose->addAction("2");
        Nruote_choose->addAction("3");
        Nruote_choose->addAction("4");
        Nruote_edit->setMenu(Nruote_choose);

        carburante_choose->addAction("benzina");
        carburante_choose->addAction("diesel");
        carburante_choose->addAction("elettrica");
        carburante_edit->setMenu(carburante_choose);


        posti_choose->addAction("1");
        posti_choose->addAction("2");
        posti_edit->setMenu(posti_choose);

        //norma_antinquinamento_choose->addAction("euro 5");    //da aggiungere quando disponibili anche per le moto
        //norma_antinquinamento_choose->addAction("euro 6");


        cambio_choose->addAction("automatico");
        cambio_choose->addAction("manuale");
        cambio_choose->addAction("semiautomatico");
        cambio_choose->addAction("monomarcia");
        cambio_edit->setMenu(cambio_choose);

        QLabel* tipologiamoto=new QLabel;
            tipologiamoto->setText("* tipologia:");
        option1=new myButton;
            QMenu* tipologia_choose=new QMenu;
            tipologia_choose->addAction("scooter");
            tipologia_choose->addAction("sportiva");
            tipologia_choose->addAction("chopper");
            tipologia_choose->addAction("motocross");
            tipologia_choose->addAction("naked");
            tipologia_choose->addAction("adventure");
            tipologia_choose->addAction("quad");
            tipologia_choose->addAction("motoslitta");
            tipologia_choose->addAction("altro");
            option1->setMenu(tipologia_choose);
            connect(tipologia_choose, SIGNAL(triggered(QAction*)), option1, SLOT(setAction(QAction*)));

        QLabel* patentenecessaria=new QLabel;
            patentenecessaria->setText("* patente necessaria:");
        option2=new myButton;
            QMenu* patenti=new QMenu;
            patenti->addAction("A1");
            patenti->addAction("A2");
            patenti->addAction("A3");
            option2->setMenu(patenti);
            connect(patenti, SIGNAL(triggered(QAction*)), option2, SLOT(setAction(QAction*)));

        layout->addWidget(tipologiamoto, 15, 0);
        layout->addWidget(option1, 15, 1);
        layout->addWidget(patentenecessaria, 16, 0);
        layout->addWidget(option2, 16, 1);

    }
}

addvehicle_window::addvehicle_window(std::string& tipologia, QWidget* parent, Vehicle_list& list):QDialog(parent), typeofvehicle(tipologia), vehicles(list){

    layout=new QGridLayout;
    descriptor=new QLabel;
        descriptor->setText("inserire i dati del veicolo (i campi * sono obbligatori");
    marchio=new QLabel;
        marchio->setText("* marchio:");
    nome=new QLabel;
        nome->setText("* nome:");
    cavalli=new QLabel;
        cavalli->setText("cavalli:");
    Nruote=new QLabel;
        Nruote->setText("numero ruote:");
    cilindrata=new QLabel;
        cilindrata->setText("cilindrata:");
    versione=new QLabel;
        versione->setText("versione:");
    carburante=new QLabel;
        carburante->setText("* carburante:");
    posti=new QLabel;
        posti->setText("posti:");
    consumoMedio=new QLabel;
        consumoMedio->setText("consumo medio:");
    norma_antinquinamento=new QLabel;
        norma_antinquinamento->setText("norma antinquinamento:");
    cambio=new QLabel;
        cambio->setText("cambio:");
    inizioproduzione=new QLabel;
        inizioproduzione->setText("inizio produzione (dd/mm/yyyy):");
    fineproduzione=new QLabel;
        fineproduzione->setText("fine produzione (dd/mm/yyyy):");
    marchio_edit=new QLineEdit;
    nome_edit=new QLineEdit;

    cavalli_edit=new QLineEdit;
    Nruote_edit=new myButton;
    cilindrata_edit=new QLineEdit;
    versione_edit=new QLineEdit;
    carburante_edit=new myButton;
    posti_edit=new myButton;
    consumoMedio_edit=new QLineEdit;
    norma_antinquinamento_edit=new myButton;
    cambio_edit=new myButton;
    inizioproduzione_editday=new QLineEdit;
    inizioproduzione_editmonth=new QLineEdit;
    inizioproduzione_edityear=new QLineEdit;
    fineproduzione_editday=new QLineEdit;
    fineproduzione_editmonth=new QLineEdit;
    fineproduzione_edityear=new QLineEdit;

    norma_antinquinamento_choose=new QMenu;
    connect(norma_antinquinamento_choose, SIGNAL(triggered(QAction*)), norma_antinquinamento_edit, SLOT(setAction(QAction*)));

    norma_antinquinamento_choose->addAction("euro 0");
    norma_antinquinamento_choose->addAction("euro 1");
    norma_antinquinamento_choose->addAction("euro 2");
    norma_antinquinamento_choose->addAction("euro 3");
    norma_antinquinamento_choose->addAction("euro 4");
    norma_antinquinamento_edit->setMenu(norma_antinquinamento_choose);

    add=new QPushButton;
        add->setText("aggiungi");
        connect(add, SIGNAL(clicked(bool)), this, SLOT(addvehicle()));


    layout->addWidget(descriptor, 1, 0);
    layout->addWidget(marchio, 2, 0);
    layout->addWidget(marchio_edit, 2, 1);
    layout->addWidget(nome, 3, 0);
    layout->addWidget(nome_edit, 3, 1);
    layout->addWidget(cavalli, 4, 0);
    layout->addWidget(cavalli_edit, 4, 1);
    layout->addWidget(Nruote, 5, 0);
    layout->addWidget(Nruote_edit, 5, 1);
    layout->addWidget(cilindrata, 6, 0);
    layout->addWidget(cilindrata_edit, 6, 1);
    layout->addWidget(versione, 7, 0);
    layout->addWidget(versione_edit, 7, 1);
    layout->addWidget(carburante, 8, 0);
    layout->addWidget(carburante_edit, 8, 1);
    layout->addWidget(posti, 9, 0);
    layout->addWidget(posti_edit, 9, 1);
    layout->addWidget(consumoMedio, 10, 0);
    layout->addWidget(consumoMedio_edit, 10, 1);
    layout->addWidget(norma_antinquinamento, 11, 0);
    layout->addWidget(norma_antinquinamento_edit, 11, 1);
    layout->addWidget(cambio, 12, 0);
    layout->addWidget(cambio_edit, 12, 1);
    layout->addWidget(inizioproduzione, 13, 0);
    layout->addWidget(inizioproduzione_editday, 13, 1);
    layout->addWidget(inizioproduzione_editmonth, 13, 2);
    layout->addWidget(inizioproduzione_edityear, 13, 3);
    layout->addWidget(fineproduzione, 14, 0);
    layout->addWidget(fineproduzione_editday, 14, 1);
    layout->addWidget(fineproduzione_editmonth, 14, 2);
    layout->addWidget(fineproduzione_edityear, 14, 3);
    addbuttons(typeofvehicle);
    layout->addWidget(add, 20, 0);

    setLayout(layout);
}

void addvehicle_window::addvehicle(){
    if(marchio_edit->text().isEmpty() || nome_edit->text().isEmpty() || carburante_edit->text().isEmpty()){
        QMessageBox* message=new QMessageBox;
        message->setText("impossibile completare l'azione: non tutti i campi * sono stati riempiti");
        message->setWindowTitle("ERRORE!");
        message->exec();
        return;
    }

    int days=31; int months=12; int years=QDate::currentDate().year()+1;
    if((inizioproduzione_editday->text().toInt())>(days)||(inizioproduzione_editmonth->text().toInt())>(months)||(inizioproduzione_edityear->text().toInt())>=(years)){
        QMessageBox* wrongdate=new QMessageBox;
        wrongdate->setText("attenzione: la data di inizio produzione non è valida (non si accettano date oltre il prossimo anno)");
        wrongdate->setText("ATTENZIONE!");
        wrongdate->exec();
        return;
    }

    QDate* startdate=new QDate(inizioproduzione_edityear->text().toInt(), inizioproduzione_editmonth->text().toInt(), inizioproduzione_editday->text().toInt());

    QDate* enddate=new QDate(fineproduzione_edityear->text().toInt(), fineproduzione_editmonth->text().toInt(), fineproduzione_editday->text().toInt());

    if(fineproduzione_editday->text().toInt()>31 || fineproduzione_editmonth->text().toInt()>12 || *enddate>QDate::currentDate()){
        QMessageBox* wrongdate=new QMessageBox;
        wrongdate->setText("attenzione: la data di fine produzione non è valida (non si accettano date oltre il giorno corrente)");
        wrongdate->setWindowTitle("ATTENZIONE!");
        wrongdate->exec();
        return;
    }

    if(!consumoMedio_edit->text().isEmpty()){
        double a=0;
        if(consumoMedio_edit->text().toDouble()==a && consumoMedio_edit->text().toStdString()!="0" && consumoMedio_edit->text().toStdString()!="0,0" && consumoMedio_edit->text().toStdString()!="00,0" && consumoMedio_edit->text().toStdString()!="0,00"&& consumoMedio_edit->text().toStdString()!="00,00"){
            QMessageBox* wrongvalue=new QMessageBox;
            wrongvalue->setText("errore: il valore del consumo medio va scritto nella forma xxxxx.xxxx");
            wrongvalue->setWindowTitle("ERRORE");
            wrongvalue->exec();
            return;
        }
    }

    if(typeofvehicle=="Automobile"){
        if(option1->text().isEmpty() || option2->text().isEmpty()){
            QMessageBox* error=new QMessageBox;
            error->setText("errore: devono essere inseriti i campi carrozzeria e posizione motore");
            error->setWindowTitle("ERRORE");
            error->exec();
            return;
        }

        automobile* car=new automobile(marchio_edit->text().toStdString(),nome_edit->text().toStdString(), cavalli_edit->text().toInt(), Nruote_edit->text().toInt(), cilindrata_edit->text().toDouble(), versione_edit->text().toStdString(), carburante_edit->text().toStdString(), posti_edit->text().toInt(), consumoMedio_edit->text().toDouble(), norma_antinquinamento_edit->text().toStdString(), cambio_edit->text().toStdString(), *startdate, *enddate, option1->text().toStdString(), option2->text().toStdString(), option3->text().toStdString());
        vehicles.insertVehicle(car);
    }
    if(typeofvehicle=="Autocarro"){
        if(option1->text().isEmpty() || option2->text().isEmpty()){
            QMessageBox* error=new QMessageBox;
            error->setText("errore: devono essere inseriti il tipo di cabina e il numero di assi");
            error->setWindowTitle("ERRORE");
            error->exec();
            return;
        }
        if(!option3->text().isEmpty()){
            double a=0;
            if(option3->text().toDouble()==a && option3->text().toStdString()!="0" && option3->text().toStdString()!="0,0" && option3->text().toStdString()!="00,0" && option3->text().toStdString()!="0,00"&& option3->text().toStdString()!="00,00"){
                QMessageBox* wrongvalue=new QMessageBox;
                wrongvalue->setText("errore: il valore del costo chilometrico va scritto nella forma xxxxx.xxxx");
                wrongvalue->setWindowTitle("ERRORE");
                wrongvalue->exec();
                return;
            }
        }

        if(!option4->text().isEmpty()){
            double a=0;
            if(option4->text().toDouble()==a && option4->text().toStdString()!="0" && option4->text().toStdString()!="0,0" && option4->text().toStdString()!="00,0" && option4->text().toStdString()!="0,00"&& option4->text().toStdString()!="00,00"){
                QMessageBox* wrongvalue=new QMessageBox;
                wrongvalue->setText("errore: il valore della portata massima va scritto nella forma xxxxx.xxxx");
                wrongvalue->setWindowTitle("ERRORE");
                wrongvalue->exec();
                return;
            }
        }
        autocarro* camion=new autocarro(marchio_edit->text().toStdString(),nome_edit->text().toStdString(), cavalli_edit->text().toInt(), Nruote_edit->text().toInt(), cilindrata_edit->text().toDouble(), versione_edit->text().toStdString(), carburante_edit->text().toStdString(), posti_edit->text().toInt(), consumoMedio_edit->text().toDouble(), norma_antinquinamento_edit->text().toStdString(), cambio_edit->text().toStdString(), *startdate, *enddate, option1->text().toStdString(), option3->text().toDouble(), option4->text().toDouble(), option2->text().toInt());
        vehicles.insertVehicle(camion);
    }
    if(typeofvehicle=="Motociclo"){
        if(option1->text().isEmpty() || option2->text().isEmpty()){
            QMessageBox* error=new QMessageBox;
            error->setText("errore: devono essere scelti i campi patente necessaria e tipologia");
            error->setWindowTitle("ERRORE");
            error->exec();
            return;
        }
        motociclo* motorbike=new motociclo(marchio_edit->text().toStdString(),nome_edit->text().toStdString(), cavalli_edit->text().toInt(), Nruote_edit->text().toInt(), cilindrata_edit->text().toDouble(), versione_edit->text().toStdString(), carburante_edit->text().toStdString(), posti_edit->text().toInt(), consumoMedio_edit->text().toDouble(), norma_antinquinamento_edit->text().toStdString(), cambio_edit->text().toStdString(), *startdate, *enddate, option1->text().toStdString(), option2->text().toStdString());
        vehicles.insertVehicle(motorbike);
    }
    vehicles.XmlExporter();
    close();
}
