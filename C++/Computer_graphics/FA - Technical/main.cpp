#include<GL/glut.h>
#include<GL/freeglut_ext.h>
#include<iostream>
#include <stdlib.h>


using namespace std;

void display();
float xpos = 0.0f;
float ypos = 0.0f;
int colorLeftEye[3] = {0, 0, 255};
int colorRightEye[3] = {0, 0, 255};

void faceAdjust(int value){
	xpos += .05f;
	glutPostRedisplay();
}



void mouseMonitor(int button, int state, int x, int y	){
	

	switch(button){
		case GLUT_LEFT_BUTTON:
			colorLeftEye[1] = 0;
			colorLeftEye[0] = 255;
			break;
			
		case GLUT_RIGHT_BUTTON:
			colorRightEye[1] = 0;
			colorRightEye[0] = 255;
			break;
	
	}
	
	glutPostRedisplay();	
}



void adjust(int val){
	int v = val + 1;
	glutTimerFunc(1000,adjust,v);
	glutTimerFunc(1000,faceAdjust,0);
	if(val == 5){
		exit(0);
	}
	cout << v << endl;
}


void keyboardMonitor(unsigned char key, int x, int y){
	
		switch(key){
			case 'a':
			case 'A':
				xpos-=.05f;
				break;
				
			case 'd':
			case 'D':
				xpos+=.05f;
				break;
			case 'w':
			case 'W':
				ypos+=.05f;
				break;
				
			case 's':
			case 'S':
				ypos-=.05f;
				break;
			case 27:
				glutTimerFunc(1000,adjust,0);
				break;
		
		}
		
		glutPostRedisplay();

	
	
}





void specialkeyboardMonitor(int key, int x, int y){
	
		switch(key){
			case GLUT_KEY_LEFT:
				colorLeftEye[2] = 0;
				colorLeftEye[1] = 255;
				break;
			case GLUT_KEY_RIGHT:
				colorRightEye[2] = 0;
				colorRightEye[1] = 255;
				break;
		
		}
		
		glutPostRedisplay();

	
	
}




int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("FA5");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardMonitor);
	glutSpecialFunc(specialkeyboardMonitor);
	glutMouseFunc(mouseMonitor);
	glutMainLoop();
}

void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3ub(colorLeftEye[0],colorLeftEye[1],colorLeftEye[2]);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.8+xpos,0.1f+ypos);
	glVertex2f(-.5f+xpos,.5f+ypos);
	glVertex2f(-.2f+xpos,.1f+ypos);
	glEnd();
	
	glColor3ub(colorRightEye[0],colorRightEye[1],colorRightEye[2]);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.8f+xpos,0.1f+ypos);
	glVertex2f(.5f+xpos,.5f+ypos);
	glVertex2f(.2f+xpos,.1f+ypos);
	glEnd();
	
	glColor3ub(0,0,255);
	glLineWidth(4.0f);
	glBegin(GL_LINES);
	glVertex2f(-0.3+xpos, -0.2+ypos);
	glVertex2f(0.3+xpos, -0.2+ypos);

	glEnd();
	
	//box
	
	
	
	glFlush();
	

}

