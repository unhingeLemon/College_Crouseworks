#include<GL/glut.h>
#include<GL/freeglut_ext.h>
#include<iostream>
//https://www.opengl.org/resources/libraries/glut/spec3/node45.html
//https://www.opengl.org/resources/libraries/glut/spec3/node54.html
using namespace std;

void display1();
void displayTriangle();
void keyboardMonitor(unsigned char key, int x, int y);
void mouseMonitor(int button, int state, int x, int y);
void mousePosition(int x, int y);
void textAdjust(int value);

float xpos = 0.0f;
float ypos = 0.0f;

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(640,480);
   glutInitWindowPosition(0,0); //top left most
   glutCreateWindow("simple");
   glutDisplayFunc(display1);
   glutKeyboardFunc(keyboardMonitor);
   glutMouseFunc(mouseMonitor);
   //glutMotionFunc(mousePosition);
   glutPassiveMotionFunc(mousePosition);
   
   glutMainLoop();
}

void textAdjust(int value){
	xpos -= .02f;
	glutPostRedisplay();
}

void mousePosition(int x, int y){
	cout << "Mouse Location : " << x << " " << y << endl;
}


void mouseMonitor(int button, int state, int x, int y	){
	
	if(button==GLUT_LEFT_BUTTON){
		cout << "LEFT" << endl;
		if(state == GLUT_UP){
			cout << "UP " << x << endl;
		}else{
			cout << "DOWN " << x << endl;
		}
	}
	
}


void keyboardMonitor(unsigned char key, int x, int y){
	cout << key << " " << xpos << " " << y << endl;
	
		switch(key){
			case 'a':
			case 'A':
				xpos-=.05f;
				break;
				
			case 'd':
			case 'D':
				xpos+=.05f;
				break;
			
		}
		
		glutPostRedisplay();

	
	
}
void display1(){
 glClear(GL_COLOR_BUFFER_BIT);
 //glColor3f(0.0,0.0,1.0);
 
 const unsigned char str[100] = {"FEU-TECH"};
 glColor3f(0.0f, 0.0f, 1.0f);
 glRasterPos2f(xpos, ypos);
 glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, str);
 glFlush();	
 
 glutTimerFunct(1000,textAdjust,1);

}

void displayTriangle(){
	
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_TRIANGLES);
  glVertex2f(-.5f,-.5f);
  glVertex2f(.5f,-.5f);
  glVertex2f(0.0f,.5f);
 glEnd();
 glFlush();
	
	
}

