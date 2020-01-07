#include <QApplication>
#include "Game.h"

/* Video 6
 Topics:
-parents
-QGraphicsTextItem, setPlainText(), setFont(),setDefaultTextColor()
*/

/* Video 7
 * create resoruce file (.qrc file)
 * inside the resource file you have folders (aka prefixes)
 *
 * Use QMediaPlayer to add the sounds you want from the resource file
 *   by using QUrl("qrc:/<folder_name>/<file_name>")
*/

/* Video 8
 * Qt provides 2 classes for displaying images:
 * 1. QPixmap  ---> better for drawing on to the screen
 * 2. QImage ---> better for input/output & the manipulation of single pixels
 *
 * To actually represent an image inside of a scene you have to pass the QPixmap or QImage
 *   inside a QGraphicsPixmapItem
 */

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
