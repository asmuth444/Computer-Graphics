#include<GL/glut.h>
#include<iostream>
float tx=0,ty=0;
void display()
{
	gluOrtho2D(-500.0,500.0,-500.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glTranslatef(tx,ty,0);
	glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(-100,100);
	glVertex2f(-100,-100);/*Timer function glutTimerFunc(time millisec,function to be called,parameter to function) should be recursively for looping
glutPostRedisplay() calls the display function without name*/
	glVertex2f(100,-100);
	glEnd();
	glFlush();
}

void time(int arg)
{
	tx+=0.1;
	ty+=0.1;
	glutPostRedisplay();
	glutTimerFunc(100,time,0);
}

int main(int argc,char **argv)
{
	glutInit(& argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Timer");
	glutDisplayFunc(display);
	glutTimerFunc(100,time,0);
	glutMainLoop();
	return 0;
}
