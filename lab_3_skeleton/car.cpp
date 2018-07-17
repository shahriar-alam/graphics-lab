#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>




//Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.25, 0.25, 0.25, 0.0);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _angle1 = 0.0;
float _angle2 = 0.0;
float _angle3 = 0.0;

//Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.3, -7.0);


	glPushMatrix();
	glTranslatef(_angle, 0.0, 0.0);
	glRotatef(_angle3, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.5, -0.15, 0.0);
	glVertex3f(0.5, -0.15, 0.0);
	glVertex3f(0.5, 0.15, 0.0);
	glVertex3f(-0.5, 0.15, 0.0);
	glEnd();

	_angle2 = _angle;
    glPopMatrix();

    glPushMatrix();
	glTranslatef(_angle2+0.25, -0.15, 0.0);
	glRotatef(_angle3, 0.0, 1.0, 0.0);
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.11;
		float x = r * cos(A);
		float y = r * sin(A);
        glVertex2f(x,y);
	}
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(_angle2-0.25, -0.15, 0.0);
	glRotatef(_angle3, 0.0, 1.0, 0.0);
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.11;
		float x = r * cos(A);
		float y = r * sin(A);
        glVertex2f(x,y);
	}
	glEnd();

	glPopMatrix();



	glutSwapBuffers();
}

void update(int value)
 {
	_angle += 0.05f;
	if (_angle > 5)
    {
		_angle -= 7;
		_angle3 = 0;
	}


	_angle1 += 2.0f;
	if (_angle1 > 360)
	{
		_angle1 -= 360;
	}

    _angle3 += 0.2f;
	if (_angle3 > 30)
	{
		_angle3 -= 30;
	}

	glutPostRedisplay();


	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(100,100);

	//Create the window
	glutCreateWindow("Solar System");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}








