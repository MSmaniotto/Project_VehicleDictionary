#include "MODEL/header/veicolo_automobile.h"

automobile::automobile(std::string marchio="ND", std::string nomeauto="ND", unsigned int cav=0, unsigned int ruote=4, unsigned int cm3=0,
                       std::string versioneauto="ND", std::string combustibile="benzina", unsigned short int passeggeri=1,
                       double consumo=0, std::string inquinamento="euro 0", std::string Tcambio="manuale", QDate inizio=defaultData, QDate fine=defaultData, std::string genere="ND", std::string posizioneM="ND",
                       std::string versione="standard"):Veicolo(marchio,nomeauto,cav, ruote,cm3,versioneauto,combustibile,passeggeri,consumo,inquinamento,Tcambio,inizio,fine),
                       Carrozzeria(genere), PosizioneMotore(posizioneM), allestimento(versione){}

std::string automobile::getcarrozzeria() const{
    return automobile::Carrozzeria;
}

std::string automobile::getPosizioneMotore()const{
    return automobile::PosizioneMotore;
}

std::string automobile::getallestimento()const{
    return automobile::allestimento;
}

bool automobile::operator ==(const Veicolo& a) const{
    const automobile* au=dynamic_cast<const automobile*> (&a);
    if(au && Veicolo::operator ==(*au)){
        if(Carrozzeria==au->Carrozzeria && PosizioneMotore==au->PosizioneMotore && allestimento==au->allestimento)
            return true;
    }
    return false;
}

automobile* automobile::clone()const{
    return new automobile(*this);
}

Veicolo* automobile::importAuto(QXmlStreamReader& input){
    std::string produttore;
    std::string nomeCommerciale;
    unsigned int cavalli;
    unsigned int Nruote;
    unsigned int cilindrata;
    std::string versione;
    std::string carburante;
    unsigned short int posti;
    double consumoMedio;
    std::string norma_antinquinamento;
    std::string cambio;
    QDate inizioproduzione;
    QDate fineproduzione;

    std::string Carrozzeria;
    std::string PosizioneMotore;
    std::string allestimento;

    Veicolo::importVeicolo(input, produttore, nomeCommerciale, cavalli, Nruote, cilindrata,
                  versione, carburante, posti, consumoMedio, norma_antinquinamento,
                  cambio, inizioproduzione, fineproduzione);

    QString c =import(input, "Carrozzeria");
    QString p =import(input, "PosizioneMotore");
    QString a =import(input, "allestimento");

    Carrozzeria= c.toStdString();
    PosizioneMotore= p.toStdString();
    allestimento= a.toStdString();

    return new automobile(produttore, nomeCommerciale, cavalli, Nruote, cilindrata,
                          versione, carburante, posti, consumoMedio, norma_antinquinamento,
                          cambio, inizioproduzione, fineproduzione, Carrozzeria,
                          PosizioneMotore, allestimento);

}

void automobile::Ownexporter(QXmlStreamWriter &out)const{
    out.writeStartElement("Automobile");

    this->Veicolo::Ownexporter(out);

    out.writeTextElement("Carrozzeria", QString::fromStdString(Carrozzeria));
    out.writeTextElement("PosizioneMotore", QString::fromStdString(PosizioneMotore));
    out.writeTextElement("allestimento", QString::fromStdString(allestimento));
    out.writeEndElement();
}

void automobile::setcarrozzeria(std::string nuova){
    if(Carrozzeria!=nuova)
        Carrozzeria=nuova;
}

void automobile::setPosizioneMotore(std::string nuovo){
    if(PosizioneMotore!=nuovo)
        PosizioneMotore=nuovo;
}

void automobile::setallestimento(std::string nuovo){
    if(allestimento!=nuovo)
        allestimento=nuovo;
}
