#include<GL/glut.h>
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
float rx,ry,cx,cy,p;

void drawPixel(float x,float y)
{
	glBegin(GL_POINTS);
	glVertex2f(cx+x,cy+y);
	glVertex2f(cx-x,cy+y);
	glVertex2f(cx+x,cy-y);
	glVertex2f(cx-x,cy-y);
  	glEnd();
}

void display()
{
	float x=0,y=ry;
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-500,500,-500,500);
  	p = pow(ry,2)-(pow(rx,2)*ry)+(pow(rx,2)/4);
  	float dx = 2*pow(ry,2)*x;
  	float dy = 2*pow(rx,2)*y;
  	while(dx<=dy)
  	{
  		x++;
  		if(p<0)
        	{
            		dx = dx + (2 * (pow(ry,2)));
            		p += dx +(pow(ry,2));
		}
        	else
        	{
        		y--;
            		dx = dx + (2 * (pow(ry,2)));
            		dy = dy - (2 * (pow(rx,2)));
			p += dx - dy + (pow(ry,2));
		}
		drawPixel(x,y);
	}

	p=pow(ry,2)*pow(x+0.5,2)+pow(rx,2)*pow(y-1,2)-pow(rx*ry,2);
	while(y>0)
  	{
		y--;
  		if(p>0)
        	{
            		dy = dy - (2 * (pow(rx,2)));
			p += pow(rx,2) - dy;
		}
		else
		{
			x++;
			dy = dy - (2 * (pow(rx,2)));
			dx = dx + (2 * (pow(ry,2)));
			p += dx - dy + pow(rx,2);
		}
		drawPixel(x,y);
	}
	glFlush();
}
int main(int argc,char **argv)
{
	cout<<"Enter Radius X:"<<endl;
	cin>>rx;
	cout<<"Enter Radius Y:"<<endl;
	cin>>ry;
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
