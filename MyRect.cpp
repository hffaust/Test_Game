#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "MyRect knows that you pressed a key";
    if (event->key() == Qt::Key_Left){
        //check bounds of screen
        if(pos().x() > 0){
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        //check bounds of screen
        if(pos().x() + 100 < 800){
            setPos(x()+10, y());
        }

    }
/*
 //Getting rid of the up and down movement as of video4
    else if (event->key() == Qt::Key_Up)
    {
         // zero, zero origin is at top left corner of screen
         // this direction -------> is the positive X axis
         //
         // this direction | is the positive Y axis
         //                |
         //                |
         //                |
         //                |
         //                V

        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
*/
    else if (event->key() == Qt::Key_Space){
        // space bar is pressed
        // create a bullet
        Bullet * bullet = new Bullet();
        //qDebug() << "bullet created";
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
