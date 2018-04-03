#include "MODEL/header/veicolo_autocarro.h"

autocarro::autocarro(std::string marchio="ND", std::string nomeauto="ND", unsigned int cav=0, unsigned int ruote=4, unsigned int cm3=0,
                     std::string versioneauto="ND", std::string combustibile="diesel",unsigned short int passeggeri=1,
                     double consumo=0, std::string inquinamento="euro 0", std::string Tcambio="manuale", QDate inizio=defaultData, QDate fine=defaultData,std::string cab="ND", double costo=0, double massatrasp=0,
                     unsigned int assiC=2):Veicolo(marchio,nomeauto,cav, ruote,cm3,versioneauto,combustibile,passeggeri,consumo,inquinamento,Tcambio,inizio,fine),
                     Cabina(cab), costochilometrico(costo), portata(massatrasp), assi(assiC){}
std::string autocarro::getCabina()const{
    return Cabina;
}

double autocarro::getcostochilometrico()const{
    return costochilometrico;
}

double autocarro::getportata()const{
    return portata;
}

unsigned int autocarro::getassi() const{
    return assi;
}

bool autocarro::operator ==(const Veicolo& a)const{
    const autocarro* au=dynamic_cast<const autocarro*> (&a);
    if(au && Veicolo::operator ==(*au)){
        if(Cabina==au->Cabina && costochilometrico==au->costochilometrico && portata==au->portata && assi==au->assi)
            return true;
    }
    return false;
}

autocarro* autocarro::clone()const{
    return new autocarro(*this);
}

Veicolo* autocarro::importCamion(QXmlStreamReader& input){
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
    std::string Cabina;
    double costochilometrico;
    double portata;
    unsigned int assi;

    Veicolo::importVeicolo(input, produttore, nomeCommerciale, cavalli, Nruote, cilindrata,
                  versione, carburante, posti, consumoMedio, norma_antinquinamento,
                  cambio, inizioproduzione, fineproduzione);

    QString c =import(input, "Cabina");
    QString co =import(input, "costochilometrico");
    QString p =import(input, "portata");
    QString a =import(input, "assi");

    Cabina= c.toStdString();
    costochilometrico= co.toDouble();
    portata= p.toDouble();
    assi= a.toInt();

    return new autocarro(produttore, nomeCommerciale, cavalli, Nruote, cilindrata,
                          versione, carburante, posti, consumoMedio, norma_antinquinamento,
                          cambio, inizioproduzione, fineproduzione, Cabina, costochilometrico, portata, assi);
}

void autocarro::Ownexporter(QXmlStreamWriter &out)const{
    out.writeStartElement("Autocarro");

    this->Veicolo::Ownexporter(out);

    out.writeTextElement("Cabina", QString::fromStdString(Cabina));
    out.writeTextElement("costochilometrico", QString::fromStdString(std::to_string(costochilometrico)));
    out.writeTextElement("portata", QString::fromStdString(std::to_string(portata)));
    out.writeTextElement("assi", QString::fromStdString(std::to_string(assi)));
    out.writeEndElement();
}

void autocarro::setCabina(std::string str){
    if(Cabina!=str)
        Cabina=str;
}

void autocarro::setcostochilometrico(double nuovo){
    if(costochilometrico!=nuovo)
        costochilometrico=nuovo;
}

void autocarro::setportata(double nuova){
    if(portata!=nuova)
        portata=nuova;
}

void autocarro::setassi(int nuovi){
    if(assi!=nuovi)
        assi=nuovi;
}
