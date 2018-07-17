#include <iostream>
#include <queue>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

int arr1 [2][3], arr2[2][3], arr3[2][3], arr4[2][3], arr5[2][3];
int tx, ty, x, y;
double sx, sy, deg;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0, 1.0, 0.0);//(R,G,B)

//Draw a triangle using line.

  glBegin(GL_LINES);
//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);
    glVertex3i(0, -300, 0);
    glVertex3i(0,  300, 0);

glEnd();

  glBegin(GL_LINES);
//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);
    glVertex3i(300, 0, 0);
    glVertex3i(-300, 0, 0);

glEnd();

glColor3f(1.0, 1.0, 1.0);

glBegin(GL_LINE_LOOP);
//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);
    for(int j = 0; j<3; j++)
    {
        glVertex3i(arr1[0][j], arr1[1][j], 0);
    }

glEnd();

glColor3f(1.0, 0.0, 0.0);

glBegin(GL_LINE_LOOP);
//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);
    for(int j = 0; j<3; j++)
    {
        glVertex3i(arr2[0][j], arr2[1][j], 0);
    }

glEnd();

glColor3f(0.0, 0.0, 1.0);

glBegin(GL_LINE_LOOP);
//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);
    for(int j = 0; j<3; j++)
    {
        glVertex3i(arr3[0][j], arr3[1][j], 0);
    }

glEnd();

glColor3f(0.5, 0.5, 0.5);

glBegin(GL_LINE_LOOP);
//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);
    for(int j = 0; j<3; j++)
    {
        glVertex3i(arr5[0][j], arr5[1][j], 0);
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

void trans()
{
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i == 0)
                arr2[i][j] = arr1[i][j] + tx;
            else
                arr2[i][j] = arr1[i][j] + ty;
        }
    }
}

void scal()
{
    x=arr1[0][0];
    y=arr1[1][0];
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i == 0)
                arr3[i][j] = arr1[i][j] - x;
            else
                arr3[i][j] = arr1[i][j] - y;
        }
    }
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i == 0)
                arr3[i][j] = round(arr3[i][j] * sx);
            else
                arr3[i][j] = round(arr3[i][j] * sy);
        }
    }
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i == 0)
                arr3[i][j] = arr3[i][j] + x;
            else
                arr3[i][j] = arr3[i][j] + y;
        }
    }
}

void rot()
{
    x=arr1[0][0];
    y=arr1[1][0];
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i == 0)
                arr4[i][j] = arr1[i][j] - x;
            else
                arr4[i][j] = arr1[i][j] - y;
        }
    }
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i == 0)
                arr5[i][j] = round(arr4[i][j] * cos(deg) - arr4[i+1][j] * sin(deg));
            else
                arr5[i][j] = round(arr4[i-1][j] * sin(deg) + arr4[i][j] * cos(deg));
        }
    }
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i == 0)
                arr5[i][j] = arr5[i][j] + x;
            else
                arr5[i][j] = arr5[i][j] + y;
        }
    }
}

void init(void)
{
/* select clearing (background) color */
glClearColor(0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
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
cout<<"Points: "<<endl;
for(int i = 0; i<2; i++)
{
    for (int j = 0; j<3; j++)
    {
        cin>>arr1[i][j];
    }
}
cout<<"translation: "<<endl;
cin>>tx>>ty;
cout<<"scalling: "<<endl;
cin>>sx>>sy;
cout<<"Degree"<<endl;
cin>>deg;
deg = deg * M_PI / 180;
trans();
scal();
rot();
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

