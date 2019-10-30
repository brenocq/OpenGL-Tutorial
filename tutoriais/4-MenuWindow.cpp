#include <GL/glut.h>
#include <iostream>
#include <math.h>
// Está cansado de ter que ficar digitando no terminal e ficar dando enter? Então esse tutorial é para você!!
// Nesse tutorial vamos aprender a criar uma janela de seleção que aparece quando você aperta com o botão direito
// (ela não é muito bonita mas dá pro gasto kk)

using namespace std;

#define windowWidth 600
#define windowHeight 600

// Opções do menu principal
#define RESET 1
// Opções do menu de cor
#define RED 1
#define GREEN 2
#define BLUE 3
#define PINK 4
#define PURPLE 5
// Opções do menu de velocidade
#define INCREASE 1
#define DECREASE 2


typedef struct _bixinho{
  float radius;
  float x;
  float y;
  float theta;
  float r,g,b;
  float vel;// Agora o struct tambem tem a velocidade do bixinho
}Bixinho;

// Nossos famigerados wilson, robson e dikson bixinhos estão de volta!
Bixinho wilson =     {0.07,   0,0,0,            0.8,0,0,  0.005};
Bixinho robson =     {0.05,   -0.3,-0.3,M_PI,   0,0.8,0,  -0.003};
Bixinho dikson =     {0.1,    -0.5,0,M_PI/2,    0,0,0.8,  0.007};

//---------- Protótipos de função ----------//
void draw();
void timer(int);
void rotateBixinho(Bixinho *bixinho, float angle);
void moveBixinho(Bixinho *bixinho, float distance);
void drawBixinho(Bixinho bixinho);

// Handlers de menu
void menuInit();// Inicia os menus
void mainMenuHandler(int choice);// Menu principal
void colorMenuHandler(int choice);// Menu secundário
void velocityMenuHandler(int choice);// Menu secundário

//------------------ Main -----------------//
int main(int argc, char** argv){
  srand(42);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Tutorial 4 - Menu Window");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  menuInit();// Inicializa o menu de seleção
  glutDisplayFunc(draw);
  glutTimerFunc(0, timer, 0);
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
  // Para mover os bixinhos
  moveBixinho(&wilson, wilson.vel);
  moveBixinho(&robson, robson.vel);
  moveBixinho(&dikson, dikson.vel);

  // Para girar os bixinhos
  rotateBixinho(&wilson, 0.02);
  rotateBixinho(&robson, 0.04);
  rotateBixinho(&dikson, -0.02);

  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, 0);
}

//------------------ Menu -----------------//
void menuInit(){
  // Create the menu options
  int colorSubMenu = glutCreateMenu(colorMenuHandler);
  glutAddMenuEntry("Red", RED);
  glutAddMenuEntry("Green", GREEN);
  glutAddMenuEntry("Blue", BLUE);
  glutAddMenuEntry("Pink", PINK);
  glutAddMenuEntry("Purple", PURPLE);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  int velocitySubMenu = glutCreateMenu(velocityMenuHandler);
  glutAddMenuEntry("Increase", INCREASE);
  glutAddMenuEntry("Decrease", DECREASE);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutCreateMenu(mainMenuHandler);
  glutAddSubMenu("Color", colorSubMenu);
  glutAddSubMenu("Velocity", velocitySubMenu);
  glutAddMenuEntry("Reset", RESET);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void mainMenuHandler(int choice){
  if(choice == RESET){
    wilson.x = 0;
    wilson.y = 0;

    robson.x = 0;
    robson.y = 0;

    dikson.x = 0;
    dikson.y = 0;
  }
}

void colorMenuHandler(int choice) {
  // Muda a cor dos bixinhos para a selecionada
  float r=0,g=0,b=0;
	switch(choice) {
    case RED:
      r = 1;
      g = 0;
      b = 0;
      break;
		case GREEN:
      r = 0;
      g = 1;
      b = 0;
			break;
    case BLUE:
      r = 0;
      g = 0;
      b = 1;
			break;
    case PINK:
      r = 1;
      g = 0;
      b = 1;
			break;
    case PURPLE:
      r = 0.6;
      g = 0;
      b = 0.6;
			break;
	}

  wilson.r = r;
  wilson.g = g;
  wilson.b = b;

  robson.r = r;
  robson.g = g;
  robson.b = b;

  dikson.r = r;
  dikson.g = g;
  dikson.b = b;
}

void velocityMenuHandler(int choice) {
  // Aumenta ou diminui a velocidade dos bixinhos
	switch(choice) {
    case INCREASE:
      wilson.vel*=1.2;
      robson.vel*=1.2;
      dikson.vel*=1.2;
      break;
		case DECREASE:
      wilson.vel*=0.83;
      robson.vel*=0.83;
      dikson.vel*=0.83;
			break;
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
  bixinho->x = bixinho->x<-1 ? 1 : bixinho->x;
  bixinho->y = bixinho->y<-1 ? 1 : bixinho->y;

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
