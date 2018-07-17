#include<iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

int input1;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

//(R,G,B)

//Draw a triangle using line.

int color = 0;
int first = 0;

for(int x = 100, y=100, col = 1, row = 1; row <= input1; row++ )
{
    for(col = 1; col<=input1; col++)
    {
        glBegin(GL_POLYGON);
        if(color == 0)
            {
                glColor3f(1.0, 1.0, 1.0);
                color = 1;
            }
        else
            {
                glColor3f(0.0, 0.0, 0.0);
                color = 0;
            }
        glVertex3i(x, y, 0);
        glVertex3i(x+30, y, 0);
        glVertex3i(x+30, y+30, 0);
        glVertex3i(x, y+30, 0);

        glEnd();

        x+=30;

    }
    y=y+30;
    x = 100;
    if(first == 0)
    {
        color = 1;
        first = color;
    }
    else
    {
        color = 0;
        first = color;
    }
}

/*
glBegin(GL_POLYGON);


    glVertex3i(25, 70, 0);
    glVertex3i(275, 70, 0);
    glVertex3i(150, 200, 0);
    //glVertex3i(25,200,0);


glEnd();
*/
glFlush();
}
void init(void)
{
/* select clearing (background) color */
glClearColor(0.5, 0.5, 0.5, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 700.0, 0, 700.0);
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{

cin>>input1;

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(700, 700);
glutInitWindowPosition(100, 100);
glutCreateWindow("hello");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

