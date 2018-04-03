#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>
#include <QAction>
#include <QMenu>

class myButton: public QPushButton
{
    Q_OBJECT
private:
    QAction* activeAction; //mantiene l'azione selezionata sul pulsante


public:
    explicit myButton(QWidget* parent=0);
    void ChangeMenu(QMenu*);

public slots:
    void setAction(QAction* action);

private slots:
    void updateButtonStatus();
};

#endif // MYBUTTON_H
