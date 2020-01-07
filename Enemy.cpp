#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include<stdlib.h>  // gives us rand() ->  returns really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random x position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //add the enemy image
    setPixmap(QPixmap(":/images/images/rocket.png"));
    this->setScale(0.1);

    // drew the rectangle
    //setRect(0,0,100,100); //size for the bullet

    // connect!
    QTimer * timer = new QTimer();
    // the connect function lets us connect a certain signal with a certain slot
    // connect 1st param: the object whose signal you want to connect
    // connect 2nd param: the function of the first object (signal) that is connected
    // connect 3rd param: the object whose slot we want connected
    // connect 4th param: the function of the second object (slot) that we want to connect to
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    if (pos().y() > 600){
            //decrease the health
            game->health->decrease();

            //remove enemy after its off the screen
            scene()->removeItem(this);
            delete this;
    }
    //move enemy down
    setPos(x(), y() + 5);

}
