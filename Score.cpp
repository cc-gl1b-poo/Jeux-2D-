#include "Score.h"
#include <QFont>
#include<QColor>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialiser le score a 0
    score = 0;

    // dessiner le texte
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
