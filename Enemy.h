#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);

public slots:
    // signals & slots
    // a signal is just a signal
    // a slot is a member funtion that is supposed to react to a specific signal
    //  have to put it under 'public slots' instead of just public
    // ANY CLASS THAT WANTS TO USE SIGNALS & SLOTS HAS TO DERIVE FROM QObject
    //  and incldue the Q_OBJECT Macro at top of the class
    void move();
};

#endif // ENEMY_H
