/*
#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>
*/

/* Video1 Topics
 *
 * QGraphicsScene ---> Container for all of the game objects (ex: a player, a tree, etc)
 * |---> think of the scene as the world
 *
 * QGraphicsItem ---> Any object that you want to put inside a scene has to be derived from QGraphicsItem
 * |---> Youre supposed to inherit from QGraphicsItem to build your custom item and put it in the scene
 * |---> QGraphicsRectItem: just a rectangle that is subclass of QGraphicsItem
 *
 * QGraphicsView ---> A widget that is used to visualize the scene... Allows for the QGraphicsItems to be printed on the screen
 */

/* Video2 Topics
 * events ---> anything important that happens through the lifetime of the application
 *   for example if the user uses the mouse or presses a key
 *
 * keyPressEvent() stores the information about the even in a QKeyEvent object...
 *   i.e. what key was pressed etc
 *
 * event propagation system ---> describes the order in which the event is passed around
 *   i.e. when a key press occurs who the event is passed to and how we know when the event has been handled and
 *     execution of the game can continue.
 *
 * QDebug ---> Header file to print out messages to console to test code and help with debugging
 */

/* Video4 Topics
 * Three main coordinate systems in Qt to be aware of from largest scope to smallest:
 *   Note: all three coordinate systems start at the top left corner.
 * 1. QGraphicScene ---> by default will grow to accomadate size of all objects contained within...
 *     in order to avoid this behavior you have to set the scene's sceneRect size to be fixed.
 *     sceneRect sets the scrollable area of the screen.
 * 2. QGraphicView
 * 3. QGraphicItem
 *
 */

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //step 1: create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //step 2: create an item to put into the scene
    MyRect * player = new MyRect();
    // By default rect has length and width of ZERO, so you must define it to make it usable
    // setRect : first 2 arguments define the coordinates of the top left corner of the rectangle
    // |---> next 2 arguments define the width and the height in pixels
    player->setRect(0,0,100,100);

    //step 3: add the item to the scene
    scene->addItem(player);

    //make rect focusable so that it will respond to events
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //step 4: create a view to visualize scene
    QGraphicsView * view = new QGraphicsView(scene);
    // alternatively could leave the consturctor blank then do:
    // view->setScene(scene);

    // quick and dirty solution to disable the scroll bars so that
    //  firing bullets doesnt make the screen get infinitely bigger
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // view is a widget so by default its invisible... make visible with show() function.
    view->show();
    // we want to set the view to be the same size as the scene
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width() / 2, view->height() - player->rect().height());

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000); //spawn an enemy every 2000 milliseconds


    return a.exec();
}
*/
