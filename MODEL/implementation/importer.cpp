#include "MODEL/header/importer.h"


void importData(QXmlStreamReader &input, std::string tag, QDate& target){
    input.readNextStartElement();
    bool done=false;
    if(input.name().toString().toStdString()!=tag)
        done=search(input, tag);
    if(input.name().toString().toStdString()==tag || done){
        int days=0, months=0, years=0;

        QString d = import(input, "days");
        QString m = import(input, "months");
        QString y = import(input, "years");

        days=d.toInt();
        months= m.toInt();
        years= y.toInt();

        target.setDate(years, months, days);
    }
}


bool search(QXmlStreamReader& input, std::string value){
    bool x=true;
    while(input.name().toString().toStdString()!=value && x && !input.isEndElement()){
        input.readNext();
        if(input.isEndElement())
            x=false;
    }
    return x;
}

QString import(QXmlStreamReader &input, std::string tag){
        if(input.isEndDocument())
            return NULL;
        input.readNextStartElement();
        bool done=true;
        if(input.name().toString().toStdString()!=tag){
            done=false;
            done=search(input, tag);
        }
        if(done){
            return input.readElementText();
        }
        else{
            return NULL;
        }
}
