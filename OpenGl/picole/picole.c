#include <GL/glut.h>
#include <GL/glu.h>

void initPicole(void){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void picoleFunc(void){


    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2i(248, 250);
        glVertex2i(251, 250);
        glVertex2i(248, 100);
        glVertex2i(251, 100);
    glEnd();

    glColor3f(.0, 1.0, .0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(250, 100);
        glVertex2i(250, 150);
    glEnd();

    glFlush();
}

int main (int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Picole");

    initPicole();

    glutDisplayFunc(picoleFunc);
    
    glutMainLoop();
    
}