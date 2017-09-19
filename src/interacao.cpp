// Interacao.c - Isabel H. Manssour
// Um programa OpenGL simples que desenha um  quadrado em
// uma janela GLUT de acordo com interações do usuário.
// Este código está baseado nos exemplos 
// disponíveis no livro "OpenGL SuperBible", 
// 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// Constantes
#define QUADRADO 1
#define TRIANGULO 2
#define CIRCULO   3

// Variáveis
char texto[30];
GLfloat win, r=1, g=0, b=0, xf, yf;
GLint tx=0, ty=0,rx=0,ry=0, view_w, view_h, primitiva= QUADRADO;


// Função callback chamada para fazer o desenho
void DesenhaQ(void)
{
    // glMatrixMode(GL_MODELVIEW);
     //glLoadIdentity();
                   
     //glClear(GL_COLOR_BUFFER_BIT);
     // Desenha um retângulo preenchido com a cor corrente
     glBegin(GL_POLYGON);
               glVertex2f(0.0f, 0.0f);
               glVertex2f(xf, 0.0f);
               glVertex2f(xf, yf);
               glVertex2f(0.0f, yf);               
     glEnd();
     glFlush();
}
//Desenha triangulo

void DesenhaT(void)
{
     
     glBegin(GL_TRIANGLES);
               glVertex2f(-25.0f, -25.0f);
               glVertex2f(0.0f, 25.0f);
               glVertex2f(25.0f, -25.0f);              
     glEnd();
}
//Desenha circulo

void DesenhaC(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.141592;
    
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount;i++) { 
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)), 
            y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}
// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT);
     
     // Define a cor corrente
     glColor3f(r,g,b);
    
     
     // Desenha uma primitiva     
     switch (primitiva) {
            case QUADRADO:
                   	glTranslatef(tx, ty, 0);  // Translada
                   	glRotatef (rx,0,0,1);
                   	DesenhaQ();
                   	break;
            case TRIANGULO:
			glTranslatef(tx, ty, 0); // Translada
			glRotatef (rx,0,0,1);
			DesenhaT();
			break;
            case CIRCULO:   
                   	glTranslatef(tx, ty, 0); // Translada           
                   	DesenhaC(0.0f,0.0f,30.0f);                       
                        break;
     }

     // Exibe a posição do mouse na janela
     glColor3f(1.0f,1.0f,1.0f);
     
     glutSwapBuffers();
}
// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    xf=50.0f;
    yf=50.0f;
    win=250.0f;
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{ 
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                   

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    
    if(key == 'a') {
           win -= 20;
    }
    else if(key == 's') {
           win += 20;
    }
    if (key == 'q') 
    {
        exit(0);
    }   
				
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
    glutPostRedisplay();
    
} 

// Função callback chamada para gerenciar eventos do teclado   
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y)
{
    switch (key) {
           
            case GLUT_KEY_UP:
                    ty+=10;
                     break; 
            case GLUT_KEY_DOWN:
                    ty-=10;
                     break; 
    	    case GLUT_KEY_LEFT: 
    	            tx-=10;
                     break; 
   	        case GLUT_KEY_RIGHT:  
   	                tx+=10;
                     break;    
           case GLUT_KEY_PAGE_UP: // Rotate on x axis
                    rx -= 2.0f;   
                     break;
           case GLUT_KEY_PAGE_DOWN:// Rotate on x axis (opposite)
                    rx+= 2.0f;
                      break;                     
    }
    glutPostRedisplay();
}


    

// Gerenciamento do menu com as opções de cores           
void MenuCor(int op)
{
   switch(op) {
            case 0:
                     r = 1.0f;
                     g = 0.0f;
                     b = 0.0f;
                     break;
            case 1:
                     r = 0.0f;
                     g = 1.0f;
                     b = 0.0f;
                     break;
            case 2:
                     r = 0.0f;
                     g = 0.0f;
                     b = 1.0f;
                     break;
    }
    glutPostRedisplay();
}           

// Gerenciamento do menu com as opções de cores           
void MenuPrimitiva(int op)
{
   switch(op) {
            case 0:
                     primitiva = QUADRADO;
                     break;
            case 1:
                     primitiva = TRIANGULO;
                     break;
            case 2:
                     primitiva = CIRCULO;
                     break;
    }
    glutPostRedisplay();
}  
// Gerenciamento do menu principal           
void MenuPrincipal(int op)
{
}
// Criacao do Menu
void CriaMenu() 
{
    int menu,submenu1,submenu2;

    submenu1 = glutCreateMenu(MenuCor);
    glutAddMenuEntry("Vermelho",0);
    glutAddMenuEntry("Verde",1);
    glutAddMenuEntry("Azul",2);

    submenu2 = glutCreateMenu(MenuPrimitiva);
    glutAddMenuEntry("Quadrado",0);
    glutAddMenuEntry("Triangulo",1);
    glutAddMenuEntry("Circulo",2);

    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Cor",submenu1);
    glutAddSubMenu("Primitivas",submenu2);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            CriaMenu();
         
    glutPostRedisplay();
}

                      
// Programa Principal 
int main(int argc, char *argv[])
{

     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);     
     glutInitWindowSize(350,300);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Exemplo de Menu e Exibicao de Caracteres");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutMouseFunc(GerenciaMouse);
     glutKeyboardFunc(GerenciaTeclado);
     glutSpecialFunc(TeclasEspeciais); 
     Inicializa();
     glutMainLoop();
}
