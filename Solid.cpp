#include "GL/freeglut.h"
#include "GL/gl.h"

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-500, 500, -500, 500,-500,500);
    //glutWireTeapot(0.2); Refer Solid Notes for reference
    //glutSolidTeapot(20);
    //glutWireCube(20);
    //glutSolidCube(20);
    //glutSolidTorus(100,300,100,100);
    //glutWireTorus(100,300,100,100);
    //glutSolidCone(100,300,100,100);
    glutWireCone(50,100,10,10);
    //glutSolidSphere(20);
    //glutWireSphere(20);
    
    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Solid Figure");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
