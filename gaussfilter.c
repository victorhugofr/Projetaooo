#include "imagem.h"
#include "gaussfilter.h"

//FUNCAO DE APLICACAO DO FILTRO GAUSSIANO NA IMAGEM
Imagem *GaussFilter (Imagem *m, int blurtimes) {

	int filter[5][5] = {{2,4,5,4,2}, {4,9,12,9,4}, {5,12,15,12,5}, {4,9,12,9,4}, {2,4,5,4,2}};//Filtro Gaussiano
	unsigned int i,j,k,l;
	double aux=0;//Variaveis de auxilio para o calculo

	Imagem *GaussImage = criarImagem(m->altura, m->largura, m->max);
	strcpy(GaussImage->header, m->header);

	for (i=0; i < m->altura; i++) {
		for (j=0; j < m->largura; j++) {
			aux = 0;
			for (k=0; k < 5; k++) {
				for (l=0; l < 5; l++) {
					if ( (i+k-2 < 0) || (j+l-2 < 0) || (i+k-2 >= m->altura) || (j-2+l >= m->largura) ) {
						continue;
					} 

					aux += (double) (m->M[i+k-2][j+l-2].r * filter[k][l])/159;
				}
			}
			GaussImage->M[i][j].r = aux;
			GaussImage->M[i][j].g = aux;
			GaussImage->M[i][j].b = aux;

		}
	}

	if (blurtimes > 1) {
		GaussImage = GaussFilter(GaussImage, blurtimes -1);
	}
	else if (blurtimes == 1) {
		printf("ok");
	}
	printf("%hu %hu %hu\n", GaussImage->M[0][6].r, GaussImage->M[0][6].g, GaussImage->M[0][6].b);

	return GaussImage;
}
