#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include<QImage>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // rendre la scene 800 x 600 au lieu de l'infini par  (default)
    setBackgroundBrush(QBrush(QImage(":/images/k.jpg")));

    // faire de la scene nouvellement creee la scene a visualiser(puisque game est un widget QGraphicsvie
    // il peut etre utilise pour visualiser des scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // creer le joueur
    player = new Player();

    player->setPos(400,500); // todo generaliser pour etre toujours au milieu en bas de l'ecran
    // rendre ;e joueur focalisable et le definir comme etant le focus actuel
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // ajouter le joueur a la scene
    scene->addItem(player);

    // creer le score /la sante
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // engendrer des ennemis
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //jouer la music de fond
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bg.mp3"));
    music->play();

 show();
}
