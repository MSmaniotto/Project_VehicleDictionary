#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "MODEL/header/user_list.h"

class login_window:public QDialog
{
    Q_OBJECT
public slots:
    void login_action();
private:
    User_list& lista;
    QGridLayout* layout;
    QLabel* ID;
    QLineEdit* IDinput;
    QLabel* pass;
    QLineEdit* Passinput;
    QPushButton* loginbutton;
    bool& ok;
    account datapusher;

public:
    login_window(User_list&, bool&, account&);

};

#endif // LOGIN_WINDOW_H
