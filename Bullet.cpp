#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // drew the rectangle
    //setRect(0,0,10,50); //size for the bullet
    setPixmap(QPixmap(":/images/images/bullet.png"));
    this->setScale(0.2);
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

void Bullet::move()
{
    // if bullet collides with enemy, destroy both
    // every QGraphicsItem has a member function called collidingItems()
    //   that returns a list of all the items that are colliding with the calling object
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();

            // remove bullet and enemy
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both from heap to save memory
            delete colliding_items[i]; //enemy
            delete this; // bullet

            // return (all code below refers to a non existint bullet)
            return;
        }
    }
    //move bullet up, if there was no collision with an Enemy
    setPos(x(), y()-10);

    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }

}
