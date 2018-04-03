#ifndef IMPORTER_H
#define IMPORTER_H

#include <QXmlStreamReader>
#include <typeinfo>
#include <QDate>

bool search(QXmlStreamReader &input, std::string value);

//caso QDate
void importData(QXmlStreamReader &input, std::string tag, QDate& target);


QString import(QXmlStreamReader &input, std::string tag);



#endif // IMPORTER_H
