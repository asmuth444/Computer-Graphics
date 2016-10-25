#include<GL/glut.h>

void display() //every GL project will have atleast 2 function this and main
{
	glClear(GL_COLOR_BUFFER_BIT); //WORKING WITH GRAPHICS AND VOLOR IS STORED IN BUFFER SO CLEAR IT FIRST
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUAD_STRIP);//EVERY THING we want to draw with vertices is its parameter 1.GL_POINTS
	//GL_LINES GL_LINE_LOOP GL_LINE_STRIP GL_TRIANGLES GL_TRIANGLE_STRIP GL_QUADS GL_QUAD_STRIP GL_POLYGON
	glVertex2f(0.2,0.5); //2for 2d and f for float value
	glVertex2f(0.5,0.5);
	glVertex2f(-0.2,-0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(-0.2,-0.5);
	glVertex2f(0.1,0.8);
	glEnd(); //every begin will have one end
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);//next line is to dicide the display  mode 
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //parameter1 is for color red green blue 2 is for buffer mode
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Test");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
