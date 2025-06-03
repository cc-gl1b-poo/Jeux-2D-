#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //definir une position x aleatoire
    int random_number = rand() % 700;
    setPos(random_number,0);


    setPixmap(QPixmap(":/images/enemi.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // creer/connecter un minuteur pour deplacer l'enemi de temps en temps
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // demarrer le chronometre
    timer->start(50);
}

void Enemy::move(){
    // deplacer l'ennemi vers le bas
    setPos(x(),y()+5);

    // detruire l'ennemi lorsqu'il sort de l'ecran
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

