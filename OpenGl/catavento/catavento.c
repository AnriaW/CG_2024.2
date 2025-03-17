#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

float angulo = 0.0f;
int sentido = 0;

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(248, 250);
    glVertex2i(251, 250);
    glVertex2i(251, 100);
    glVertex2i(248, 100);
    glEnd();
    
    glPushMatrix();
    glTranslatef(250, 250, 0);
    glRotatef(angulo, 0, 0, 1);
    glTranslatef(-250, -250, 0);
    
    int largura = 50;
    int altura = 52;
    
    GLfloat cores[4][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 1.0, 0.0}
    };
    
    glColor3fv(cores[0]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 - largura/2, 250 + altura);
    glVertex2i(250, 250);
    glVertex2i(250 + largura/2, 250 + altura);
    glEnd();
    
    glColor3fv(cores[1]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 + largura, 250 - altura/2);
    glVertex2i(250, 250);
    glVertex2i(250 + largura, 250 + altura/2);
    glEnd();
    
    glColor3fv(cores[2]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 - altura/2, 250 - largura);
    glVertex2i(250, 250);
    glVertex2i(250 + altura/2, 250 - largura);
    glEnd();
    
    glColor3fv(cores[3]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 - largura, 250 - altura/2);
    glVertex2i(250, 250);
    glVertex2i(250 - largura, 250 + altura/2);
    glEnd();
    
    glPopMatrix();
    glFlush();
}

void timer(int value){
    if (sentido == 0){
        angulo += 10.0f;
    } else {
        angulo -= 10.0f;
    }
    if (angulo >= 360.0f || angulo <= -360.0f) {
        angulo = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

void keyboard(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        sentido = 1; 
    } else if (key == GLUT_KEY_LEFT) {
        sentido = 0;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Catavento");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(50, timer, 0);
    glutSpecialFunc(keyboard); 
    glutMainLoop();
}
