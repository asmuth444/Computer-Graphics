#include "GL/freeglut.h"
#include "GL/gl.h"

void renderFunction()
{
    GLubyte CHAR_L[24]={0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,0xff, 0xc0, 0xff, 0xc0};
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glBitmap(10,12,0,0,11,0,CHAR_L);
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h)
{

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

}
void init(void)
{
    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
    glClearColor (0.0, 0.0, 0.0, 0.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(100,100);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Bitmap");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
