#ifndef SCENESHADER_H
#define SCENESHADER_H

#include "abstractglscene.h"
#include "sceneglwindow.h"

#include <QOpenGLShaderProgram>
#include <QFile>
#include <QUrl>

class SceneShader : public QObject, public AbstractGLScene
{
    Q_OBJECT

    Q_PROPERTY(float angle READ angle WRITE setAngle)

public:
    SceneShader(SceneGLWindow *window);
    void initialize();
    void paint();
    void setAngle(float angle);
    float angle() { return m_angle; }

protected:
    void initializeObjectData();

    struct ScenePoint {
        QVector3D coords;
        QVector3D normal;

        ScenePoint(const QVector3D &c = QVector3D(), const QVector3D &n = QVector3D()) { coords = c; normal=n; }
    };

private:
    QOpenGLShaderProgram m_shader;
    QMatrix4x4 m_modelMatrix;
    QMatrix4x4 m_viewMatrix;
    QMatrix4x4 m_projectionMatrix;
    QVector<ScenePoint> m_data;
    float m_angle;

    QString fileContent(QString filename);
    void paintObject(const QMatrix4x4& mvMatrix);
};

#endif // SCENESHADER_H
