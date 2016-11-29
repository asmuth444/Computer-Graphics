#include<GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();//Used to load GlFigures into System Stack Prevents effects from spreading to other objects
    glRotatef(-20.0,1.0,0.0,0.0);
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glRotatef(90,1,0,0);
    glutSolidTorus(0.275,0.85,40,1);
    glPopMatrix();//Removes GLFigures from system stack
    glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(-0.55,0.5,0.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glutSolidTorus(0.275,0.85,40,1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(-0.75,-0.5,0.0);
    glRotatef(270,1,0,0);
    glutSolidCone(0.5,0.7,70,15);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,-1);
    glutSolidTeapot(0.2);
    glPopMatrix();
    glPopMatrix();
    glFlush();
}

void init()
{
    GLfloat black[] = {0,0,0};
    GLfloat yellow[] = {1,1,0};
    GLfloat cyan[] = {0,1,1};
    GLfloat white[] = {1,1,1};
    GLfloat direction[] = {1,0,1};
    GLfloat shine = 30;

    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,cyan);//Helps you change material of your GLobjects
    glMaterialfv(GL_FRONT,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT,GL_SHININESS,&shine);

    glLightfv(GL_LIGHT0,GL_AMBIENT,black);//Used for Lighting
    glLightfv(GL_LIGHT0,GL_DIFFUSE,yellow);
    glLightfv(GL_LIGHT0,GL_SPECULAR,white);
    glLightfv(GL_LIGHT0,GL_POSITION,direction);

    glEnable(GL_LIGHTING);//Enables Lighting
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);//Enables Depth
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(80,80);
    glutInitWindowSize(700,700);
    glutCreateWindow("Lights");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
