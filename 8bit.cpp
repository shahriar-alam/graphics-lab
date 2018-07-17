#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

//(R,G,B)

//Draw a triangle using line.

glBegin(GL_POLYGON);

    glColor3f(1.0, 0.8, 0.8);
    glVertex3i(280, 510, 0);
    glVertex3i(380, 510, 0);
    glVertex3i(380, 595, 0);
    glVertex3i(280, 595, 0);

glEnd();
glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(270, 500, 0);
    glVertex3i(270, 300, 0);
    glVertex3i(430, 300, 0);
    glVertex3i(430, 500, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(1.0, 0.8, 0.8);
    glVertex3i(320, 485, 0);
    glVertex3i(380, 485, 0);
    glVertex3i(380, 510, 0);
    glVertex3i(320, 510, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3i(320, 460, 0);
    glVertex3i(380, 460, 0);
    glVertex3i(380, 485, 0);
    glVertex3i(320, 485, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3i(330, 430, 0);
    glVertex3i(370, 430, 0);
    glVertex3i(370, 460, 0);
    glVertex3i(330, 460, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3i(345, 430, 0);
    glVertex3i(345, 410, 0);
    glVertex3i(355, 410, 0);
    glVertex3i(355, 430, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.6, 0.6, 0.6);
    glVertex3i(345, 332, 0);
    glVertex3i(355, 332, 0);
    glVertex3i(355, 410, 0);
    glVertex3i(345, 410, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.6, 0.6, 0.6);
    glVertex3i(295, 320, 0);
    glVertex3i(405, 320, 0);
    glVertex3i(405, 332, 0);
    glVertex3i(295, 332, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.4, 0.4, 1.0);
    glVertex3i(295, 105, 0);
    glVertex3i(330, 105, 0);
    glVertex3i(330, 320, 0);
    glVertex3i(295, 320, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.4, 0.4, 1.0);
    glVertex3i(330, 280, 0);
    glVertex3i(370, 280, 0);
    glVertex3i(370, 320, 0);
    glVertex3i(330, 320, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.4, 0.4, 1.0);
    glVertex3i(370, 105, 0);
    glVertex3i(405, 105, 0);
    glVertex3i(405, 320, 0);
    glVertex3i(370, 320, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.6, 0.6, 1.0);
    glVertex3i(370, 80, 0);
    glVertex3i(405, 80, 0);
    glVertex3i(405, 105, 0);
    glVertex3i(370, 105, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.6, 0.6, 1.0);
    glVertex3i(295, 80, 0);
    glVertex3i(330, 80, 0);
    glVertex3i(330, 105, 0);
    glVertex3i(295, 105, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(295, 30, 0);
    glVertex3i(330, 30, 0);
    glVertex3i(330, 80, 0);
    glVertex3i(295, 80, 0);
    glVertex3i(295, 55, 0);
    glVertex3i(255, 55, 0);
    glVertex3i(255, 30, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(370, 30, 0);
    glVertex3i(445, 30, 0);
    glVertex3i(445, 55, 0);
    glVertex3i(405, 55, 0);
    glVertex3i(405, 80, 0);
    glVertex3i(370, 80, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(1.0, 0.8, 0.8);
    glVertex3i(270, 300, 0);
    glVertex3i(270, 255, 0);
    glVertex3i(295, 255, 0);
    glVertex3i(295, 280, 0);
    glVertex3i(305, 280, 0);
    glVertex3i(305, 300, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(1.0, 0.8, 0.8);
    glVertex3i(405, 280, 0);
    glVertex3i(405, 255, 0);
    glVertex3i(430, 255, 0);
    glVertex3i(430, 300, 0);
    glVertex3i(395, 300, 0);
    glVertex3i(395, 280, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(295, 495, 0);
    glVertex3i(320, 495, 0);
    glVertex3i(320, 510, 0);
    glVertex3i(295, 510, 0);


glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(380, 495, 0);
    glVertex3i(405, 495, 0);
    glVertex3i(405, 520, 0);
    glVertex3i(395, 520, 0);
    glVertex3i(395, 535, 0);
    glVertex3i(380, 535, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(255, 660, 0);
    glVertex3i(255, 635, 0);
    glVertex3i(320, 635, 0);
    glVertex3i(320, 660, 0);


glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(255, 635, 0);
    glVertex3i(255, 595, 0);
    glVertex3i(395, 595, 0);
    glVertex3i(395, 635, 0);


glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(345, 595, 0);
    glVertex3i(345, 540, 0);
    glVertex3i(355, 540, 0);
    glVertex3i(355, 595, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(370, 560, 0);
    glVertex3i(395, 560, 0);
    glVertex3i(395, 595, 0);
    glVertex3i(370, 595, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(355, 585, 0);
    glVertex3i(370, 585, 0);
    glVertex3i(370, 595, 0);
    glVertex3i(355, 595, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(255, 585, 0);
    glVertex3i(255, 560, 0);
    glVertex3i(280, 560, 0);
    glVertex3i(280, 570, 0);
    glVertex3i(295, 570, 0);
    glVertex3i(295, 585, 0);

glEnd();

glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(295, 560, 0);
    glVertex3i(330, 560, 0);
    glVertex3i(330, 585, 0);
    glVertex3i(295, 585, 0);

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
glClearColor(1.0, 1.0, 1.0, 0.0);
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

