#include<GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glTranslatef(2.0,3.0,0.0);
	glScalef(2.0,3.0,0.0);
	glRotatef(30,0.0,0.0,1.0);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(0.2,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(-0.2,-0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(-0.2,-0.5);
	glVertex2f(0.1,0.8);
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Test");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
