#include "widget.h"
#include <QApplication>
#include "glwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GLWindow window;
    window.resize(600, 400);
    window.show();

    return a.exec();
}
