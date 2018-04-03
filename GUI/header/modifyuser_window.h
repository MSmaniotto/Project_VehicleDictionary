#ifndef MODIFYUSER_WINDOW_H
#define MODIFYUSER_WINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include "MODEL/header/account.h"

class modifyUser_window: public QDialog
{
    Q_OBJECT
private:
    bool& change_done;
    QGridLayout* layout;
    QLabel* description;
    account& acc;
    QLabel* ID;
    QLabel* ID_show;
    QLabel* password;
    QLabel* name;
    QLabel* surname;
    QLineEdit* password_change;
    QLineEdit* name_change;
    QLineEdit* surname_change;
    QPushButton* changer;
    void passwordchanger();
    void namechanger();
    void surnamechanger();
public:
    modifyUser_window(QWidget*, account&, bool&);
public slots:
    void accountrefresher();
};

#endif // MODIFYUSER_WINDOW_H
