#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>
// Estaremos utilizando a classe vector neste tutorial
// Se você não sabe como ela funciona olhe aqui: http://www.cplusplus.com/reference/vector/vector/

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

// Estaremos utilizando um vector de bixinhos
vector<Bixinho> bixinhos;

//---------- Protótipos de função ----------//
void draw();
void timer(int);
void mouse(int button, int state, int x, int y);// Função para receber os cliques do mouse
void rotateBixinho(Bixinho *bixinho, float angle);
void moveBixinho(Bixinho *bixinho, float distance);
void drawBixinho(Bixinho bixinho);

//------------------ Main -----------------//
int main(int argc, char** argv){
  srand(42);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Tutorial 3 - Mouse Click");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutDisplayFunc(draw);
  glutTimerFunc(0, timer, 0);
  glutMouseFunc(mouse);// É chamada quando ocorre cliques na tela
  glutMainLoop();

  return 0;
}

//------------------ Draw -----------------//
void draw(){
  glClear(GL_COLOR_BUFFER_BIT);

  // Desenha cada bixinho do vetor
  for(int i=0;i<int(bixinhos.size());i++){
    drawBixinho(bixinhos[i]);
  }

  glutSwapBuffers();
}

//------------------ Timer -----------------//
void timer(int){
  // Move cada bixinho do vetor
  for(int i=0;i<int(bixinhos.size());i++){
    moveBixinho(&bixinhos[i], 0.005);
    rotateBixinho(&bixinhos[i], 0.02);
  }


  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, 0);
}

//------------------ Mouse -----------------//
void mouse(int button, int state, int x, int y)
{
  if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  {
    float mouseX, mouseY;
    // Converte a entrada para pontos (x,y) na tela
    mouseX = 2*((float(x)/windowWidth)-0.5);
    mouseY = -2*((float(y)/windowHeight)-0.5);

    float radius = 0.05 + (rand()%50)/1000.0f;
    float theta = (rand()%628)/100.0f;
    float r = (rand()%100)/100.0f;
    float g = (rand()%100)/100.0f;
    float b = (rand()%100)/100.0f;

    Bixinho newBixinho = {radius, mouseX, mouseY, theta, r, g, b};

    bixinhos.push_back(newBixinho);
  }
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
