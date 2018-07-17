#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0, 1.0, 0.0);//(R,G,B)

//Draw a triangle using line.

  glBegin(GL_LINE_LOOP);

    glVertex3i(100, 100, 0);
    glVertex3i(350, 300, 0);

    glVertex3i(50, 300, 0);
    glVertex3i(300, 100, 0);

    glVertex3i(200, 400, 0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3i(450, 300, 0);
    glVertex3i(700, 100, 0);
    glVertex3i(635, 300, 0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3i(500, 100, 0);
    glVertex3i(750, 300, 0);
    glVertex3i(565, 300, 0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3i(565, 300, 0);
    glVertex3i(635, 300, 0);
    glVertex3i(600, 400, 0);

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
gluOrtho2D(0.0, 800.0, 0, 500.0);
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
glutInitWindowSize(800, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("hello");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

