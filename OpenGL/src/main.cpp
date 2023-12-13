#include <GL/glew.h>
#include <GL/freeglut.h>

#include "cyCodeBase/cyGL.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glVertex2f(0.0, 1.0);

    glColor3f(0.0, 1.0, 0.0); // Green color
    glVertex2f(-1.0, -1.0);

    glColor3f(0.0, 0.0, 1.0); // Blue color
    glVertex2f(1.0, -1.0);
    glEnd();

    glFlush();
}

void debugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    // Your debug callback implementation here
    // This function will be called when OpenGL generates debug messages
    // You can handle/debug the messages received here
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitContextFlags(GLUT_DEBUG);
    glutCreateWindow("OpenGL");

    // Initialize GLEW 
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        return -1;
    }

    // Register display function
    glutDisplayFunc(display);

    // Enable debugging by registering the debug callback function
    CY_GL_REGISTER_DEBUG_CALLBACK; 

    glutMainLoop();
    return 0;
}