#ifndef TYPEVEHICLE_CHOOSER_H
#define TYPEVEHICLE_CHOOSER_H
#include <QPushButton>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>




class typevehicle_chooser:public QDialog
{
    Q_OBJECT
private:
    QGridLayout* layout;
    QPushButton* car;
    QPushButton* camion;
    QPushButton* motorbike;
    QLabel* description;
public:
    typevehicle_chooser(QWidget*);
};

#endif // TYPEVEHICLE_CHOOSER_H
