#include<iostream>
#include<GL/glut.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

float xf,xl,yf,yl,dx,dy,x,y,pk;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	gluOrtho2D(0,100,0,100);
	dx = xl-xf;
	dy = yl-yf;
	pk = 2*dy-dx;
	glBegin(GL_POINTS);
	x = xf;
	y = yf;
	for(int i=0;i<=dx-1;i++)
	{
		if(pk<0)
		{
			x+=1;
			y=y;
			pk+= 2*abs(dy);
		}
		else
		{
			x+=1;
			y+=1;
			pk+= 2*abs(dy);
			pk-= 2*abs(dx);

		}
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv) 
{
	cout<<"Enter two end points of the line to be drawn:\n";
	cout<<"\nEnter Point( X1 , Y1):\n";
	cin>>xf;
	cin>>yf;
	cout<<"\nEnter Point( X2 , Y2):\n";
	cin>>xl;
	cin>>yl;
	glutInit(&argc,argv);  
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowSize(500,500);  
	glutCreateWindow("Bresenham");  
	glutDisplayFunc(display);  
	glutMainLoop();
	return 0;
}
