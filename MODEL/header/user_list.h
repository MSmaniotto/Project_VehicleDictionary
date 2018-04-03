#ifndef USER_LIST_H
#define USER_LIST_H
#include <list>
#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include "MODEL/header/account.h"
#include "MODEL/header/importer.h"
#include "MODEL/header/empty_error.h"

class User_list:public std::list<const account*>
{
private:
static QString StarterWord;
static QString UserFile;

public:
User_list();
bool insertAccount(account*);
void createAdmin();
void modifyaccount(std::string, std::string, std::string, std::string);

const account* search(std::string)const;

account& getaccount(std::string);

void deleteaccount(std::string);
~User_list();

bool XmlImporter();

void XmlExporter() const;

};

#endif // USER_LIST_H
