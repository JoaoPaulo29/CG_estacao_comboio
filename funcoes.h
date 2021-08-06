#ifndef FUNCOES_H
#define FUNCOES_H
#include <math.h>
#include "headers.h"

void movimentoDoCarro(unsigned char tecla,GLint x, GLint y){
    switch(tecla){
        case 97://a
            velocidade+=0.1;
            break;
        case 100://d
            if(travadoCarro==0){
                if(velocidade<=0){
                    velocidade=0.1;
                }else velocidade-=0.1;
            }
            break;
        case 98://b
            velocidade1+=0.1;
            break;
        case 101://e
            if(travadoCarro==0){
                if(velocidade1<=0){
                    velocidade1=0.1;
                }else velocidade1-=0.1;
            }
            break;
        case 103://g
            if(janela==0){
                janela=1;
            }else janela=0;
            break;
        case 104://h
            if(porta==0){
                porta=1;
            }else porta=0;
            break;
        case 105://i
            if(luzes==1)
                luzes=0;
            else luzes=1;
            break;
        case 106://j
            if(luz==1)
                luz=0;
            else luz=1;
            break;
        case 32://espaço
            if(noite==1){
                noite=0;
            }else noite=1;
            break;
        case 102://f
            if(lua==0){
                lua=1;
            }else lua=0;
    }
    desenhar();
}
void escrever(float x, float y, char *string, void *font){
    int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen(string); i++){
        glutBitmapCharacter(font, string[i]);
    }
}
void circulo(float x, float y, float r, float g, float b,float alfa, float mult){
    int i=0;
    float teta;
    glBegin(GL_POLYGON);
    glColor4f(r,g,b,alfa);
    for(i=0; i<360; i++){
        teta=i*3.142/180;
        glVertex2f(x+mult*cos(teta),y-mult*sin(teta));
    }
   glEnd();
}
void ceu(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa){
    if (noite == 1){
        quadrado2f(x1,x2,y1,y2,r-0.7,g-0.7,b-0.7,alfa);
        if(lua==1){
            circulo(x2-3,y2-2.4,r,g,b,alfa,0.8);
            circulo(x2-3.5,y2-2.4,r-0.7,g-0.7,b-0.7,alfa,0.8);
         }else{
            circulo(x2-3,y2-2.4,r,g,b,alfa,1);
         }

     }else {
         quadrado2f(x1,x2,y1,y2,r-r,g,b,alfa);
         circulo(x1+3,y2-2.4,r,g,b-b,alfa,1);
     }
     nuvens(nuven,5.6,0.9,0.9,0.9,1,0.8);
     nuvens(nuven2,5.6,0.9,0.9,0.9,1,0.8);
}
void jardim(){
    glBegin(GL_POLYGON);
    glColor3f(0,0.40,0);
    glVertex2f(-12,1);
    glVertex2f(-12,-8);
    glVertex2f(12,-8);
    glVertex2f(12,1);
    glVertex2f(10,1.8);
    glVertex2f(8,2);
    glVertex2f(6,2.8);
    glVertex2f(-3,3);
    glVertex2f(-5,3);
    glVertex2f(-7,2.8);
    glVertex2f(-9,2);
    glVertex2f(-11,1.8);

glEnd();
}
void casa(float x1,float x2, float y1,float y2){
    //CASA
    //casa(-3,3,1.5,6);
    quadrado2f(x1,x2,y1,y2,1,0,0,1);//QUADRADO PRINCIPAL DA CASA OU  SEJA AS PAREDES
    if(janela==0){
        quadrado2f((x1+2),-(x2-0.5),(y1+1.7),(y2-1.5),0,0,0,1);//JANELA ESQUERDA
        quadrado2f(-(x1+2),(x2-0.5),(y1+1.7),(y2-1.5),0,0,0,1);//JANELA DIREITA
    }else{
        quadrado2f((x1+2),-(x2-0.5),(y1+1.7),(y2-1.5),1,1,0,1);//JANELA ESQUERDA
        quadrado2f(-(x1+2),(x2-0.5),(y1+1.7),(y2-1.5),1,1,0,1);//JANELA DIREITA
        poligono4f((x1+1.5),(x1+1.5),-(x2-0.5),-(x2-0.5),(y1+1.7),(y1+1.7),(y2-1.5),(y2-2),0,0,0,1);
        poligono4f((x2-0.5),(x2-0.5),(x2-1.5),(x2-1.5),(y1+1.7),(y1+1.7),(y2-2),(y2-1.5),0,0,0,1);
    }
    if(porta==0){
        quadrado2f((x1+2.3),(x2-2.3),y1,(y2-1.5),1,1,0,1);//PORTA
        poligono4f((x1+2.3),(x1+2.3),(x2-2.6),(x2-2.6),(y1),(y1),(y2-2),(y2-1.5),0,0,0,1);
    }else quadrado2f((x1+2.3),(x2-2.3),y1,(y2-1.5),0,0,0,1);//PORTA

    if(noite==01){
        glColor3f(1,1,1);
    }else glColor3f(0,0,0);
    escrever(-1.5,5,"NVINDA DIA NZAMBE",GLUT_BITMAP_8_BY_13);
}
void poligono4f(float x1, float x2,float x3, float x4,float y1, float y2,float y3,float y4, float r, float g, float b,float alfa){
    glBegin(GL_POLYGON);
    glColor4f(r,g,b,alfa);
    glVertex2f(x1,y4);
    glVertex2f(x2,y2);
    glVertex2f(x3,y1);
    glVertex2f(x4,y3);
    glEnd();
}
void triangulo3f(float x1, float x2, float x3, float y1, float y2,float y3,float r,float g,float b,float alfa){
    glBegin(GL_TRIANGLE_STRIP);
    glColor4f(r,g,b,alfa);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();

}
void varanda(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa){
    //varanda(7,8,-0.2,1.50.86,0.86,0.86,1)
    quadrado2f(-x2+0.2,(-x2+0),-0.2,1.2,r,g-g,b,alfa);
    quadrado2f(-x2+1,(-x2+1.2),1.38,2.9,r,g-g,b,alfa);
    quadrado2f(-x2+2,(-x2+2.2),1.38,2.7,r,g-g,b,alfa);
    quadrado2f(-x2+3,(-x2+3.2),1.38,2.7,r,g-g,b,alfa);
    quadrado2f(-x2+4,(-x2+4.2),1.38,2.9,r,g-g,b,alfa);
    poligono4f(x1,x2,x2-0.2,x1-0.2,1,1,2.68,2.7,r,b-b,b,alfa);
    quadrado2f(x2-0.2,(x2+0),-0.2,1.2,r,g-g,b,alfa);
    quadrado2f(x2-1,(x2-1.2),1.38,2.9,r,g-g,b,alfa);
    quadrado2f(x2-2,(x2-2.2),1.38,2.7,r,g-g,b,alfa);
    quadrado2f(x2-3,(x2-3.2),1.38,2.7,r,g-g,b,alfa);
    quadrado2f(x2-4,(x2-4.2),1.38,2.9,r,g-g,b,alfa);
    quadrado2f(-x2+1,(x2-1),2.5,2.7,r,g-g,b,1);
    quadrado2f(-x2+1,(x2-1),1.9,2.1,r,g-g,b,1);
    poligono4f(-x1,-x2,-x1-0.8,-x1+0.2,1,1,2.68,2.7,r,b-b,b,alfa);
    if(noite==0){
        circulo(x2-0.15,1.3,1.3,1,1,1,0.25);
        circulo(x2-4.1,3,1,1,1,1,0.25);
        circulo(x2-1.1,3,1,1,1,1,0.25);
        circulo(-x2+0.15,1.3,1,1,1,1,0.25);
        circulo(-x2+4.1,3,1,1,1,1,0.25);
        circulo(-x2+1.1,3,1,1,1,1,0.25);
    }else{
        circulo(x2-0.15,1.3,1.3,1,0,1,0.25);
        circulo(x2-4.1,3,1,1,0,1,0.25);
        circulo(x2-1.1,3,1,1,0,1,0.25);
        circulo(-x2+0.15,1.3,1,1,0,1,0.25);
        circulo(-x2+4.1,3,1,1,0,1,0.25);
        circulo(-x2+1.1,3,1,1,0,1,0.25);
    }


}
void passeioDaEstacao(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa){
    //PASSEIO  7,8,-0.2,1.5
    poligono4f(-7,-8,8,7,-0.2,-0.2,1.5,1.5,r,b,b,alfa);//PASSEIO
    //FALTA VER BEM AS CORES PARA ANALISAR
    quadrado2f(-x2,x2,y1,0.5-y2,r,0,b,1);//DEGRAU DO PASSEIO
    quadrado2f(-x2+0.5,(x2-0.5),0.5-y2,y1-0.3,r,g,b,1);
    quadrado2f(-x2+1.5,(-x2+2.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);
    quadrado2f(-x2+2.5,(-x2+3.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);
    quadrado2f(-x2+3.6,(-x2+4.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);

    quadrado2f(-x2+6.5,(-x2+7.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);
    quadrado2f(-x2+7.5,(-x2+8.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);
    quadrado2f(-x2+8.6,(-x2+9.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);

    quadrado2f(-x2+11.5,(-x2+12.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);
    quadrado2f(-x2+12.5,(-x2+13.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);
    quadrado2f(-x2+13.6,(-x2+14.4),0.46-y2,y1-0.4,0.3,0.3,0.3,0.3);
}
void escada(float x1, float x2,float r,float g,float b,float alfa,float sub){
     //ESCADAS
    //escada(-3,3,1,1,1,1,1)
    poligono4f(x1,x1-0.2,x2+0.2,x2,1.3,1.3,1.5,1.5,r-sub,g-sub,b-sub,alfa);
    quadrado2f(x1-0.2,x2+0.2,1,1.3,r,g-sub,b-sub,alfa);
    poligono4f(x1-0.2,x1-0.4,x2+0.4,x2+0.2,0.8,0.8,1,1,r-sub,g-sub,b-sub,alfa);
    quadrado2f(x1-0.4,x2+0.4,0.6,0.8,r,g-sub,b-sub,alfa);
    poligono4f(x1-0.4,x1-0.6,x2+0.6,x2+.4,0.4,0.4,0.6,0.6,r-sub,g-sub,b-sub,alfa);
    quadrado2f(x1-0.6,x2+0.6,0.2,0.4,r,g-sub,b-sub,alfa);
    poligono4f(x1-0.6,x1-0.8,x2+0.8,x2+0.6,0,0,0.2,0.2,r-sub,g-sub,b-sub,alfa);
    quadrado2f(x1-0.8,x2+0.8,-0.2,0,r,g-sub,b-sub,alfa);
}
void bancos(float x1, float x2,float x3, float x4,float r,float g,float b,float alfa,float sub){
    //BANCO DIREITO 1
    //bancos(3.7,4.5,5.5,6.5,1,1,1,1)
    poligono4f(x1,x1,x1+0.2,x1+0.2,0.5,0.75,1.3,1.3,r-sub,g-sub,b-sub,alfa);//PERNO 1
    poligono4f(x2,x2,x2+0.2,x2+0.2,0.5,0.75,1,1.3,r-sub,g-sub,b-sub,alfa);//PERNO 2
    poligono4f(x1-0.2,x1,x2+0.4,x2+0.2,1,1,1.3,1.3,r,g-sub,b-sub,alfa);//ASSENTO
    //BANCO DIREITO 2
    poligono4f(x3,x3,x3+0.2,x3+0.2,0.5,0.75,1.3,1.3,r-sub,g-sub,b-sub,alfa);//PERNO ESQUERDO
    poligono4f(x4-0.2,x4-0.2,x4,x4,0.5,0.75,1,1.3,r-sub,g-sub,b-sub,alfa);//PERNO DIREITO
    poligono4f(x3-0.2,x3,x4+0.2,x4,1,1,1.3,1.3,r,g-sub,b-sub,alfa);//ASSENTO
    //BANCO ESQUERDO 1
    poligono4f(-x1,-x1,-(x1+0.2),-(x1+0.2),0.5,0.75,1.3,1.3,r-sub,g-sub,b-sub,alfa);//PERNO 1
    poligono4f(-x2,-x2,-(x2+0.2),-x2-0.2,0.5,0.75,1,1.3,r-sub,g-sub,b-sub,alfa);//PERNO 2
    poligono4f(-(x1-0.2),-x1,-x2-0.4,-x2-0.2,1,1,1.3,1.3,r,g-sub,b-sub,alfa);//ASSENTO
    //BANCO ESQUERDO 2
    poligono4f(-x3,-x3,-x3-0.2,-x3-0.2,0.5,0.75,1.3,1.3,r-sub,g-sub,b-sub,alfa);//PERNO ESQUERDO
    poligono4f(-x4+0.2,-x4+0.2,-x4,-x4,0.5,0.75,1,1.3,r-sub,g-sub,b-sub,alfa);//PERNO DIREITO
    poligono4f(-x3+0.2,-x3,-x4-0.2,-x4,1,1,1.3,1.3,r,g-sub,b-sub,alfa);//ASSENTO
}
void linhas2f(float x1,float x2,float y1,float y2,float r,float g,float b,float alfa){
    glBegin(GL_LINE_LOOP );
    glColor4f(r,g,b,alfa);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
void estrada(float x1,float x2,float y1,float y2){
     //ESTRADA
    //estrada(-12,12,-5.5,-1,1,1,1,1);
    quadrado2f(x1,x2,y1,y2,0,0,0,1);
    //LINHAS BRANCAS
    //CIMA
    linhas2f(x1,x2,y2-1.17,y2-1.17,1,1,1,1);
    linhas2f(x1,x2,y2-1.2,y2-1.2,1,1,1,1);
    //MEIO
    linhas2f(x1,x2,y2-1.6,y2-1.6,1,1,1,1);
    linhas2f(x1,x2,y2-1.58,y2-1.58,1,1,1,1);
    linhas2f(x1,x2,y2-2.94,y2-2.94,1,1,1,1);
    linhas2f(x1,x2,y2-2.97,y2-2.97,1,1,1,1);
    //BAIXO
    linhas2f(x1,x2,y2-3.57,y2-3.57,1,1,1,1);
    linhas2f(x1,x2,y2-3.6,y2-3.6,1,1,1,1);
}
void cabinaParteDeBaixo(float x1,float x2, float y1, float y2,float r, float g, float b,float alfa){
    //CABINA PARTE DE BAIXO
    if(y1>=0.2 || y1>=-2){
        quadrado2f(x1,x2,y1,y2,r-r,g,b,alfa);
    }else{
        quadrado2f(x2,x1,y1,y2,r-r,g,b,alfa);
    }
}
void cabinaParteDeCima(float x1,float x2, float y1, float y2,float r, float g, float b){
    //CABINA PARTE DE CIMA
    glBegin(GL_POLYGON);
    if(y1>=-0.2 || y1>=-2){
        glColor3f(r-r,g,b);
        glVertex2f(x2-0.8,y2);
        glVertex2f(x1,y1);
        glVertex2f(x2,y1);
        glVertex2f(x2,y2);
    }else{
        glBegin(GL_POLYGON);
        glColor3f(r-r,g,b);
        glVertex2f(x2+0.8,y2);
        glVertex2f(x1-1.6,y1);
        glVertex2f(x2,y1);
        glVertex2f(x2,y2);
    }
    glEnd();

}
void quadrado2f(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa){
    glBegin(GL_QUADS);
    glColor4f(r,g,b,alfa);
    glVertex2f(x1,y2);
    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glEnd();
}
void janelaDaCabina(float x1,float x2, float y1,float y2,float r,float g,float b){
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    if(y1>=-0.2 || y1>=-2){
        glVertex2f(x2,y2);
        glVertex2f(x2,y1);
        glVertex2f(x1,y1);
        glVertex2f((x2-0.4),y2);
    }else{
        glVertex2f(x1,y2);
        glVertex2f(x1,y1);
        glVertex2f(x2,y1);
        glVertex2f((x2-1),y2);
    }
    glEnd();
}
void faroesDoComboio(float x1,float x2, float y1, float y2){
    //FAROES
    if((y1>=-0.2 || y1>=-2)){
        glBegin(GL_POLYGON);
        glColor3f(0,1,1);
        glVertex2f(x1,y2);
        glVertex2f(x1,y1);
        glVertex2f(x2,(y1-y2));
        glVertex2f(x2,y2-0.2);
        glEnd();
        if(noite==1){
            if(luzes==1){
                glBegin(GL_POLYGON);
                glColor4f(1,1,0,1);
                glVertex2f(x1,y2);
                glColor4f(0.8,0.8,0,1);
                glVertex2f(x1,y1);
                glColor4f(0.8,0.8,0,0.6);
                glVertex2f(x1-1.5,(y1-1));
                glColor4f(0.4,0.4,0,0.2);
                glVertex2f(x1-1.5,y2+1.2);
                glEnd();
            }
        }
    }else{
        glBegin(GL_POLYGON);
        glColor3f(0,1,1);
        glVertex2f(x1,y2-0.3);
        glVertex2f(x1,y1+0.3);
        glVertex2f(x2,(y1));
        glVertex2f(x2,y2);
        glEnd();
        if(noite==1){
            if(luz==1){
                glBegin(GL_POLYGON);
                glColor4f(1,1,0,1);
                glVertex2f(x2,y2);
                glColor4f(0.8,0.8,0,1);
                glVertex2f(x2,y1);
                glColor4f(0.4,0.4,0.4,1);
                glVertex2f(x2+1.5,(y1-1.2));
                glVertex2f(x2+1.5,y2+ 1.2);
                glEnd();
            }
        }
    }
}
void cabecaDoComboio(float x1,float x2, float y1, float y2,float r, float g, float b,float alfa){
    //CABE�A DO COMBOIO
    cabinaParteDeCima(x1+0.8,x2,y1,y2,r,g,b);
    cabinaParteDeBaixo(x1,x2,y1,y2-3,r,g,b,alfa);
   //quadrado(x1,x2,y1,y2,0,1,1);
}
void semaforo(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa, float mult){
    quadrado2f(x1,x2,y1,y2,r-r,g-g,b-b,alfa);
    quadrado2f(x2-0.5,x2-0.3,-y1,y1+0.5,r-r,g-g,b-b,alfa);
    if(semaphoro==0){
       circulo(x1+0.35,2,r,g,b-b,alfa,mult);
       circulo(x1+0.35,2.5,r-0.7,g-0.7,b-0.7,alfa,mult);
       circulo(x1+0.35,1.5,r-0.7,g-0.7,b-0.7,alfa,mult);
    }else{
        if(semaphoro==1){
            circulo(x1+0.35,2,r-0.7,g-0.7,b-0.7,alfa,mult);
            circulo(x1+0.35,2.5,r-r,g,b-b,alfa,mult);
            circulo(x1+0.35,1.5,r-0.7,g-0.7,b-0.7,alfa,mult);
        }else{
            circulo(x1+0.35,2,r-0.7,g-0.7,b-0.7,alfa,mult);
            circulo(x1+0.35,2.5,r-0.7,g-0.7,b-0.7,alfa,mult);
            circulo(x1+0.35,1.5,r,g-g,b-b,alfa,mult);
        }
    }
}
void estacao(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa, float mult){
   // estacao(-3,8,-0.2,5,1,1,1,1,0.2);
    passeioDaEstacao(x2-1,x2,-0.2,1.5,0.86,0.86,0.86,alfa);
    varanda(x2-1,x2,y1,1.5,0.86,0.86,0.86,alfa);
    casa(x1,x2-5,1.5,6);
    escada(x1,-x1,r,g,b,alfa,1);
    bancos(6.7+x1,x2-3.5,5.5,6.5,r,g,b,alfa,1);
    semaforo(x2+0.25,x2+1,1,3.0,r,g,b,alfa,0.2);
}
void nuvens(float x, float y, float r, float g, float b,float alfa, float mult){
    circulo(x,y,r,g, b,alfa, mult);
    circulo(x-1,y,r,g, b,alfa, mult);
    circulo(x,y+0.6,r,g, b,alfa, mult);
    circulo(x+0.7,y,r,g, b,alfa, mult);
    circulo(x,y-0.5,r,g, b,alfa, mult);
    circulo(x+1,y+0.7,r,g, b,alfa, mult);
    circulo(x+1.3,y-0.4,r,g, b,alfa, mult);
}
void desenhar(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(widthLeft,widthRight,heighLetf,heighRight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    ceu(-12,12,1,8,1,1,1,1);
    jardim();
    estacao(-3,8,-0.2,5,1,1,1,1,0.2);
    estrada(-12,12,-5.5,-1);
    //FALTA A VERIFICAÇÃO DO VALOR DE X
    comboio(movxx,movxx2,-0.2,-2,1,1,1,1);
    comboio(movx,movx2,-2.2,-4,1,1,1,1);
    glFlush();
}
void andarPrimeiroComboio(){
    switch(travadoCarro){
        case 0:
            switch(semaphoro){
                case 1:
                    if(movx2<=25){
                        if(velocidade>0){
                            movx2+=velocidade;
                            movx+=velocidade;
                        }else{
                            movx2+=0;
                            movx+=0;
                        }
                    }else{
                        movx=widthLeft-0.2;
                        movx2=widthLeft;
                    }
                    break;
                case 2:
                    if(!(movx>=7 && movx<=8)){
                        if(movx2<=25){
                            if(velocidade>0){
                                movx2+=velocidade;
                                movx+=velocidade;
                            }else{
                                movx2+=0;
                                movx+=0;
                            }
                        }else{
                            movx=widthLeft-0.2;
                            movx2=widthLeft;
                        }
                    }else{
                        movx2+=0;
                        movx+=0;
                        }
                    break;
                case 0:
                    if(velocidade>0){
                        semaphoro=1;
                    }else {
                        velocidade=0.1;
                        semaphoro=2;
                    }
                    break;
            }
            break;
        case 1:
            if(velocidade>0){
                travadoCarro=0;
            }
    }
}
void andarSegundoComboio(){
    switch(travadoCarro){
        case 0:
            switch(semaphoro){
                case 1:
                    if(movxx2>=-25){
                        if(velocidade1>0){
                            movxx2-=velocidade1;
                            movxx-=velocidade1;
                        }else{
                            movxx2-=0;
                            movxx-=0;
                        }
                    }else{
                        movxx=widthRight;
                        movxx2=widthRight+0.2;
                    }
                    break;
                case 2:
                    if(!(movxx>8.5 && movxx<9.5)){
                        if(movxx2>=-25){
                            if(velocidade>0){
                                movxx2-=velocidade1;
                                movxx-=velocidade1;
                            }else{
                                movxx2+=0;
                                movxx+=0;
                            }
                        } else{
                            movxx=widthRight;
                            movxx2=widthRight+0.2;
                        }
                    }else{
                        movxx2+=0;
                        movxx+=0;
                        }
                    break;
                case 0:
                    if(velocidade1>0){
                        semaphoro=1;
                    }else {
                        velocidade1=0.1;
                        semaphoro=2;
                    }
                    break;
            }
            break;
        case 1:
            if(velocidade>0){
                travadoCarro=0;
            }
    }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(4600/60,timer,0);
    switch(travadoNuvem){
        case 0:
            if(nuven2<=widthRight || nuven>=widthLeft){
                if(nuven>=widthLeft){
                    nuven-=0.08;
                }
                if(nuven2<=widthRight){
                    nuven2+=0.08;
                }

            }else{
                travadoNuvem=1;
            }
            break;
        case 1:
            if(nuven2>=widthLeft|| nuven<=widthRight){
                if(nuven<=widthRight){
                    nuven+=0.08;
                }
                if(nuven2>=-12){
                    nuven2-=0.08;
                }
            }else{
                travadoNuvem=0;
            }
            break;
    }

    andarPrimeiroComboio();
    andarSegundoComboio();
}
void pneu(float x1,float x2, float y1,float y2){
    if(y1>=-0.2 || y1>=-2){
        circulo(1+x1,-2.3,1,1,0,1,0.3);
        circulo(x1+2.6,-2.3,1,1,0,1,0.3);
        circulo(x1+5,-2.3,1,1,0,1,0.3);
        circulo(x1+7.5,-2.3,1,1,0,1,0.3);
        circulo(x1+10,-2.3,1,1,0,1,0.3);
        circulo(x1+12.8,-2.3,1,1,0,1,0.3);
    }else{
        circulo(x1-0.5,-4.3,1,1,0,1,0.3);
        circulo(x1-2,-4.3,1,1,0,1,0.3);
        circulo(-4.5+x1,-4.3,1,1,0,1,0.3);
        circulo(-7+x1,-4.3,1,1,0,1,0.3);
        circulo(-9.5+x1,-4.3,1,1,0,1,0.3);
        circulo(-12+x1,-4.3,1,1,0,1,0.3);
    }
}
void semaforoTime(int){
    glutPostRedisplay();
    glutTimerFunc(4000,semaforoTime,0);
    if(semaphoro==0){
        semaphoro=1;
    }else{
        if(semaphoro==1){
            semaphoro=2;
        }else semaphoro=0;
        }
}
void comboio(float x1,float x2, float y1,float y2,float r, float g, float b,float alfa){
    //COMBOIO
    //pneu(x1+0.2,x2+0.2,y1+0.2,y2+0.2);
    faroesDoComboio(x1,x2,y2,y1);
    if(y1>=0.2 || y1>=-2){
        cabecaDoComboio(x2,x2+3,y1,3+y2,r,g,b,alfa);
        //JANELA DA CABINA DO COMBOIO
        janelaDaCabina(x1+1.4,x2+2.6,y1,1.1+y1,r,g,b);
        //LIGAÇÃO DO PRIMEIRO VAGÃO
        quadrado2f(x2+3,x2+4,y2+0.6,y2-y1,r-r,g,b,alfa);
        //LIGA��O DA CABINA E O SEGUNDO VAG�O
        quadrado2f(x2+8,x2+9,y1-1.2,y2-y1,r-r,g,b,alfa);
        //PRIMEIRO VAG�O
        quadrado2f(x2+4,x2+8,y2,3+y2,r-r,g,b,alfa);
        //SEGUNDO VAG�O
        quadrado2f(x2+9,13+x2,y2,3+y2,r-r,g,b,alfa);
        //JANELA DO PRIMEIRO VAGãO
        quadrado2f(x1+4.6,x1+6,y1,0.9+y1,r,g,b,alfa);
        quadrado2f(x1+6.2,x1+8,y1,0.9+y1,r,g,b,alfa);
        //JANELA DO PRIMEIRO VAG�O
        quadrado2f(x1+9.6,10.2+x2,y1,0.9+y1,r,g,b,alfa);
        quadrado2f(10.3+x2,11+x2,y1,0.9+y1,r,g,b,alfa);
        quadrado2f(11.1+x2,11.8+x2,y1,0.9+y1,r,g,b,alfa);
        quadrado2f(11.9+x2,12.8+x2,y1,0.9+y1,r,g,b,alfa);
    }
    else{
        cabecaDoComboio(x1,x2-3,y1,3+y2,r,g,b,alfa);
        //JANELA DA CABINA DO COMBOIO
        janelaDaCabina(x1-2.6,x2-1.3,y1,1.1+y1,r,g,b);
        //LIGA��O DA CABINA E O PRIMEIRO VAG�O
        quadrado2f(x2-4,x2-3,y1-1.2,y2+0.2,r-r,g,b,alfa);
        //LIGA��O DA CABINA E O SEGUNDO VAG�O
        quadrado2f(x2-8,x2-9,y1-1.2,y2+0.2,r-r,g,b,alfa);
        //PRIMEIRO VAG�O
        quadrado2f(x2-4,x2-8,y2,3+y2,r-r,g,b,alfa);
        //SEGUNDO VAG�O
        quadrado2f(x2-9,-13+x2,y2,3+y2,r-r,g,b,alfa);
        //JANELA DO PRIMEIRO VAGãO
        quadrado2f(x1-4,x1-5.5,y1,0.9+y1,r,g,b,alfa);
        quadrado2f(x1-5.7,x1-7.5,y1,0.9+y1,r,g,b,alfa);
        //JANELA DO PRIMEIRO VAG�O
        quadrado2f(x1-9.0,-12.8+x2,y1,0.9+y1,r,g,b,alfa);
    }
    pneu(x1,x2,y1,y2);

}
#endif // FUNCOES_H
