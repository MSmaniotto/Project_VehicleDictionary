#ifndef VEICOLO_AUTOMOBILE_H
#define VEICOLO_AUTOMOBILE_H

#include "MODEL/header/veicolo.h"



class automobile: public Veicolo{   //sottoclasse automobile con derivazione pubblica da veicolo
private:
    std::string Carrozzeria;
    std::string PosizioneMotore;
    std::string allestimento;
public:
    automobile(std::string, std::string,unsigned int, unsigned int, unsigned int, std::string, std::string, unsigned short int, double,
               std::string, std::string, QDate, QDate, std::string, std::string, std::string);
    automobile(){}
    static Veicolo* importAuto(QXmlStreamReader&);
    std::string getcarrozzeria() const;
    std::string getPosizioneMotore() const;
    std::string getallestimento() const;

    void setcarrozzeria(std::string);
    void setPosizioneMotore(std::string);
    void setallestimento(std::string);

    virtual bool operator ==(const Veicolo&) const;
    virtual automobile* clone()const;

    void Ownexporter(QXmlStreamWriter&)const;
};


#endif // VEICOLO_AUTOMOBILE_H
