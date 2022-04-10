#include<GL/glut.h>
#include<GL/freeglut_ext.h>
#include<iostream>

using namespace std;


int boxSize = 10/800;
float x = 1/800;
float y = 1/800;
void display();


int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(0,0); //top left most
   glutCreateWindow("Snake");
   glutDisplayFunc(display);

   
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	

	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	
	glEnd();
	glFlush();
}
