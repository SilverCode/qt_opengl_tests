#include "widget.h"
#include <QApplication>
#include "sceneglwindow.h"
#include "mainscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SceneGLWindow window;
    QSurfaceFormat fmt;
    fmt.setSamples(16);
    window.setFormat(fmt);
    MainScene scene(&window);
    window.setScene(&scene);
    scene.setTexture(QImage(":/images/crate.jpg"));
    window.resize(600, 600);
    window.show();

    return a.exec();
}
