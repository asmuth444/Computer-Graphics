#include<GL/glut.h>
#include<iostream>
using namespace std;
float deg=0.0,dis=0.0;
int check=0;
int move=-1;
void display();
void timer(int);
void mouse_input(int ,int ,int ,int );

int main(int argc ,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("Controller");
	glutDisplayFunc(display);
	if(check)
	{
		cout<<"True";
	}
	glutTimerFunc(100,timer,0);
	glutMouseFunc(mouse_input);
	glutMainLoop();
}
void display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(dis,0.0,0.0);
	glRotatef(deg,0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(100,-100);
	glVertex2f(-100,-100);
	glVertex2f(-100,100);
	glVertex2f(100,100);
	glEnd();
	glFlush();
}

void timer(int v)
{
	cout<<"Distance: "<<dis<<endl;
	cout<<"Degree: "<<deg<<endl;
	cout<<"State:"<<move<<endl;
	if(move==0)
	{
		dis-=1;
		deg+=0.0;
	} 
	else if(move==1)
	{
		dis+=1;
		deg+=0.0;
	}
	else if(move==2)
	{
	dis+=0.0;
		deg+=1;
	}
	glutPostRedisplay();
	glutTimerFunc(100,timer,0);
}

void mouse_input(int button , int state,int x ,int y)
{
	if(button == GLUT_LEFT_BUTTON && state== GLUT_DOWN)
	{
		if(check==0)
		{
			move=0;
			check=1;
		} 
		else
		{
			move=1;
			check=0;
		}
	}
	else if(button == GLUT_RIGHT_BUTTON && state== GLUT_DOWN)
	{
		move=2;
	}
}
