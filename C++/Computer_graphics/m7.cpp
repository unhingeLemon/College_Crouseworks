#define GLEW_STATIC // <----- define GLEW_STATIC
#include<iostream>
#include <GL/glew.h> // <---- additional header files
#include <GL/glut.h>
using namespace std;
void display();
void triangle();
void init();
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	GLenum err = glewInit(); // <------- Include glew initialization calls before the main loop
	if (err == GLEW_OK) {
		glutMainLoop(); 
	}else{
		cout << "ERROR with GLEW\n"; 
	}
}
void triangle(){
	//1. Initialize the triangle using an array
	GLfloat trianglevertices[] = {
		0.0f, .75f, 0.0f,
		-0.75f, 0.0f, 0.0f,
		0.75f, 0.0f, 0.0f
	};
	//2. Generate a Vertex Object ID for your array of vertices and bind it
	GLuint VBOid;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, trianglevertices, 
	GL_STATIC_DRAW);
	//3. Activate and specify pointer to vertex array
	glEnableClientState(GL_VERTEX_ARRAY);
	//4. Draw the primitive object
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glDrawArrays(GL_TRIANGLES,0,6);
	//5. Disable client side capability for normal operation
	glDisableClientState(GL_VERTEX_ARRAY);
	// bind with 0, so, switch back to normal pointer operation
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(.16f,.72f,.08f,1.0f);
	triangle();
	glFlush();
}



//////////////////////////////////////////////////////////////
//with error


#define GLEW_STATIC

#include <iostream>
#include <GL\glew.h>
#include <GL\glut.h>
 
 
using namespace std;
 
void defaultDisplay();
void point();
void triangle();

// https://www.khronos.org/opengl/wiki/Debug_Output
void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam ) ;
 
int main(int argc, char **argv){
 
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(200,50);
    glutCreateWindow("My First OpenGL");
    glutDisplayFunc(defaultDisplay);
    
    
    
    GLenum err = glewInit();
    if(err==GLEW_OK){
        glutMainLoop();
    }else{
        cout << "Error in initializing GLEW extension library...";
    }
    
 
 
 
    return 0;
}
 
void triangle(){
 
    GLuint VBOid;
 
    GLfloat trianglevertex[] = {
       0.0f, .75f, 0.0f,
       -0.75f, 0.0f, 0.0f,
       0.75f, 0.0f, 0.0f
    };
    
    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, trianglevertex, GL_STATIC_DRAW);

 
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT,0,0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);

    
}
 
 
void defaultDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f);
    
    // During init, enable debug output
    glEnable ( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );

    triangle();
    glFlush();
} 

void GLAPIENTRY
MessageCallback( GLenum source,
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



///////////////////////////////////////////////////////////


#define GLEW_STATIC

#include <iostream>
#include <GL\glew.h>
#include <GL\glut.h>
 
 
using namespace std;
 
void defaultDisplay();
void point();
void triangle();

// https://www.khronos.org/opengl/wiki/Debug_Output
void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam ) ;
 
int main(int argc, char **argv){
 
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(200,50);
    glutCreateWindow("My First OpenGL");
    glutDisplayFunc(defaultDisplay);
    
    
    
    GLenum err = glewInit();
    if(err==GLEW_OK){
        glutMainLoop();
    }else{
        cout << "Error in initializing GLEW extension library...";
    }
    
 
 
 
    return 0;
}
 
