#define GLEW_STATIC // <----- define GLEW_STATIC

#include<iostream>
#include <GL/glew.h>  // <---- additional header files
#include <GL/glut.h>


using namespace std;

void display();
void triangle();
void init();

void keyBoardMonitor(unsigned char key, int x, int y);
GLuint VBOid;

bool initTriangle = true;
float angle = 1.0f;

GLfloat trianglevertices[] = {
        0.0f, .75f, 0.0f,
      -0.75f, 0.0f, 0.0f,
       0.75f, 0.0f, 0.0f
  };

int main(int argc, char** argv){

   glutInit(&argc, argv);
   
   glutInitWindowSize(800,600);
   glutInitWindowPosition(100,100);
   glutCreateWindow("simple");
   
   glutKeyboardFunc(keyBoardMonitor);
   
   glutDisplayFunc(display);
   
   GLenum err = glewInit(); 
    if (err == GLEW_OK) {
       glutMainLoop();        
    }
   
}

void triangle(){
  
  if(initTriangle){
      
    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, trianglevertices, GL_STATIC_DRAW);

    glEnableClientState(GL_VERTEX_ARRAY);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(.75f,.75f,0.0f);
    initTriangle= false;
  }
    
  glPushMatrix();
  glRotatef(angle,0.0f,0.0f,1.0);
  
  glVertexPointer(3, GL_FLOAT, 0, 0);
  glDrawArrays(GL_TRIANGLES,0,6);
  glPopMatrix();
}

void animateTriangle(int value){
    angle++;
    glutPostRedisplay();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4f(.16f,.72f,.08f,1.0f);
  
  triangle();
  glFlush();
  
  glutTimerFunc(200,animateTriangle,1);
}

void keyBoardMonitor(unsigned char key, int x, int y){
    
    if(key == 'x'){
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &VBOid);
        exit(0);
    }
    
    
}

 

#define GLEW_STATIC
#define BUFFER_OFFSET(i) ((void*)(i))

#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;

void displayObject();
void displayTriangle();
void animateTriangle(int value);
void init();


void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam );

GLuint VBOid;
void keyMonitor(unsigned char key, int x, int y);
bool initTriangle = true;

float angle=1.0f;

GLfloat vertices[] = {
//-------------------  Triangle
    
    0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    
    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,
    
    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, -1.0f,
   -1.0f, -1.0f, -1.0f,
    
    0.0f,  1.0f,  0.0f,
   -1.0f,-1.0f, -1.0f,
   -1.0f,-1.0f,  1.0f,
 
};

GLfloat colorstriangle[] = {

    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    
    1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    
    1.0f,0.0f,0.0f,
    0.0f,0.0f,1.0f,
    0.0f,1.0f,0.0f
};


int main(int argc, char** argv){
    
   glutInit(&argc, argv);
   glutCreateWindow("simple");
   glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
   
   init();
   
   glutDisplayFunc(displayObject);
   glutKeyboardFunc(keyMonitor);
   glutInitWindowSize(800,600);
   
      
   GLenum err = glewInit();
   
   if(err == GLEW_OK){
       
      glEnable              ( GL_DEBUG_OUTPUT );
      glDebugMessageCallback( MessageCallback, 0 );
      printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
      printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR));
      glutMainLoop();
       
   }
   
}
   
void displayTriangle(){


  if(initTriangle){
     glGenBuffers(1, &VBOid);
     glBindBuffer(GL_ARRAY_BUFFER, VBOid);
  
     glBufferData(GL_ARRAY_BUFFER,  ((9*4) + (9*4)) * sizeof(GLfloat), vertices, GL_DYNAMIC_DRAW);
     glBufferSubData(GL_ARRAY_BUFFER, (9*4) * sizeof(GLfloat),(9*4) * sizeof(GLfloat), colorstriangle);
  
  
     glEnableClientState(GL_VERTEX_ARRAY);
     glEnableClientState(GL_COLOR_ARRAY);
  
     glVertexPointer(3, GL_FLOAT, 0, 0);    
     glColorPointer(3, GL_FLOAT,0,BUFFER_OFFSET((9*4)*sizeof(GLfloat) ));
     
     initTriangle = false;
  }
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glRotatef(angle,0.0f,1.0f,0.0f);
  
  glBegin(GL_TRIANGLES); //Displaying Six Sides
       for(int i=0; i < 12; i++) {
         glArrayElement(i);
     }
  glEnd(); 
  
  
  glFlush();
  glPopMatrix();    
    
}


