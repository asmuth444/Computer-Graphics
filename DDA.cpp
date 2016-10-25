#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<stdlib.h>
using namespace std;

float xf,xl,yf,yl,dx,dy,x,y;
float step, xinc, yinc;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	gluOrtho2D(0,500,0,500);
	dx=xl-xf;
	dy=yl-yf;
	glBegin(GL_POINTS);
	if(abs(dx)>abs(dy))
	{
		step = abs(dx);
	}
	else
	{
		step = abs(dy);
	}
	xinc=dx/(float)step;
    	yinc=dy/(float)step;
	x = xf;
	y = yf;
	for(int k = 1;k <= step; k++)
	{
		x+=xinc;
		y+=yinc;
		glVertex2f(round(x),round(y));

	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv) 
{
  	cout<<"Enter two end points of the line to be drawn:\n";
  	cout<<"\nEnter Point( xl , Y1):\n";
  	cin>>xf;
  	cin>>yf;
  	cout<<"\nEnter Point( X2 , Y2):\n";
  	cin>>xl;
  	cin>>yl;
  	glutInit(&argc,argv);  
  	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
  	glutInitWindowSize(500,500);  
  	glutCreateWindow("DDA");  
  	glutDisplayFunc(display);  
  	glutMainLoop();
  	return 0;
}
