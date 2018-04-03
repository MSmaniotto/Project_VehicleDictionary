#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include "MODEL/header/vehicle_list.h"
#include "mybutton.h"
#include "MODEL/header/user_list.h"
#include "typevehicle_chooser.h"
#include "addvehicle_window.h"
#include "users_panel.h"
#include "showvehicle_window.h"
#include "countdowntimer.h"
#include "modifyvehicle_window.h"

class MyMainWindow: public QWidget {
    Q_OBJECT
private:
    User_list& accounts;
    account& activeuser;
    Vehicle_list listaVeicoli;
    QListWidget* vehicles_list;
    std::vector<const Veicolo*> selection;
    std::vector<std::string> vehicles_added;


    QLabel* typelabel;
    QGridLayout* myGrid;
    QGridLayout* buttonLayout;
    QMenu* VehicleTypemenu;
    QMenu* VehicleBrandMenu;
    QMenu* VehicleNamesMenu;

    QLabel* brandlabel;
    QLabel* namelabel;
    myButton* VehicleSelect;
    myButton* VehicleBrand;
    myButton* VehicleName;
    QPushButton* deletevehicle;
    QPushButton* modifyvehicle;

    QLabel* description;
    QLabel* istruzioni;

    void clear_vehicles_list();
    void resetVehicleBrandMenu();
    void resetVehicleNamesMenu();

public:
    explicit MyMainWindow(User_list& users, account* actual_user, QWidget* parent=0);
    ~MyMainWindow();
private slots:
    void addmenu_NameOfVehicles(QAction*);
    void refreshlist(QAction*);
    void addmenu_brand_list(QAction*);
    void reset();
    void enable_buttons();
    void callvehicleremover();

public slots:
    void openUsers_panel();
    void openCarAdder();
    void openVehicleChooserToAdd();
    void openCamionAdder();
    void openMotorbikeAdder();
    void openVehicleShow();
    void callvehiclemodify();
};

#endif // MAINWINDOW_H
