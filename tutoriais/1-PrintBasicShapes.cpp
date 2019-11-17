#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include <iostream>
#include <math.h>

using namespace std;

#define windowWidth 600
#define windowHeight 600

// Função principal para desenhar
void draw();

// Funções para desenhar polígonos
void retangle(float x, float y, float w, float h);
void triangle(float x, float y, float h, float b);
void circle(float x, float y, float radius);
void strangePolygon(float x, float y);
void anotherStrangePolygon(float x, float y);

int main(int argc, char** argv){
  //----- Criar janela -----//
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Tutorial 1 - Print Basic Shapes");
  glClearColor(1.0, 1.0, 1.0, 1.0);// Limpa a tela (red, green, blue, alpha)
  glutDisplayFunc(draw);// Define qual função irá desenhar
  glutMainLoop();

  return 0;
}

void draw(){
  // Importante: Somente será desenhado o que estiver entre glClear e glEnd
  glClear(GL_COLOR_BUFFER_BIT);

  // A tela padrão do OpenGL tem suas coordenadas X e Y de -1 até 1
  // Coordenada (-1 -1) é o canto inferior esquerdo
  // Coordenada (-1 1) é o canto superior esquerdo
  // Coordenada (0 0) é o centro da tela

  retangle(0, 0, 0.1, 0.2);
  triangle(0.5, 0.5, 0.4, 0.5);
  circle(-0.5, 0.5, 0.1);
  strangePolygon(-0.5, -0.5);
  anotherStrangePolygon(0.5, -0.5);

  glutSwapBuffers();
}

//------------------------------//
//--------- RECTANGLE ----------//
//------------------------------//

void retangle(float x, float y, float w, float h){
  // Vai desenhar um polígono de 4 vértices

  glColor3f(0, 0, 1);// Define que será desenhar um objeto azul
  glBegin(GL_POLYGON);// Fala para o OpenGL que os próximos pontos serão para desenhar um polígono

  // Adicionada cada vértice do retângulo
  glVertex2d( x-w/2, y-h/2);
  glVertex2d( x-w/2, y+h/2);
  glVertex2d( x+w/2, y+h/2);
  glVertex2d( x+w/2, y-h/2);

  glEnd();// Fala para o OpenGL que terminou de enviar os vértices do polígono
}

//------------------------------//
//---------- TRIANGLE ----------//
//------------------------------//

void triangle(float x, float y, float h, float b){
  // O mais polígono mais trivial: 3 vertíces

  glColor3f(1, 0, 1);// Define que será desenhar um objeto roxo
  glBegin(GL_POLYGON);

  // Adicionada cada vértice do triângulo
  glVertex2d( x-b/2, y-h/2);
  glVertex2d( x+b/2, y-h/2);
  glVertex2d( x, y+h/2);

  glEnd();// Fala para o OpenGL que terminou de enviar os vértices do polígono
}

//------------------------------//
//----------- CIRCLE -----------//
//------------------------------//

void circle(float x, float y, float radius){
  // Um circulo é desenhado como um polígono de muitos pontos

  glColor3f(0, 1, 0);// Define que será desenhar um objeto verde
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i+=5) {
    // Adicionada cada vértice 2D do circulo
    glVertex2d( radius*cos(i/180.0*M_PI) + x, radius*sin(i/180.0*M_PI) + y);
  }
  glEnd();
}

//------------------------------//
//----------- STRANGE ----------//
//------------------------------//
void strangePolygon(float x, float y){

  glColor3f(0, 0, 0);// Define que será desenhar um objeto preto

  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i+=10) {
    glVertex2d( 0.2*cos(i/180.0*M_PI) + x + cos(i)*0.15,  0.2*sin(i/180.0*M_PI) + y + sin(i)*0.15);
  }
  glEnd();

}

void anotherStrangePolygon(float x, float y){
  glColor3f(1, 1, 0);// Define que será desenhar um objeto amarelo

  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i+=10) {
    glVertex2d( 0.3*cos(i/180.0*M_PI) + x,  0.3*sin(i/180.0*M_PI) + y);
    i+=10;
    glVertex2d( 0.1*cos(i/180.0*M_PI) + x,  0.1*sin(i/180.0*M_PI) + y);
  }
  glEnd();
}
