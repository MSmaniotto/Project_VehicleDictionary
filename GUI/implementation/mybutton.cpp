#include "GUI/header/mybutton.h"

myButton::myButton(QWidget* parent): QPushButton(parent), activeAction(nullptr){}

void myButton::setAction(QAction* action){ //cambia l'azione attiva di myButton
    if(activeAction &&activeAction!=action){ //se vi è un azione già attiva su myButton ne sconnetto i segnali verso gli slot di myButton
        disconnect(activeAction, &QAction::changed, this, &myButton::updateButtonStatus);
        disconnect(this, &myButton::clicked, activeAction, &QAction::trigger);
    }
    activeAction=action;

    updateButtonStatus();

    connect(activeAction, &QAction::changed, this, &myButton::updateButtonStatus);

    connect(this, &myButton::clicked, activeAction, &QAction::trigger);
}

void myButton::updateButtonStatus(){
    if(!activeAction)
        return;
    setText(activeAction->text());
}

//funzione per cambiare menu ad un pulsante sconnettendo un eventuale menu ad esso collegato
void myButton::ChangeMenu(QMenu *menu){
    if(this->menu())
        disconnect(this->menu(), SIGNAL(triggered(QAction*)), this, SLOT(setAction(QAction*)));
    this->setMenu(menu);
}