void animateTriangle(int value){
    
    if(angle>360)
        angle=0;
        
    angle++;
    glutPostRedisplay();
}

void keyMonitor(unsigned char key, int x, int y){
    
    if(key=='x'){
     glDisableClientState(GL_VERTEX_ARRAY);
     glDisableClientState(GL_COLOR_ARRAY);

     glBindBuffer(GL_ARRAY_BUFFER, 0);
     glDeleteBuffers(1, &VBOid);
     
     exit(0);
    }

}

void displayObject(){
    
  
  glClear(GL_COLOR_BUFFER_BIT);
  displayTriangle();
  glutTimerFunc(50,animateTriangle,1);
  glFlush();
    
}

void GLAPIENTRY MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}

void init(){
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-4.0,4.0,-4.0,4.0, -4.0,4.0);
}

 

#define GLEW_STATIC
#define BUFFER_OFFSET(i) ((void*)(i))


#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;

void displayObject();
void displayTriangle();


void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam );
                 
                 GLuint VBOid;
                 
void keyMonitor(unsigned char key, int x, int y);
bool initTriangle = true;

float angle=1.0f;

void init();

GLfloat vertices[] = {
    
//-------------------  Triangle
    
    0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    
    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,
    
    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    
    0.0f,  1.0f,  0.0f,
    -1.0f,-1.0f, -1.0f,
    -1.0f,-1.0f,  1.0f,
 
};

GLfloat colorstriangle[] = {

    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    
    1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    
    1.0f,0.0f,0.0f,
    0.0f,0.0f,1.0f,
    0.0f,1.0f,0.0f
};

int main(int argc, char** argv){
    
   glutInit(&argc, argv);
   glutCreateWindow("simple");
   glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
   

   init();
   
   glutInitWindowSize(800,600);
   glutDisplayFunc(displayObject);
   glutKeyboardFunc(keyMonitor);
   
   GLenum err = glewInit();
   
   if(err == GLEW_OK){
       
       glEnable              ( GL_DEBUG_OUTPUT );
                            glDebugMessageCallback( MessageCallback, 0 );
       printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
       printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR));
       glutMainLoop();
       
   }
   
}
   
void init(){
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60, 800.0/600.0, 1.0, 10.0);
}


void displayTriangle(){


  if(initTriangle){
     glGenBuffers(1, &VBOid);
     glBindBuffer(GL_ARRAY_BUFFER, VBOid);
     glBufferData(GL_ARRAY_BUFFER,  ((9*4) + (9*4)) * sizeof(GLfloat), vertices, GL_DYNAMIC_DRAW);
     glBufferSubData(GL_ARRAY_BUFFER, (9*4) * sizeof(GLfloat),(9*4) * sizeof(GLfloat), colorstriangle);
  
     glEnableClientState(GL_VERTEX_ARRAY);
     glEnableClientState(GL_COLOR_ARRAY);
  
     glVertexPointer(3, GL_FLOAT, 0, 0);    
     glColorPointer(3, GL_FLOAT,0,BUFFER_OFFSET((9*4)*sizeof(GLfloat) ));
     
     initTriangle = false;
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  gluLookAt(0.5,2.0,4.0,0.0,0.0,0.0,0.0,1.0,0.0);
  
  glPushMatrix();
  glRotatef(angle,0.0f,1.0f,0.0f);
  
  glBegin(GL_TRIANGLES); //Displaying Six Sides
       for(int i=0; i < 12; i++) {
         glArrayElement(i);
     }
  glEnd(); 
  
  
  glFlush();
  glPopMatrix();    
    
}

void animateTriangle(int value){
    
    if(angle>360)
        angle=0;
        
    angle++;
    glutPostRedisplay();
}

void keyMonitor(unsigned char key, int x, int y){
    
    if(key=='x'){
     glDisableClientState(GL_VERTEX_ARRAY);
     glDisableClientState(GL_COLOR_ARRAY);

     glBindBuffer(GL_ARRAY_BUFFER, 0);
     glDeleteBuffers(1, &VBOid);
     
     exit(0);

    }
    
}


void GLAPIENTRY MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}


void displayObject(){
    
  
  glClear(GL_COLOR_BUFFER_BIT);
  displayTriangle();
  glutTimerFunc(50,animateTriangle,1);
  glFlush();
    
}
