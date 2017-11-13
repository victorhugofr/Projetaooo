#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "imagem.h"

Pixel **alocar_espaco_para_matriz_de_pixels(unsigned int altura, unsigned int largura){
	Pixel **M = calloc(altura,sizeof(Pixel *)); //Alocaçao de criação das linhas
	unsigned int i;
	for (i=0; i < altura; i++) {
		M[i] = calloc(largura,sizeof(Pixel));//Alocação de criação das colunas
	}
	return M;
}