void triangle(){
 
    //1. Initialize the triangle using an array
  GLfloat trianglevertices[] = {
        0.0f, .75f, 0.0f,
      -0.75f, 0.0f, 0.0f,
       0.75f, 0.0f, 0.0f,
       
       -0.75f, -0.75f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.75f, -0.75f, 0.0f
  };
  
  GLubyte indices[] = {
      0,1,2,
      3,4,5
  };
 

    
    //2. Generate a Vertex Object ID for your array of vertices and normal arrays and bind it
  GLuint VBOid; 
  glGenBuffers(1, &VBOid);
  glBindBuffer(GL_ARRAY_BUFFER, VBOid);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*18, trianglevertices, GL_STATIC_DRAW);
  
  GLuint VBOindex; 
  glGenBuffers(1, &VBOindex);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBOindex);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte)*6, indices, GL_STATIC_DRAW);
  

  //3. Activate and specify pointer to vertex array
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY); 

  //4. Draw the primitive object
  glVertexPointer(3, GL_FLOAT, 0, 0);
  glNormalPointer(GL_UNSIGNED_BYTE,0, 0);
  
  //5.
  //glDrawArrays(GL_TRIANGLES,0,6);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
  
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  
  // bind with 0, so, switch back to normal pointer operation
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glDeleteBuffers(1, &VBOid);
  glDeleteBuffers(1, &VBOindex);
    
}
 
 
void defaultDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f);
    
    // During init, enable debug output
    glEnable ( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );

    triangle();
    glFlush();
} 

void GLAPIENTRY
MessageCallback( GLenum source,
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









/////////////////////////////////////













#define GLEW_STATIC // <----- define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>  // <---- additional header files
#include <GL/glut.h>

using namespace std;

// Function Prototypes
void display();
void triangle();
void init();

void modifyTriangle(int value);
void monitorKeyboard(unsigned char key, int x, int y);

// Global Variables
bool triangleUpdate=false; //flag to check if triangle is for update
GLfloat *mappedVertices = NULL;
GLuint VBOid;

int main(int argc, char** argv){

        glutInit(&argc, argv);

        glutInitWindowSize(800,600);
        glutInitWindowPosition(100,100);
        glutCreateWindow("simple");

        glutDisplayFunc(display);
        glutKeyboardFunc(monitorKeyboard);

        GLenum err = glewInit(); 
        if (err == GLEW_OK) {
                glutMainLoop();
        }

}
void display(){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor4f(.16f,.72f,.08f,1.0f);


        triangle();


        glFlush();
        glutTimerFunc(1000,modifyTriangle,0);
}

void monitorKeyboard(unsigned char key, int x, int y){
    
         if(key == 27){ //ESC
        
                // Disable client side capability for normal operation
                glDisableClientState(GL_VERTEX_ARRAY);

                // bind with 0, so, switch back to normal pointer operation
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glDeleteBuffers(1, &VBOid);
                
                exit(0);
          }
}

void modifyTriangle(int value){
    
    triangleUpdate=true;
    
    //Map the array from the server memory (video card) to the local variable
                 mappedVertices = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
    
    mappedVertices[0]+=.01f;
    mappedVertices[3]+=.01f;
    mappedVertices[6]+=.01f;
    
    glUnmapBuffer(GL_ARRAY_BUFFER);
    glutPostRedisplay();

}

void triangle(){
    
        if(!triangleUpdate) {

               //1. Initialize the triangle using an array
                GLfloat trianglevertices[] = {
                        0.0f, .75f, 0.0f,
                        -0.75f, 0.0f, 0.0f,
                        0.75f, 0.0f, 0.0f
                };

                //2. Generate a Vertex Object ID for your array of vertices and bind it
                
                glGenBuffers(1, &VBOid);
                glBindBuffer(GL_ARRAY_BUFFER, VBOid);
                glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, trianglevertices, GL_DYNAMIC_DRAW);

        //3. Activate and specify pointer to vertex array
                glEnableClientState(GL_VERTEX_ARRAY);

                //4. Draw the primitive object
                glVertexPointer(3, GL_FLOAT, 0, 0);
                glDrawArrays(GL_TRIANGLES,0,6);
                       
        }else{
                //When for update just draw the primitive object
               glVertexPointer(3, GL_FLOAT, 0, 0);
               glDrawArrays(GL_TRIANGLES,0,6);
        }

}



