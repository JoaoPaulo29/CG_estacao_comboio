#ifndef HEADERS_H
#define HEADERS_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

//VARIAVEIS PARA DIMENSÃO DA TELA PRINCIPAL
float widthLeft=-12,widthRight=12,heighLetf=-8,heighRight=8;

//VARIAVEIS AUXILIARES
//VARIAVEL PARA TRANSLAÇÃO DO CAOMBOIO
//SEGUNDO COMBOIO
float movxx=0,movxx2=0.2, luz=0;
//PRIMEIRO COMBOIO
float movx=0, movx2=0.2;
int travadoCarro=0, luzes=0;
float velocidade=0.1,velocidade1=0.1;

//VARIAVEL PARA TRANSLAÇÃO DAS NUVENS E AUXILIARES PARA O CEU
int i,travadoNuvem=0;
float noite=0, lua=0, nuven=12, nuven2=-12;

int semaphoro=0;
//VARIAVEIS PARA ABRIR PORTA E JANELS
int janela=0,porta=1;

void desenhar(void);
void quadrado2f(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa);
void janelaDaCabina(float x1,float x2, float y1,float y2,float r,float g,float b);
void comboio(float x1,float x2, float y1,float y2,float r, float g, float b,float alfa);
void varanda(float x1,float x2, float y1,float y2, float r,float g,float b,float alfa);
void nuvens(float x, float y, float r, float g, float b,float alfa, float mult);
void pneu(float x1,float x2, float y1,float y2);
void triangulo3f(float x1, float x2, float x3, float y1, float y2,float y3,float r,float g,float b,float alfa);
void linhas2f(float x1,float x2,float y1,float y2,float r,float g,float b,float alfa);
void poligono4f(float x1, float x2,float x3, float x4,float y1, float y2,float y3,float y4, float r, float g, float b,float alfa);

#endif // HEADERS_H
