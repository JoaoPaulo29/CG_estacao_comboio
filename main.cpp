#include "funcoes.h"


int main(void){
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(1024,650);
 glutInitWindowPosition(300,100);
 glutCreateWindow("NVINDA DIA NZAMBE");
 glutDisplayFunc(desenhar);
 glutKeyboardFunc(movimentoDoCarro);
 glutTimerFunc(0,timer,0);
 glutTimerFunc(0,semaforoTime,0);
 glClearColor(1,1,1,1);
 glutMainLoop();
 return 0;


}
