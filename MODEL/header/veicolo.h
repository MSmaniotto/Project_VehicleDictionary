#ifndef VEICOLO_H
#define VEICOLO_H
#include <QDate>
#include <QString>
#include <QXmlStreamWriter>
#include <typeinfo>
#include "MODEL/header/importer.h"


class Veicolo   //classe generica veicolo
{
private:
    unsigned int cavalli;
    unsigned int Nruote;
    unsigned int cilindrata;
    std::string produttore;
    std::string nomeCommerciale;
    std::string versione;
    std::string carburante;
    unsigned short int posti;
    double consumoMedio;
    std::string norma_antinquinamento;
    std::string cambio;
    QDate inizioproduzione;
    QDate fineproduzione;

protected:
    static QDate defaultData;
public:

    static void importVeicolo(QXmlStreamReader&, std::string&, std::string&, unsigned int&, unsigned int&, unsigned int&, std::string&, std::string&, unsigned short int&,
                              double&, std::string&, std::string&, QDate&, QDate&);

    Veicolo(std::string, std::string, unsigned int, unsigned int, unsigned int, std::string, std::string,  unsigned short int,
            double, std::string, std::string, QDate, QDate);
    Veicolo(){}
    int getPotenza() const;
    int getNumeroruote() const;
    int getCubatura() const;
    unsigned short int getpasseggeri()const;
    std::string getProduttore() const;
    std::string getNome() const;
    std::string getVersione()const;
    std::string getCarburante()const;
    double getConsumoMedio()const;
    std::string getNormaAntinquinamento()const;
    std::string getCambio()const;
    QDate getInizioProduzione()const;
    QDate getFineProduzione()const;

    void setCavalli(unsigned int);
    void setNruote(unsigned int);
    void setCilindrata(unsigned int);
    void setProduttore(std::string);
    void setNomeCommerciale(std::string);
    void setVersione(std::string);
    void setCarburante(std::string);
    void setPosti(unsigned short int);
    void setConsumoMedio(double);
    void setNorma_antinquinamento(std::string);
    void setCambio(std::string);
    void setInizioproduzione(QDate);
    void setFineproduzione(QDate);

    virtual bool operator==(const Veicolo&) const;
    virtual ~Veicolo(){}
    virtual Veicolo* clone()const;
    void virtual Ownexporter(QXmlStreamWriter&)const;

};



#endif // VEICOLO_H
