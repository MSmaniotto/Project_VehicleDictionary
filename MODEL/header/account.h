#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QDate>
#include <QXmlStreamWriter>
#include <typeinfo>

class account{
private:
    std::string ID;
    std::string password;
    std::string name;
    std::string surname;
    std::string status;
public:
    account();
    account(std::string, std::string, std::string, std::string, std::string);
    std::string getID()const;
    std::string getpassword()const;
    std::string getname()const;
    std::string getsurname()const;
    std::string getStatus()const;

    bool operator !=(const account&);
    virtual ~account()=default;
    void setID(const std::string&);
    void setname(const std::string&);
    void setsurname(const std::string&);
    void setpassword(const std::string&);
    void setStatus(const std::string&);
    void XmlWriter(QXmlStreamWriter&)const;
    virtual account* copia()const;
};

class accountPremium:public account{
public:
    accountPremium(std::string, std::string, std::string, std::string, std::string);
    virtual accountPremium* copia()const;
};

class accountAdmin:public accountPremium{
public:
    accountAdmin(std::string, std::string, std::string, std::string, std::string);
    virtual accountAdmin* copia()const;
};

#endif // ACCOUNT_H
