#include "MODEL/header/veicolo.h"

QDate Veicolo::defaultData=QDate::currentDate();
Veicolo::Veicolo(std::string marchio="ND", std::string nomeauto="ND", unsigned int cav=0, unsigned int ruote=1, unsigned int cm3=0,
                 std::string versioneauto="ND", std::string combustibile="benzina", unsigned short int passeggeri=1,
                 double consumo=0, std::string inquinamento="euro 0", std::string Tcambio="manuale", QDate inizio=defaultData, QDate fine=defaultData): cavalli(cav), Nruote(ruote),
                 cilindrata(cm3), produttore(marchio), nomeCommerciale(nomeauto),versione(versioneauto), carburante(combustibile),
                 posti(passeggeri), consumoMedio(consumo), norma_antinquinamento(inquinamento), cambio(Tcambio), inizioproduzione(inizio), fineproduzione(fine){}

int Veicolo::getPotenza() const{
    return Veicolo::cavalli;
}

int Veicolo::getNumeroruote() const{
    return Veicolo::Nruote;
}

int Veicolo::getCubatura() const{
    return Veicolo::cilindrata;
}

unsigned short int Veicolo::getpasseggeri()const{
    return posti;
}

std::string Veicolo::getProduttore()const{
    return produttore;
}

std::string Veicolo::getNome()const{
    return nomeCommerciale;
}

std::string Veicolo::getVersione()const{
    return versione;
}

std::string Veicolo::getCarburante()const{
    return carburante;
}

double Veicolo::getConsumoMedio()const{
    return consumoMedio;
}

std::string Veicolo::getNormaAntinquinamento()const{
    return norma_antinquinamento;
}

std::string Veicolo::getCambio()const{
    return cambio;
}

QDate Veicolo::getInizioProduzione()const{
    return inizioproduzione;
}

QDate Veicolo::getFineProduzione()const{
    return fineproduzione;
}

void Veicolo::setCambio(std::string c){
    if(cambio!=c)
        cambio=c;
}

void Veicolo::setCarburante(std::string c){
    if(carburante!=c)
        carburante=c;
}

void Veicolo::setCavalli(unsigned int c){
    if(cavalli!=c)
        cavalli=c;
}

void Veicolo::setCilindrata(unsigned int c){
    if(cilindrata!=c)
        cilindrata=c;
}

void Veicolo::setConsumoMedio(double c){
    if(consumoMedio!=c)
        consumoMedio=c;
}

void Veicolo::setFineproduzione(QDate f){
    if(fineproduzione!=f)
        fineproduzione=f;
}

void Veicolo::setInizioproduzione(QDate i){
    if(inizioproduzione!=i)
        inizioproduzione=i;
}

void Veicolo::setNomeCommerciale(std::string n){
    if(nomeCommerciale!=n)
        nomeCommerciale=n;
}

void Veicolo::setNorma_antinquinamento(std::string n){
    if(norma_antinquinamento!=n)
        norma_antinquinamento=n;
}

void Veicolo::setNruote(unsigned int n){
    if(Nruote!=n)
        Nruote=n;
}

void Veicolo::setPosti(unsigned short p){
    if(posti!=p)
        posti=p;
}

void Veicolo::setProduttore(std::string p){
    if(produttore!=p)
        produttore=p;
}

void Veicolo::setVersione(std::string v){
    if(versione!=v)
        versione=v;
}

bool Veicolo::operator ==(const Veicolo& v)const {
    return (produttore==v.produttore && nomeCommerciale==v.nomeCommerciale && versione==v.versione);
}

Veicolo* Veicolo::clone()const{
    return new Veicolo(*this);
}

void Veicolo::importVeicolo(QXmlStreamReader& input, std::string &produttore, std::string &nomeCommerciale, unsigned int &cavalli, unsigned int &Nruote, unsigned int &cilindrata,
                 std::string &versione, std::string &carburante, unsigned short int &posti,
                 double &consumoMedio, std::string &norma_antinquinamento, std::string &cambio, QDate &inizioproduzione, QDate &fineproduzione){

    QString pr =import(input, "produttore");
    QString nc =import(input, "nomeCommerciale");
    QString ca =import(input, "cavalli");
    QString nr =import(input, "Nruote");
    QString cil =import(input, "cilindrata");
    QString ver =import(input, "versione");
    QString carb =import(input, "carburante");
    QString ps =import(input, "posti");
    QString cons =import(input, "consumoMedio");
    QString na =import(input, "norma_antinquinamento");
    QString cam =import(input, "cambio");

    produttore= pr.toStdString();
    nomeCommerciale=nc.toStdString();
    cavalli=ca.toInt();
    Nruote= nr.toInt();
    cilindrata= cil.toInt();
    versione= ver.toStdString();
    carburante=carb.toStdString();
    posti=ps.toInt();
    consumoMedio=cons.toDouble();
    norma_antinquinamento=na.toStdString();
    cambio=cam.toStdString();

    importData(input, "inizioproduzione", inizioproduzione);
    importData(input, "fineproduzione", fineproduzione);
}

void Veicolo::Ownexporter(QXmlStreamWriter &out)const{


    out.writeTextElement("produttore", QString::fromStdString(produttore));
    out.writeTextElement("nomeCommerciale", QString::fromStdString(nomeCommerciale));
    out.writeTextElement("cavalli", QString::fromStdString(std::to_string(cavalli)));
    out.writeTextElement("Nruote", QString::fromStdString(std::to_string(Nruote)));
    out.writeTextElement("cilindrata", QString::fromStdString(std::to_string(cilindrata)));
    out.writeTextElement("versione", QString::fromStdString(versione));
    out.writeTextElement("carburante", QString::fromStdString(carburante));
    out.writeTextElement("posti", QString::fromStdString(std::to_string(posti)));
    out.writeTextElement("consumoMedio", QString::fromStdString(std::to_string(consumoMedio)));
    out.writeTextElement("norma_antinquinamento", QString::fromStdString(norma_antinquinamento));
    out.writeTextElement("cambio", QString::fromStdString(cambio));

    std::string days, months, years;
    days=std::to_string(inizioproduzione.day());
    months=std::to_string(inizioproduzione.month());
    years=std::to_string(inizioproduzione.year());

    out.writeStartElement("inizioproduzione");

    out.writeTextElement("days", QString::fromStdString(days));
    out.writeTextElement("months", QString::fromStdString(months));
    out.writeTextElement("years", QString::fromStdString(years));

    out.writeEndElement();

    days=std::to_string(fineproduzione.day());
    months=std::to_string(fineproduzione.month());
    years=std::to_string(fineproduzione.year());

    out.writeStartElement("fineproduzione");

    out.writeTextElement("days", QString::fromStdString(days));
    out.writeTextElement("months", QString::fromStdString(months));
    out.writeTextElement("years", QString::fromStdString(years));

    out.writeEndElement();
}
