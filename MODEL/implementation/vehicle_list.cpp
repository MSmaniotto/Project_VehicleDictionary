#include "MODEL/header/vehicle_list.h"

QString Vehicle_list::StarterWord="Veicoli";
QString Vehicle_list::VehicleFile="vehicle.xml";

std::vector<const Veicolo*> Vehicle_list::search(std::string brand, std::string name){
    std::vector<const Veicolo*> result;
    for(auto it=begin(); it!=end(); it++){
        if((*it)->getProduttore()==brand &&((*it)->getNome()==name))
            result.push_back(*it);
    }
    return result;
}

bool Vehicle_list::VehicleExists(const Veicolo* ve) const{
    for(auto it=begin(); it!=end(); it++){
        if((*ve)==*(*it)){
            return true;
        }
    }
    return false;
}

void Vehicle_list::insertVehicle(Veicolo * v){
    if(!VehicleExists(v))
        push_back(v->clone());
}

void Vehicle_list::deleteVehicle(Veicolo& thrash){
    for(auto it=begin(); it!=end(); it++){
        if(**it==thrash){
            it=erase(it);
            it--;
            XmlExporter();
        }
    }
}

bool Vehicle_list::XmlImporter(){
    if(size())
        erase(begin(), end());
    bool done=false;

    QFile file(VehicleFile);
    if (file.open(QFile::ReadOnly | QFile::Text)){
        QXmlStreamReader xmlIn(&file);
        while(xmlIn.readNextStartElement()){
            if(xmlIn.name()==StarterWord){
                while(xmlIn.readNextStartElement()){
                    std::string vehicletype =(xmlIn.name().toString().toStdString());


                    Veicolo* v;
                    if(vehicletype=="Automobile"){
                        v=automobile::importAuto(xmlIn);
                        done=true;
                    }
                    if(vehicletype=="Autocarro"){
                        v=autocarro::importCamion(xmlIn);
                        done=true;
                    }
                    if(vehicletype=="Motociclo"){
                        v=motociclo::importMoto(xmlIn);
                        done=true;
                    }
                    if(!v){
                        while (!xmlIn.isEndElement() || xmlIn.name() != QString::fromStdString(vehicletype))
                            xmlIn.readNext();
                    }
                    else{
                        push_back(v->clone());
                        delete v;
                        xmlIn.skipCurrentElement();
                    }
                }
            }
        }
    }
    file.close();
    return done;
}

void Vehicle_list::XmlExporter() const{
    QFile file(VehicleFile);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlOut(&file);

    xmlOut.setAutoFormatting(true);
    xmlOut.writeStartDocument();
    xmlOut.writeStartElement(StarterWord);
    for(auto it=begin(); it!=end(); it++){
        if(dynamic_cast<const automobile*>(*it))
            dynamic_cast<const automobile*>(*it)->Ownexporter(xmlOut);

        if(dynamic_cast<const autocarro*>(*it))
            dynamic_cast<const autocarro*>(*it)->Ownexporter(xmlOut);
        if(dynamic_cast<const motociclo*>(*it))
            dynamic_cast<const motociclo*>(*it)->Ownexporter(xmlOut);
    }

    xmlOut.writeEndElement();
    xmlOut.writeEndDocument();
    file.close();
}

Vehicle_list::Vehicle_list(){}

Vehicle_list::~Vehicle_list(){
    for(auto it=begin(); it!=end(); it++){
        delete (*it);
    }
}
