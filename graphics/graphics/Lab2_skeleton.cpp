#include <iostream>
#include <queue>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

queue <int> pointx;
queue <int> pointy;
int a, b, r, flag = 0;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0, 1.0, 0.0);//(R,G,B)

//Draw a triangle using line.

  glBegin(GL_POINTS);
//glBegin(GL_LINE_STRIP);
//glBegin(GL_LINE_LOOP);


    int x = 0;
    int y = 0;
    y=r;
    pointx.push(x);
    pointy.push(y);
    glVertex3i(x+a, y+b, 0); //2nd
    glVertex3i(y+a, x+b, 0); //1st
    glVertex3i(-y+a, x+b, 0); //3rd
    glVertex3i(-x+a, -y+b, 0); //4th
//    glVertex3i(x+a, y+b, 0); //5th
//    glVertex3i(x+a, y+b, 0); //6th
//    glVertex3i(x+a, y+b, 0); //7th
//    glVertex3i(x+a, y+b, 0); //8th

    int h = 1-r;
    if(h>0)
    {
        x=x+1;
        y=y-1;
        pointx.push(x);
        pointy.push(y);
        flag = 1;
    }
    else
    {
        x=x+1;
        pointx.push(x);
        pointy.push(y);
        flag = 0;
    }
    glVertex3i(x+a, y+b, 0); //2nd
    glVertex3i(y+a, x+b, 0); //1st
    glVertex3i(-x+a, y+b, 0); //3rd
    glVertex3i(-y+a, x+b, 0); //4th
    glVertex3i(-y+a, -x+b, 0); //5th
    glVertex3i(-x+a, -y+b, 0); //6th
    glVertex3i(x+a, -y+b, 0); //7th
    glVertex3i(y+a, -x+b, 0); //8th
    while(1)
    {
        if(flag == 0)
        {
            h=h+2*pointx.front()+3;
            pointx.pop();
            pointy.pop();
            if(h>0)
            {
                x=x+1;
                y=y-1;
                if(x>y)
                    break;
                pointx.push(x);
                pointy.push(y);
                flag = 1;
            }
            else
            {
                x=x+1;
                if(x>y)
                    break;
                pointx.push(x);
                pointy.push(y);
                flag = 0;
            }
        }
        else
        {
            h=h+2*(pointx.front() - pointy.front())+5;
            pointx.pop();
            pointy.pop();
            if(h>0)
            {
                x=x+1;
                y=y-1;
                if(x>y)
                    break;
                pointx.push(x);
                pointy.push(y);
                flag = 1;
            }
            else
            {
                x=x+1;
                if(x>y)
                    break;
                pointx.push(x);
                pointy.push(y);
                flag = 0;
            }
        }
        glVertex3i(x+a, y+b, 0); //2nd
        glVertex3i(y+a, x+b, 0); //1st
        glVertex3i(-x+a, y+b, 0); //3rd
        glVertex3i(-y+a, x+b, 0); //4th
        glVertex3i(-y+a, -x+b, 0); //5th
        glVertex3i(-x+a, -y+b, 0); //6th
        glVertex3i(x+a, -y+b, 0); //7th
        glVertex3i(y+a, -x+b, 0); //8th
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
gluOrtho2D(-300.0, 300.0, -300, 300.0);
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
cin>>a>>b>>r;
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

