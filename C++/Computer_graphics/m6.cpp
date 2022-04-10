#include <iostream>
#include <GL\glut.h>


using namespace std;

void defaultDisplay();
void point();
void triangle();


int main(int argc, char **argv){
    
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(200,50);
    glutCreateWindow("My First OpenGL");
    glutDisplayFunc(defaultDisplay);
    glutMainLoop();
    
    return 0;
}


void trianglePoint(){
 
    
 
    GLfloat trianglevertex[] = {
       0.0f, .75f, 
       -0.75f, 0.0f, 
       0.75f, 0.0f, 
       
       -0.75f, -0.75f,
       -0.75f, 0.75f,
       0.75f, 0.75f,
       0.75f, -0.75f
 
    };
 
    glPointSize(20.0);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(2, GL_FLOAT,0,trianglevertex);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDrawArrays(GL_POINTS, 3, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}









void triangle(){
    
    /*
    GLfloat trianglevertex[] = {
       0.0f, .75f, 0.0f,
       -0.75f, 0.0f, 0.0f,
       0.75f, 0.0f, 0.0f
    
    };
    */
    
    GLfloat trianglevertex[] = {
       0.0f, .75f, 0.0f,
       -0.75f, 0.0f, 0.0f,
       0.75f, 0.0f, 0.0f
    
    };
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT,0,trianglevertex);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
}
    

void point(){
//    glPointSize(20.0);
//    
//    glBegin(GL_POINTS);
//      glVertex2f(-0.75f, -0.75f);
//      glVertex2f(-0.75f, 0.75f);
//      glVertex2f(0.75f, 0.75f);
//      glVertex2f(0.75f, -0.75f);
//    glEnd();
    glPointSize(20.0);
    GLfloat pointVertex[] = {
       -0.75f, -0.75f,
       -0.75f, 0.75f,
       0.75f, 0.75f,
       0.75f, -0.75f
    };
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT,0,pointVertex);
    glDrawArrays(GL_POINTS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    
}

void defaultDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f);
    point();
    triangle();
    glFlush();
}    

