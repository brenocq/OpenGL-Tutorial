#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

#define windowWidth 600
#define windowHeight 600

typedef struct _bixinho{
  float radius;
  float x;
  float y;
  float theta;
  float r,g,b;
}Bixinho;

// Cria os bixinhos: (radius) (x,y,theta)       (r,g,b)
Bixinho wilson =     {0.07,   0,0,0,            0.8,0,0};
Bixinho robson =     {0.05,   -0.3,-0.3,M_PI,   0,0.8,0};
Bixinho dikson =     {0.1,    -0.5,0,M_PI/2,    0,0,0.8};

//---------- Protótipos de função ----------//
void draw();// Função para desenhar
void timer(int);// Função de loop
void rotateBixinho(Bixinho *bixinho, float angle);// Girar bixinho
void moveBixinho(Bixinho *bixinho, float distance);// Mover bixinho
void drawBixinho(Bixinho bixinho);// Desenhar bixinho

//------------------ Main -----------------//
int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Tutorial 2 - Animation");
  glClearColor(1.0, 1.0, 1.0, 1.0);// Limpa a tela (red, green, blue, alpha)
  glutDisplayFunc(draw);// Define qual função irá desenhar
  glutTimerFunc(0, timer, 0);// Define qual será a função de loop
  glutMainLoop();

  return 0;
}

//------------------ Draw -----------------//
void draw(){
  glClear(GL_COLOR_BUFFER_BIT);

  drawBixinho(wilson);
  drawBixinho(robson);
  drawBixinho(dikson);

  glutSwapBuffers();
}

//------------------ Timer -----------------//
void timer(int){
  // Essa função é chamada em loop, é aqui que realizaremos as animações

  // Tenta ficar mudando os parâmetros para ver o que muda! :)

  // Para mover os bixinhos
  moveBixinho(&wilson, 0.005);
  moveBixinho(&robson, -0.003);
  moveBixinho(&dikson, 0.007);

  // Para girar os bixinhos
  rotateBixinho(&wilson, 0.02);
  rotateBixinho(&robson, 0.04);
  rotateBixinho(&dikson, -0.02);

  // Executa a função draw para desenhar novamente
  glutPostRedisplay();

  // O primeiro parâmetro define de quanto em quanto tempo em milissegundos timer será chaamdo
  // Eu coloquei 1000/60 para definir que vai atualizar a 60hz
  glutTimerFunc(1000/60, timer, 0);// Garante que esta função será chamada de novo
}


//----------------------------------------------//
//----------- Funções para o bixinho -----------//
//----------------------------------------------//
void rotateBixinho(Bixinho *bixinho, float angle){
    bixinho->theta+=angle;
}

void moveBixinho(Bixinho *bixinho, float distance){
  // Para mover para onde ele está olhando (na direção theta)
  bixinho->x = bixinho->x + distance*cos(bixinho->theta);
  bixinho->y = bixinho->y + distance*sin(bixinho->theta);

  // Impede que o wilson saia da tela
  bixinho->x = bixinho->x>1 ? -1 : bixinho->x;
  bixinho->y = bixinho->y>1 ? -1 : bixinho->y;

}

void drawBixinho(Bixinho bixinho){
  // Função para desenhar o bixinho
  float radius = bixinho.radius;
  float x = bixinho.x;
  float y = bixinho.y;
  float theta = bixinho.theta;

  //----- Desenha corpo do bixinho -----//
  glColor3f(bixinho.r, bixinho.g, bixinho.b);// Bixinho verde
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i+=5) {
    glVertex2d( radius*cos(i/180.0*M_PI) + x, radius*sin(i/180.0*M_PI) + y);
  }
  glEnd();

  //----- Desenha olho direito do bixinho -----//
  float eyeRadius = radius/8;
  float eyeDist = M_PI/6;

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i+=5) {
    float shiftX = radius/2*cos(theta-eyeDist);
    float shiftY = radius/2*sin(theta-eyeDist);
    glVertex2d( eyeRadius*cos(i/180.0*M_PI) + x + shiftX, eyeRadius*sin(i/180.0*M_PI) + y + shiftY);
  }
  glEnd();

  //----- Desenha olho esquerdo do bixinho -----//
  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i+=5) {
    float shiftX = radius/2*cos(theta+eyeDist);
    float shiftY = radius/2*sin(theta+eyeDist);

    glVertex2d( eyeRadius*cos(i/180.0*M_PI) + x + shiftX, eyeRadius*sin(i/180.0*M_PI) + y + shiftY);
  }
  glEnd();
}
