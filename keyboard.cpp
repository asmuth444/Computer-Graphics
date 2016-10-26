#include<GL/glut.h>
#include<iostream>
float tx=0;
unsigned char p;
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
	if(p=='a')
	{
		tx-=0.01;
	}
	else if(p=='d')
	{
		tx+=0.01;
	}
	else if(p=='s')
	{
		tx+=0.00;
	}
	glutPostRedisplay();
	glutTimerFunc(100,time,0);
}
void key(unsigned char k,int x,int y)
{
	p=k;
}


int main(int argc,char **argv)
{
	glutInit(& argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Keyboard");
	glutDisplayFunc(display);//Display Callback
	glutTimerFunc(100,time,0);//Timer Callback
	glutKeyboardFunc(key);//Keyboard Callback param: key, cursor postion x,cursor position y
	glutMainLoop();
	return 0;
}
