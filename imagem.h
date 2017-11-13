#ifndef NaoImporta_h
#define NaoImporta_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	unsigned short int r, g, b; //tons vermelho, verde e azul de cada pixel
} Pixel;

typedef struct {
	char header[5];
	unsigned int altura, largura, max;
	char titulo[30];
	Pixel **M;
} Imagem;

Pixel **alocar_espaco_para_matriz_de_pixels(unsigned int altura, unsigned int largura);

Imagem *criarImagem(unsigned int altura, unsigned int largura, unsigned int max);

void freeImagem(Imagem *img);

#endif
