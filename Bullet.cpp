#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>

extern Game * game; // il exite un objet global externe appele jeu

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // dessin des graphiques
    setPixmap(QPixmap(":/images/bullet.png"));


    // creer/connecter une minuterie pour deplacer la balle de temps en temps
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // demarrer le chronometre
    timer->start(50);
}

void Bullet::move(){
    // obtenir une liste de tous les elements actuellement en collision avec cette puce
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // si l'un des objets en collision est un ennemi detruisez a la fois la balle ety l'

    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // augmenter le score
            game->score->increase();

            // retirez les de la scene  (toujours sur les tas)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // supprimer les du tas pour economiserde la memoire
            delete colliding_items[i];
            delete this;

            // retour(tout le code ci-dessous fait reference a une puce inexistance)
            return;
        }
    }

    // s'il n'y a pas eu de collision avec un ennemi deplacez la balle vers l'avant
    setPos(x(),y()-10);
    // si la balle est hors de l'ecran detruisez-la
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
