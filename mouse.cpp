#include<GL/glut.h>
#include<iostream>
float tx=0;
bool dir;
void display()
{
	gluOrtho2D(-500.0,500.0,-500.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glTranslatef(tx,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(-100,100);
	glVertex2f(-100,-100);
	glVertex2f(100,-100);
	glEnd();
	glFlush();
}

void time(int arg)
{
	if(dir)
	{
		tx-=0.01;
	}
	else
	{
		tx+=0.01;
	}
	glutPostRedisplay();
	glutTimerFunc(100,time,0);
}
void key(int button,int state,int x,int y)
{
	if(button == GL_LEFT_BUTTON && state == GL_DOWN)
	{
		dir=1;
	}	
	if(button == GL_LEFT_BUTTON && state == GL_DOWN)
	{
		dir=0;
	}
}


int main(int argc,char **argv)
{
	glutInit(& argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("bresenham");
	glutDisplayFunc(display);//Display Callback
	glutTimerFunc(100,time,0);//Timer Callback
	glutMouseFunc(mouse);//Mouse Callback param: button, state, cursor postion x,cursor position y
	glutMainLoop();
	return 0;
}
