attribute vec4 qt_Vertex;
attribute vec4 qt_MultiTexCoord0;
varying vec4 qt_TexCoord0;

void main(void)
{
    //gl_Position = qt_ModelViewProjectionMatrix * qt_Vertex;
    gl_Position = qt_Vertex;
    qt_TexCoord0= qt_MultiTexCoord0;
}
