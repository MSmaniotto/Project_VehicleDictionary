#ifndef VEHICLE_LIST_H
#define VEHICLE_LIST_H
#include <QFile>
#include <list>
#include "MODEL/header/veicolo_autocarro.h"
#include "MODEL/header/veicolo_automobile.h"
#include "MODEL/header/veicolo_motociclo.h"

class Vehicle_list:public std::vector<const Veicolo*>
{
private:
    static QString StarterWord;
    static QString VehicleFile;

public:
    Vehicle_list();
    ~Vehicle_list();
    void insertVehicle(Veicolo*);

    std::vector<const Veicolo*> search(std::string, std::string);
    bool VehicleExists(const Veicolo*) const;
    bool XmlImporter();
    void deleteVehicle(Veicolo&);
    void XmlExporter() const;

};


#endif // VEHICLE_LIST_H
