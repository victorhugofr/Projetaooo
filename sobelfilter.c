#include "imagem.h"
#include "sobelfilter.h"

//FUNCAO DE APLICACAO DO FILTRO GAUSSIANO NA IMAGEM
Imagem *SobelFilter (Imagem *m, int limite) {
	if (limite < 1) {
		fprintf(stderr, "ERRO: Nao foi possivel aplicar o filtro de sobel vezes!\n");
	}

	int sobel_x[3][3] = {{1, 0, -1}, {2, 0, -2}, {1, 0, -1}};//Filtro para as mudanças horizontais
	int sobel_y[3][3] = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};//Filtro para as mudanças verticais
	unsigned int i,j,k,l;
	double aux_x=0, aux_y=0;//Variaveis de auxilio para o calculo

	Imagem *SobelImage = criarImagem(m->altura, m->largura, m->max);
	strcpy(SobelImage->header, m->header);

	for (i=0; i < m->altura; i++) {
		for (j=0; j < m->largura; j++) {
				//Aqui serao analisados cada pixel da imagem 'entrada'
			aux_x = 0;
			aux_y = 0;
			for (k=0; k < 3; k++) {
				for (l=0; l < 3; l++) {
					if ( (i+k-1 < 0) || (j+l-1 < 0) || (i-1+k >= m->altura) || (j-1+l >= m->largura) ) {
						continue;
					} 

					aux_x += (double) m->M[i+k-1][j+l-1].r * sobel_x[k][l];
					aux_y += (double) m->M[i+k-1][j+l-1].r * sobel_y[k][l];
				}
			}
			if (sqrt((aux_x * aux_x) + (aux_y * aux_y)) > m->max) { //Caso ocorra desse valor ultrapassar o tom maximo de RGB, os pixels devem ficar com o valor maximo
				SobelImage->M[i][j].r = m->max;
				SobelImage->M[i][j].g = m->max;
				SobelImage->M[i][j].b = m->max;
			}
			else {
				SobelImage->M[i][j].r = sqrt((aux_x * aux_x) + (aux_y * aux_y));
				SobelImage->M[i][j].g = sqrt((aux_x * aux_x) + (aux_y * aux_y));
				SobelImage->M[i][j].b = sqrt((aux_x * aux_x) + (aux_y * aux_y));
			}
		}
	}
	
	if (limite > 1) {
		SobelImage = SobelFilter(SobelImage, limite -1);
		printf("O filtro de sobel foi aplicado um total de %d vezes!\n", limite);
	}
	else if (limite == 1) {
		printf("O filtro de sobel foi aplicado 1 vez!\n");
	}

	freeImagem(m);
	return SobelImage;
}
