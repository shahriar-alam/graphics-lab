#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

int x1, y1, x2, y2;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 1.0);//(R,G,B)

//Draw a triangle using line.

//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int x, y;
    glBegin(GL_POINTS);
    if(dx == 0)
    {
        for(x = x1, y = y1; y <= y2; y++)
        {
            glVertex3i(x, y, 0);
        }

    }
    else if(dy == 0)
    {
        for(x = x1, y = y1; x <= x2; x++)
        {
            glVertex3i(x, y, 0);
        }
    }
    else
    {
        float m = dy / dx;
        if( m <= 1)
        {
            int flag = 0;
            int dne = 2*(dy-dx);
            int de = 2*dy;

            int d = 2*dy - dx;
            x = x1;
            y = y1;
            if(d > 0)
            {
                flag = 1;
                glVertex3i(++x, ++y, 0);
            }
            else if (d <= 0)
            {
                flag = 0;
                glVertex3i(++x, y, 0);
            }
            while(x <= x2)
            {
                if(flag == 0)
                {
                    d = d + de;
                    if(d > 0)
                    {
                        flag = 1;
                        glVertex3i(++x, ++y, 0);
                    }
                    else if (d <= 0)
                    {
                        flag = 0;
                        glVertex3i(++x, y, 0);
                    }
                }
                else if(flag == 1)
                {
                    d = d + dne;
                    if(d > 0)
                    {
                        flag = 1;
                        glVertex3i(++x, ++y, 0);
                    }
                    else if (d <= 0)
                    {
                        flag = 0;
                        glVertex3i(++x, y, 0);
                    }
                }
            }
        }
        else if (m > 1)
        {
            int flag = 0;
            int dne = 2*(dx-dy);
            int dn = 2*dx;

            int d = dy - 2*dx;
            x = x1;
            y = y1;
            if(d > 0)
            {
                flag = 1;
                glVertex3i(++x, ++y, 0);
            }
            else if (d <= 0)
            {
                flag = 0;
                glVertex3i(x, ++y, 0);
            }
            while(y <= y2)
            {
                if(flag == 0)
                {
                    d = d + dn;
                    if(d > 0)
                    {
                        flag = 1;
                        glVertex3i(++x, ++y, 0);
                    }
                    else if (d <= 0)
                    {
                        flag = 0;
                        glVertex3i(x, ++y, 0);
                    }
                }
                else if(flag == 1)
                {
                    d = d + dne;
                    if(d > 0)
                    {
                        flag = 1;
                        glVertex3i(++x, ++y, 0);
                    }
                    else if (d <= 0)
                    {
                        flag = 0;
                        glVertex3i(x, ++y, 0);
                    }
                }
            }
        }
    }
    glEnd();

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
glClearColor(0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 300.0, 0, 300.0);
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/

void input_point()
{
    cin>>x1>>y1>>x2>>y2;
}

int main(int argc, char** argv)
{
input_point();
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(300, 300);
glutInitWindowPosition(300, 100);
glutCreateWindow("hello");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

