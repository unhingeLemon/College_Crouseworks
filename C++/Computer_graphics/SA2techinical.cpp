#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();


void doorSeperate(){
	glColor3f(0.0,0.0,0);
	glLineWidth(7.0f);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(0,-0.5);
	glEnd();
}


void handle1Lines(){
	glColor3f(0.0,0.0,0);
	glLineWidth(7.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.15,-0.3);
	glVertex2f(-0.15,-0.2);
	glVertex2f(-0.05,-0.2);
	glVertex2f(-0.05,-0.3);
	glEnd();
}

void handle2Lines(){
	glColor3f(0.0,0.0,0);
	glLineWidth(7.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.15,-0.2);
	glVertex2f(0.15,-0.3);
	glVertex2f(0.05,-0.3);
	glVertex2f(0.05,-0.2);
	glEnd();
}

void handle1(){
	glColor3ub(79,223,216);
	glBegin(GL_POLYGON);
	glVertex2f(-0.15,-0.3);
	glVertex2f(-0.15,-0.2);
	glVertex2f(-0.05,-0.2);
	glVertex2f(-0.05,-0.3);
	glEnd();
}

void handle2(){
	glColor3ub(79,223,216);
	glBegin(GL_POLYGON);
	glVertex2f(0.15,-0.2);
	glVertex2f(0.15,-0.3);
	glVertex2f(0.05,-0.3);
	glVertex2f(0.05,-0.2);
	glEnd();
}


void chimneyLines(){
	glColor3f(0.0,0.0,0);
	glLineWidth(7.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.4,0.3);
	glVertex2f(-0.4,0.7);
	glVertex2f(-0.2,0.7);
	glVertex2f(-0.2,0.5);
	glEnd();
}

void chimney(){
	glColor3ub(193,24,0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4,0.3);
	glVertex2f(-0.4,0.7);
	glVertex2f(-0.2,0.7);
	glVertex2f(-0.2,0.5);
	glEnd();
}


void doorLines(){
	glColor3f(0.0,0.0,0);
	glLineWidth(7.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.2,-0.5);
	glVertex2f(-0.2,0);
	glVertex2f(0.2,0);
	glVertex2f(0.2,-0.5);
	glEnd();
}

void door(){
	glColor3ub(230,166,96);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2,-0.5);
	glVertex2f(-0.2,0);
	glVertex2f(0.2,0);
	glVertex2f(0.2,-0.5);
	glEnd();
}

void displayFoundationLines(){
	glColor3f(0.0,0.0,0);
	glLineWidth(7.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,0.2);
	glVertex2f(0.0,.7);
	glVertex2f(0.5,0.2);
	glVertex2f(.5f,-.5f);
	glEnd();
}

void displayFoundation(){
	glColor3ub(92,181,100);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,0.2);
	glVertex2f(0.0,.7);
	glVertex2f(0.5,0.2);
	glVertex2f(.5f,-.5f);
	glEnd();
}
int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(800,800);
   glutInitWindowPosition(0,0);
   glutCreateWindow("simple");
   glutDisplayFunc(display);
   glutMainLoop();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	displayFoundation();
	displayFoundationLines();
	door();
	doorLines();
	chimney();
	chimneyLines();
	handle1();
	handle2();
	handle1Lines();
	handle2Lines();
	doorSeperate();
	glFlush();
}

