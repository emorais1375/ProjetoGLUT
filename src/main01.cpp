/*
 * Primeiro Programa em GLUT OpenGL
 *
 * Descrição: Abre uma janela com título e fundo preto.
 *
 * Autor: Eduardo Morais
 * Ano: 2017_2
 * Disciplina: PDI
 * Prof.: Ricardo Barbosa
 */

#include <stdio.h>
#include <GL/glut.h>

void Desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void Inicializa ()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f); // Cor de fundo da janela
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Primeiro Programa"); // Titulo da janela
    glutDisplayFunc(Desenha);
    Inicializa();
    glutMainLoop();
}
