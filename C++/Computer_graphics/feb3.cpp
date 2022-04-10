#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1024,768);
   glutInitWindowPosition(0,0);
   glutCreateWindow("simple");
   glutDisplayFunc(display);
   glutMainLoop();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  
   glPointSize(2.0);
   glBegin(GL_POINTS);
       glColor3f(1.0, 1.0, 1.0);
       glVertex2f(-0.5, -0.5);
       glColor3f(1.0, 0.0, 1.0);
       glVertex2f(-0.5, 0.5);
       
       glColor3f(0.0, 0.0, 1.0);
       glVertex2f(0.5, 0.5);
       glColor3f(0.0, 1.0, 0.0);
       glVertex2f(0.5, -0.5);
    glEnd();

 
  glFlush();
}



#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1024,768);
   glutInitWindowPosition(0,0);
   glutCreateWindow("simple");
   glutDisplayFunc(display);
   glutMainLoop();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  
   glPointSize(20.0);
   glBegin(GL_LINES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
  glEnd();


 
  glFlush();
}





#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1024,768);
   glutInitWindowPosition(0,0);
   glutCreateWindow("simple");
   glutDisplayFunc(display);
   glutMainLoop();
}

void display(){
   glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_TRIANGLES);
     glVertex2f(-0.8,0.1f);
     glVertex2f(.-5f,.5f);
     glVertex2f(-.2f,.1);
     
   glEnd();
   glFlush();

}



#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1024,768);
   glutInitWindowPosition(0,0);
   glutCreateWindow("simple");
   glutDisplayFunc(display);
   glutMainLoop();
}

void display(){
   glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POLYGON);
  glVertex2f(0.1,0.1);
  glVertex2f(0.6,0.1);
  glVertex2f(0.7,0.3);
  glVertex2f(0.6,0.6);
  glVertex2f(0.1,0.6);
  glVertex2f(0.0,0.3);
 glEnd();
 glFlush();

}




#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1024,768);
   glutInitWindowPosition(0,0);
   glutCreateWindow("simple");
   glutDisplayFunc(display);
   glutMainLoop();
}

void display(){
   glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_TRIANGLE_STRIP);
  glVertex2f(-.5f,-.5f);
  glVertex2f(.5f,-.5f);
  glVertex2f(0.0,.5f);
  glVertex2f(.6f,.5f);
 glEnd();
 glFlush();	


}








