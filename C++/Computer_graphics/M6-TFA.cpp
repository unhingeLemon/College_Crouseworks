#define GLEW_STATIC 
#include<iostream>
#include <GL/glew.h> 
#include <GL/glut.h>
using namespace std;
void display();
void triangle();
void init();


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	GLenum err = glewInit();
	if (err == GLEW_OK) {
		glutMainLoop(); 
	}else{
		cout << "ERROR with GLEW\n"; 
	}
}
void square(){

	GLfloat squareVertices[] = {
		-0.4f, 0.0f, 0.0f,
		0.4f, 0.0f, 0.0f,
		0.4f, -0.4f, 0.0f,
		-0.4f, -0.4f, 0.0f
	};

	GLuint VBOid;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*12, squareVertices, 
	GL_STATIC_DRAW);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glDrawArrays(GL_LINE_LOOP,0,4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
}

void triangle(){

 
    GLfloat trianglevertex[] = {
       -0.3f, 0.0f, 
       0.0f, 0.3f, 
       0.3f, 0.0f, 
       
 
    };
 
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(2, GL_FLOAT,0,trianglevertex);
    glDrawArrays(GL_LINE_LOOP, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glColor4f(.16f,.72f,.08f,1.0f);
	square();
	triangle();
	glFlush();
}
