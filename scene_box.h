#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "abstractglscene.h"
#include <QOpenGLTexture>
#include <QImage>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

struct TexturedPoint {
    QVector3D coord;
    QVector2D uv;
    TexturedPoint(const QVector3D& pcoord, const QVector2D& puv) {
        coord = pcoord; uv = puv;
    }
};

class SceneBox : public QObject, public AbstractGLScene
{
    Q_OBJECT

    Q_PROPERTY(float angle READ angle WRITE setAngle)

public:
    SceneBox(QOpenGLWindow *window = 0);
    ~SceneBox();
    void setTexture(QImage tex);
    void initialize();
    void paint();
    void setAngle(float angle);
    float angle() { return m_angle; }

protected:
    void initializeTexture();
    void initializeCudeData();
    void paintCube();

private:
    QImage m_tex;
    QOpenGLTexture *m_texture;
    bool m_initialized;
    QVector<TexturedPoint> m_data;
    float m_angle;

signals:
    void angleChanged();
};

#endif // MAINSCENE_H
