#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialiser le score a 0
    health = 3;

    // dessiner le texte
    setPlainText(QString("Health: ") + QString::number(health)); // sante: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // sante: 2
}

int Health::getHealth(){
    return health;
}

