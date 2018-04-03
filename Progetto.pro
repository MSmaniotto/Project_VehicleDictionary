TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

SOURCES += GUI/implementation/adduser_window.cpp \
    GUI/implementation/addvehicle_window.cpp \
    GUI/implementation/countdowntimer.cpp \
    GUI/implementation/login_window.cpp \
    GUI/implementation/modifyuser_window.cpp \
    GUI/implementation/modifyvehicle_window.cpp \
    GUI/implementation/mybutton.cpp \
    GUI/implementation/mymainwindow.cpp \
    GUI/implementation/showvehicle_window.cpp \
    GUI/implementation/typevehicle_chooser.cpp \
    GUI/implementation/users_panel.cpp \
    MODEL/implementation/account.cpp \
    MODEL/implementation/empty_error.cpp \
    MODEL/implementation/importer.cpp \
    MODEL/implementation/main.cpp \
    MODEL/implementation/user_list.cpp \
    MODEL/implementation/vehicle_list.cpp \
    MODEL/implementation/veicolo.cpp \
    MODEL/implementation/veicolo_autocarro.cpp \
    MODEL/implementation/veicolo_automobile.cpp \
    MODEL/implementation/veicolo_motociclo.cpp

HEADERS += \
    GUI/header/adduser_window.h \
    GUI/header/addvehicle_window.h \
    GUI/header/countdowntimer.h \
    GUI/header/login_window.h \
    GUI/header/modifyuser_window.h \
    GUI/header/modifyvehicle_window.h \
    GUI/header/mybutton.h \
    GUI/header/mymainwindow.h \
    GUI/header/showvehicle_window.h \
    GUI/header/typevehicle_chooser.h \
    GUI/header/users_panel.h \
    MODEL/header/account.h \
    MODEL/header/empty_error.h \
    MODEL/header/importer.h \
    MODEL/header/user_list.h \
    MODEL/header/vehicle_list.h \
    MODEL/header/veicolo.h \
    MODEL/header/veicolo_autocarro.h \
    MODEL/header/veicolo_automobile.h \
    MODEL/header/veicolo_motociclo.h
