#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

int frame = 0;
int sentido = 0;

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(248, 250);
    glVertex2i(251, 250);
    glVertex2i(251, 100);
    glVertex2i(248, 100);
    glEnd();
    
    int largura = 50;
    int altura = 52;
    
    GLfloat cores[4][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 1.0, 0.0}
    };
    
    int ordem[4] = {0, 1, 2, 3};
    int novaOrdem[4] = {0, 2, 1, 3};
    
    for(int i = 0; i < 4; i++){
        ordem[i] = novaOrdem[(i + frame) % 4];
    }
    
    glColor3fv(cores[ordem[0]]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 - largura/2, 250 + altura);
    glVertex2i(250, 250);
    glVertex2i(250 + largura/2, 250 + altura);
    glEnd();
    
    glColor3fv(cores[ordem[1]]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 + largura, 250 - altura/2);
    glVertex2i(250, 250);
    glVertex2i(250 + largura, 250 + altura/2);
    glEnd();
    
    glColor3fv(cores[ordem[2]]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 - altura/2, 250 - largura);
    glVertex2i(250, 250);
    glVertex2i(250 + altura/2, 250 - largura);
    glEnd();
    
    glColor3fv(cores[ordem[3]]);
    glBegin(GL_TRIANGLES);
    glVertex2i(250 - largura, 250 - altura/2);
    glVertex2i(250, 250);
    glVertex2i(250 - largura, 250 + altura/2);
    glEnd();
    
    glFlush();
}

void timer(int value){
    if (sentido == 0){
        frame = (frame + 1) % 4;
    }
    else{
        frame = (frame + 3) % 4;
    }
    glutPostRedisplay();
    glutTimerFunc(500, timer, 0);
}

void keyboard(unsigned char key, int x, int y){
    if (key == 'a' || key == 'A' || key == '0') {
        sentido = 0; 
    } else if (key == 'h' || key == 'H' || key == '1') {
        sentido = 1; 
    }
}

int main(int argc, char **argv){
    printf("\nPressione 'A' ou '0' para girar no sentido anti-horario e 'H' ou '1'para horario.\n\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Catavento Giratório");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(500, timer, 0);
    glutKeyboardFunc(keyboard); // funcao para mudar o sentido do catavento
    glutMainLoop();
}