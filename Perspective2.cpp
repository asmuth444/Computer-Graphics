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
    gluPerspective(45,1/1,0,500);//For perspective projection
    gluLookAt(180,180,180,0,0,0,1,1,0);// For setting Camera position arguments: Camera postion, Look at position, Up direction 
    glutWireCube(50);
    glFlush();
    glutSwapBuffers();//Buffer swapping
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//Allows Double Buffer Usage for faster rendering
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Solid Figure");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
