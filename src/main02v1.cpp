/*
 * Segundo Programa em GLUT OpenGL
 *
 * Descrição: Abre uma janela com título, fundo preto e um quadrado colorido.
 *
 * Autor: Eduardo Morais
 * Ano: 2017_2
 * Disciplina: PDI
 * Prof.: Ricardo Barbosa
 */

#include <GL/glut.h>
#include <stdlib.h>

#define W_HEIGHT 256
#define W_WIDTH 256

void display(void);
void key(unsigned char key, int x, int y);

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (W_WIDTH, W_HEIGHT);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-W_WIDTH)/2,
                       (glutGet(GLUT_SCREEN_HEIGHT)-W_HEIGHT)/2);

    glutCreateWindow ("GLUT Shapes");

    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
    glOrtho (0, 1, 0, 1, -1 ,1);

    glutDisplayFunc(display);
    glutKeyboardFunc(key);

    glutMainLoop();

    return 0;
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex2f(0.25,0.25);
        glVertex2f(0.75,0.25);
        glVertex2f(0.75,0.75);
        glVertex2f(0.25,0.75);
    glEnd();
    glFlush();
}

void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
            exit(0);
            break;
    }

    glutPostRedisplay();
}
