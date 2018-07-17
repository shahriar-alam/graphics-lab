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


//Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.3, -7.0);


	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.5);
	glRotatef(55, 0.0, -1.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
    glutSolidSphere(.60,25,50);
    //glutWireSphere(0.60,50,50);
	glPopMatrix();

    glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.65);
	glRotatef(100.0 ,-1.0, 0.0, 0.0); //Rotate about the z-axis
    glRotatef(_angle ,0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 1.0);
    glutSolidCone(.50,1.0,30,15);
    //glutWireCone(.50,1.0,30,15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 0.5, 0.5);
	glRotatef(100.0 ,-1.0, 0.0, 0.0); //Rotate about the z-axis
    glRotatef(_angle ,0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
    glutSolidTorus(.15,.50,30,65);
    //glutWireTorus(.15,.50,30,65);
	glPopMatrix();

	glutSwapBuffers();
}

void update(int value)
 {
	_angle += 1.0f;
	if (_angle > 360)
    {
		_angle -= 360;
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








