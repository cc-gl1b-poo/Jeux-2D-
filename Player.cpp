#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //definir le  son de la balle
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));

    // definir un graphique
    setPixmap(QPixmap(":/images/joueur.png"));

}

void Player::keyPressEvent(QKeyEvent *event){
    // deplacer le joueur vers la gauche et la droite
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // tirer avec lAa barre d'espace
    else if (event->key() == Qt::Key_Space){
        // reer une puce
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        //joueur au son des balles
        bulletsound->play();
    }
}

void Player::spawn(){
    // creer un ennemi
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
