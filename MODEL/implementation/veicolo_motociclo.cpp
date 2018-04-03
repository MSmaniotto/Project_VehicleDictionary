#include "MODEL/header/veicolo_motociclo.h"


motociclo::motociclo(std::string marchio="ND", std::string nomeauto="ND", unsigned int cav=0, unsigned int ruote=2, unsigned int cm3=0,
                     std::string versioneauto="ND", std::string combustibile="benzina",unsigned short int passeggeri=1,
                     double consumo=0, std::string inquinamento=0, std::string Tcambio="manuale", QDate inizio=defaultData, QDate fine=defaultData, std::string tipo="ND",
                     std::string patente="ND"):Veicolo(marchio,nomeauto,cav, ruote,cm3,versioneauto,combustibile,passeggeri,consumo,inquinamento,Tcambio,inizio,fine), tipologia(tipo), patentenecessaria(patente){}

std::string motociclo::gettipologia()const{
    return tipologia;
}

std::string motociclo::getpatentenecessaria()const{
    return patentenecessaria;
}


bool motociclo::operator ==(const Veicolo& a){
    const motociclo* m=dynamic_cast<const motociclo*> (&a);
    if(m && Veicolo::operator ==(*m)){
        if(tipologia==m->tipologia && patentenecessaria==m->patentenecessaria)
            return true;
    }
    return false;
}

motociclo* motociclo::clone()const{
    return new motociclo(*this);
}

Veicolo* motociclo::importMoto(QXmlStreamReader& input){
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
    std::string tipologia;
    std::string patentenecessaria;

    Veicolo::importVeicolo(input, produttore, nomeCommerciale, cavalli, Nruote, cilindrata,
                  versione, carburante, posti, consumoMedio, norma_antinquinamento,
                  cambio, inizioproduzione, fineproduzione);

    QString t =import(input, "tipologia");
    QString p =import(input, "patentenecessaria");

    tipologia= t.toStdString();
    patentenecessaria= p.toStdString();

    return new motociclo(produttore, nomeCommerciale, cavalli, Nruote, cilindrata,
                          versione, carburante, posti, consumoMedio, norma_antinquinamento,
                          cambio, inizioproduzione, fineproduzione, tipologia, patentenecessaria);
}

void motociclo::Ownexporter(QXmlStreamWriter &out)const{
    out.writeStartElement("Motociclo");

    this->Veicolo::Ownexporter(out);

    out.writeTextElement("tipologia", QString::fromStdString(tipologia));
    out.writeTextElement("patentenecessaria", QString::fromStdString(patentenecessaria));
    out.writeEndElement();
}

void motociclo::settipologia(std::string type){
    if(type!=gettipologia())
        tipologia=type;
}

void motociclo::setpatentenecessaria(std::string pantente){
    if(patentenecessaria!=pantente)
        patentenecessaria=patentenecessaria;

}
