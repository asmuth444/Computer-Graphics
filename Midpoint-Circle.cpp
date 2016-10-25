#include<GL/glut.h>
#include<iostream>
#include<conio.h>
using namespace std;
float radius,cx,cy,p;

void drawPixel(float x,float y)
{
	glBegin(GL_POINTS);
	glVertex2f(cx+x,cy+y);
	glVertex2f(cx-x,cy+y);
  	glVertex2f(cx+x,cy-y);
  	glVertex2f(cx-x,cy-y);
  	glVertex2f(cx+y,cy+x);
  	glVertex2f(cx-y,cy+x);
  	glVertex2f(cx+y,cy-x);
  	glVertex2f(cx-y,cy-x);
  	glEnd();
}

void display()
{
	float x=0,y=radius;
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-500,500,-500,500);
	p=(5/4)-radius;
  	drawPixel(x,y);
  	while(x<y)
  	{
  		x++;
  		if(p<0)
  		{
  			p += (2*x)+6;
  		}
  		else
  		{
  			y--;
  			p += (2*(x-y))+1;
  		}
  		drawPixel(x,y);
  
  	}
  	glFlush();
}

int main(int argc,char **argv)
{
	cout<<"Enter Radius:"<<endl;
	cin>>radius;
	cout<<"Enter X coordinate for center:"<<endl;
	cin>>cx;
	cout<<"Enter Y coordinate for center:"<<endl;
	cin>>cy;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Midpoint Circle");
	glutDisplayFunc(display);
	glutMainLoop();
	getch();
	return 0;
}
