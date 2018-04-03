#ifndef VEICOLO_AUTOCARRO_H
#define VEICOLO_AUTOCARRO_H

#include "MODEL/header/veicolo.h"


class autocarro: public Veicolo{    //sottoclasse autocarro con derivazione pubblica da veicolo
private:
    std::string Cabina;
    double costochilometrico;
    double portata;
    int assi;
public:
    autocarro(std::string, std::string,unsigned int, unsigned int, unsigned int, std::string, std::string, unsigned short int, double,
              std::string, std::string, QDate, QDate, std::string, double,double, unsigned int);
    autocarro(){}
    static Veicolo* importCamion(QXmlStreamReader&);
    std::string getCabina()const;
    double getcostochilometrico()const;
    double getportata()const;
    unsigned int getassi()const;

    void setCabina(std::string);
    void setcostochilometrico(double);
    void setportata(double);
    void setassi(int);

    virtual bool operator==(const Veicolo&)const;
    virtual autocarro* clone()const;

    void Ownexporter(QXmlStreamWriter&)const;
};



#endif // VEICOLO_AUTOCARRO_H
