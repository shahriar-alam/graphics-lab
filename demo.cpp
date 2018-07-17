#include<iostream>
#include <cmath>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;

int carX = 200, carY = 70;
int dividerX = 250, dividerY = 4, move_div;

void road()
{
    glBegin(GL_QUADS);

    glColor3f(0.5,0.5,0.5);
    glVertex2f(250 - 100, 500);
    glVertex2f(250 - 100, 0);
    glVertex2f(250 + 100, 0);
    glVertex2f(250 + 100, 500);
    glEnd();
 }


void divider()//black patch drawn in middle of road
 {
    glLoadIdentity();
    glTranslatef(0, move_div, 0);
    for(int i = 1; i <= 10; i++)
    {
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(dividerX  - 5, dividerY * 15 * i + 18);
        glVertex2f(dividerX  - 5, dividerY * 15 * i - 18);
        glVertex2f(dividerX  + 5, dividerY * 15 * i - 18);
        glVertex2f(dividerX  + 5, dividerY * 15 * i + 18);
        glEnd();
    }
    for(int i = 1; i <= 10; i++)
    {
        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
        glVertex2f(dividerX  - 100, dividerY * 15 * i - 18);
        glVertex2f(dividerX  - 95, dividerY * 15 * i - 18);
        glVertex2f(dividerX  - 95, dividerY * 15 * i + 18);
        glVertex2f(dividerX  - 100, dividerY * 15 * i + 18);
        glEnd();
    }

    for(int i = 1; i <= 10; i++)
    {
        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
        glVertex2f(dividerX  + 100, dividerY * 15 * i + 18);
        glVertex2f(dividerX  + 95, dividerY * 15 * i + 18);
        glVertex2f(dividerX  + 95, dividerY * 15 * i - 18);
        glVertex2f(dividerX  + 100, dividerY * 15 * i - 18);
        glEnd();
    }

    glLoadIdentity();
 }


void car()//car for racing
 {
    glPointSize(10.0);
    glBegin(GL_POINTS);//tire
    glColor3f(0,0,0);
    glVertex2f(carX - 15, carY + 16);
    glVertex2f(carX + 15, carY + 16);
    glVertex2f(carX - 15, carY - 16);
    glVertex2f(carX + 15, carY - 16);
    glEnd();

    glBegin(GL_QUADS);//middle body
    glColor3f(0.8,0.8,0.8);
    glVertex2f(carX - 15, carY + 35);
    glVertex2f(carX - 15, carY - 35);
    glVertex2f(carX + 15, carY - 35);
    glVertex2f(carX + 15, carY + 35);
    glEnd();

    glBegin(GL_QUADS);//windshild upper
    glColor3f(0,0,0);
    glVertex2f(carX - 13, carY + 35);
    glVertex2f(carX + 13, carY + 35);
    glVertex2f(carX + 7, carY + 25);
    glVertex2f(carX - 7, carY + 25);
    glEnd();

    glBegin(GL_POLYGON);//up body
    glColor3f(0.8,0.8,0.8);
    glVertex2f(carX - 15, carY + 35);
    glVertex2f(carX + 15, carY + 35);
    glVertex2f(carX + 10, carY + 55);
    glVertex2f(carX - 10, carY + 55);
    glEnd();

    glBegin(GL_TRIANGLES);//headlight1
    glColor4f(1,1,1,0.9);
    glVertex2f(carX - 10, carY + 55);
    glVertex2f(carX + 4, carY + 100);
    glVertex2f(carX - 20, carY + 100);
    glEnd();

    glBegin(GL_TRIANGLES);//headlight2
    glColor4f(1,1,1,0.9);
    glVertex2f(carX + 10, carY + 55);
    glVertex2f(carX - 2, carY + 100);
    glVertex2f(carX + 20, carY + 100);
    glEnd();

    glBegin(GL_POLYGON);//up defination
    glColor3f(0.5,0.5,0.5);
    glVertex2f(carX - 10, carY + 20);
    glVertex2f(carX - 10, carY -20);
    glVertex2f(carX + 10, carY - 20);
    glVertex2f(carX + 10, carY + 20);
    glEnd();

     //windshild lower
    glBegin(GL_QUADS);
    glColor3f(0,0,0);//middle body
    glVertex2f(carX - 13, carY - 35);
    glVertex2f(carX + 13, carY - 35);
    glVertex2f(carX + 7, carY - 25);
    glVertex2f(carX - 7, carY - 25);
    glEnd();

    glBegin(GL_QUADS);//down body
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(carX - 15, carY - 35);
    glVertex2f(carX + 15, carY - 35);
    glVertex2f(carX + 10, carY - 45);
    glVertex2f(carX - 10, carY - 45);
    glEnd();
}


 void Specialkey(int key, int x, int y)
 {
 switch(key)
 {
 case GLUT_KEY_UP:
            move_div -= 8;
            break;
 case GLUT_KEY_DOWN:
            move_div += 8;
            break;
 case GLUT_KEY_LEFT:carX = 200;
        break;
 case GLUT_KEY_RIGHT:carX = 300;
        break;
 }
 glutPostRedisplay();
 }


 void init()
 {
    glClearColor(0.0,0.50,0.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0,0,0);
    glutSwapBuffers();
 }

 void update(int i)
 {
    exit(0);
 }

void score_display()
{
    glutTimerFunc(5000,update,0);
}
 void display()
 {
     glClear(GL_COLOR_BUFFER_BIT);
     glClearColor(0.6, 0.4, 0.2, 0.0);
     road();
     divider();
     car();

     move_div = move_div - 9;
    if(move_div < - 60)
    {
        move_div = 0;
    }
     glutSwapBuffers();

 }

 int main(int argc, char **argv)
 {
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
     glutInitWindowPosition(100,100);
     glutInitWindowSize(640,360);
     glutCreateWindow("Race All you want");
     init();
     glutDisplayFunc(display);
     glutSpecialFunc(Specialkey);
     glutIdleFunc(display);

     glutMainLoop();

     return 0;
 }
