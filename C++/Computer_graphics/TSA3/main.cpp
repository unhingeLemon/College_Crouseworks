#define GLEW_STATIC 
#include<iostream>
#include <GL/glew.h> 
#include <GL/glut.h>
using namespace std;
void display();


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("TSA3");
	glutDisplayFunc(display);
	GLenum err = glewInit();
	if (err == GLEW_OK) {
		glutMainLoop(); 
	}else{
		cout << "ERROR with GLEW\n"; 
	}
}



void box(){
    GLfloat box[] = {
       -0.5f, 1.0f, 
       -0.5f, 0.0f, 
       0.5f, 0.0f, 
       0.5f, 1.0f
    };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT,0,box);
    glDrawArrays(GL_POLYGON, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void eyes(){
    GLfloat eye1[] = {
       -0.3f, 0.8f, 
       -0.2f, 0.8f, 
       -0.2f, 0.7f, 
       -0.3f, 0.7f
       
    };
    GLfloat eye2[] = {
		0.3f, 0.8f, 
    	0.2f, 0.8f, 
    	0.2f, 0.7f, 
    	0.3f, 0.7f
    };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT,0,eye1);
    glDrawArrays(GL_POLYGON, 0, 4);
	glVertexPointer(2, GL_FLOAT,0,eye2);
    glDrawArrays(GL_POLYGON, 0, 4);
    
    glDisableClientState(GL_VERTEX_ARRAY);
}

void noseMouth(){
	 GLfloat nose[] = {
       -0.2f, 0.4f, 
       -0.0f, 0.6f, 
       0.2f, 0.4f
    };
	
	 GLfloat mouth[] = {
	   -0.3f, 0.2f, 
	   0.3f, 0.2f
    };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT,0,nose);
    glDrawArrays(GL_POLYGON, 0, 3);
	glVertexPointer(2, GL_FLOAT,0,mouth);
    glDrawArrays(GL_LINES, 0, 2);
    
    glDisableClientState(GL_VERTEX_ARRAY);
}




void face(){
	glColor3f(0,0,1);
	box();
	glColor3f(0,1,0);
	eyes();
	noseMouth();
 
}


void body(){

	GLfloat shapeVertices[] = {
		-0.3f, 0.0f, 0.0f,
		-0.5f, -0.3f, 0.0f,
		-0.5f, -0.7f, 0.0f,
		-0.3f, -1.0f, 0.0f,
		0.3f, -1.0f, 0.0f,
		0.5f, -0.7f, 0.0f,
		0.5f, -0.3f, 0.0f,
		0.3f, 0.0f, 0.0f
		

	};

	GLuint VBOid;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*24, shapeVertices, 
	GL_STATIC_DRAW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glDrawArrays(GL_POLYGON,0,8);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
	
	
	
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	face();
	body();
	glColor3f(0,1,1);
	body();
	glFlush();
}

