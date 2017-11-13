#include "imagem.h"
#include "gaussfilter.h"

//FUNCAO DE APLICACAO DO FILTRO GAUSSIANO NA IMAGEM
Imagem* GaussFilter (Imagem *m) {

	int filter[5][5] = {{2,4,5,4,2},{4,9,12,9,4},{5,12,15,12,5},{4,9,12,9,4},{2,4,5,4,2}};//Filtro Gaussiano
	unsigned int i,j,k,l;
	int aux=0,div=0;//Variaveis de auxilio para o calculo
	unsigned short int g_aux;

	Imagem *GaussImage;
	GaussImage = malloc(sizeof(Imagem));
	GaussImage->M = alocar_espaco_para_matriz_de_pixels(m->altura, m->largura);//Alocando o espaço para a matriz de Pixels da imagem pós filtro

	strcpy(GaussImage->header, m->header);
	GaussImage->altura = m->altura;
	GaussImage->largura = m->largura;
	GaussImage->max = m->max;

	for (i=0; i < m->altura; i++) {
		for (j=0; j < m->largura; j++) {
			for (k = -2; k <=2; k++) {
				for (l = -2; l <= 2; l++) {
					if ( (i+k < 0) || (j+l < 0) || (i+k >= m->altura) || (j+l >= m->largura) ) {
						continue;
					} 

					aux += m->M[i+k][j+l].r * filter[k+2][l+2];
					div += filter[k+2][l+2];
				}
			}
			g_aux = (unsigned short int) aux/div;
			aux = 0;
			div = 0;
			GaussImage->M[i][j].r = g_aux; //(unsigned short int) aux/div;
			GaussImage->M[i][j].g = g_aux;//(unsigned short int) aux/div;
			GaussImage->M[i][j].b = g_aux;//(unsigned short int) aux/div;

		}
	}
	printf("%hu %hu %hu\n", GaussImage->M[i][j].r, GaussImage->M[i][j].g, GaussImage->M[i][j].b);

	return GaussImage;
}
