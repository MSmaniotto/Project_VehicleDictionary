#ifndef VEICOLO_MOTOCICLO_H
#define VEICOLO_MOTOCICLO_H

#include "MODEL/header/veicolo.h"



class motociclo:public Veicolo{     //sottoclasse motociclo con derivazione pubblica da veicolo
private:
    std::string tipologia;
    std::string patentenecessaria;
public:
    motociclo(std::string, std::string,unsigned int, unsigned int, unsigned int, std::string, std::string, unsigned short int, double,
              std::string, std::string, QDate, QDate, std::string, std::string);
    motociclo(){}
    static Veicolo* importMoto(QXmlStreamReader&);
    std::string gettipologia() const;
    std::string getpatentenecessaria()const;

    void settipologia(std::string);
    void setpatentenecessaria(std::string);

    virtual bool operator==(const Veicolo&);
    virtual motociclo* clone()const;

    void Ownexporter(QXmlStreamWriter&)const;

};



#endif // VEICOLO_MOTOCICLO_H
