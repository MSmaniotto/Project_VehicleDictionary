#ifndef ADDUSER_WINDOW_H
#define ADDUSER_WINDOW_H
#include "MODEL/header/user_list.h"
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include "mybutton.h"


class AddUser_Window: public QDialog{
    Q_OBJECT
public slots:
    void checker_adder();
private:
    User_list& list;
    QGridLayout* layout;
    QLabel* explaination;
    QLabel* IDlabel;
    QLabel* ID_allarm;
    QLineEdit* ID_insert;
    QLabel* passlabel;
    QLineEdit* pass_insert;
    QLabel* namelabel;
    QLineEdit* name_insert;
    QLabel* surnamelabel;
    QLineEdit* surname_insert;
    QLabel* typeaccountlabel;
    QMenu* statusmenu;
    myButton* typeaccount_chooser;
    QPushButton* adder;

public:
    AddUser_Window(User_list&, QDialog*);
};

#endif // ADDUSER_WINDOW_H
