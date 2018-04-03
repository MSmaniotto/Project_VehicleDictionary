#ifndef USERS_PANEL_H
#define USERS_PANEL_H
#include <QMessageBox>
#include <QListWidget>
#include "MODEL/header/user_list.h"
#include "modifyuser_window.h"
#include "adduser_window.h"


class users_panel:public QDialog
{
    Q_OBJECT
private:
    User_list& accounts;
    QGridLayout* layout;
    QPushButton* add;
    QPushButton* remover;
    QPushButton* modify;
    QListWidget* items;
public:
    users_panel(QWidget*,User_list&);
    void populate();
    void rewrite();
public slots:
    void refresh();
    void callaccountremover();
    void callaccountmodify();
    void openUserAdder();
    void enable_modify();
};

#endif // USERS_PANEL_H
