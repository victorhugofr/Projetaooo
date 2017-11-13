#include "imagem.h"
#include "grey.h"

//FUNCAO DE CONVERSAO DA IMAGEM EM TONS DE CINZA
Imagem* make_PPM_cinza (Imagem *m) {
	unsigned int i,j;
	int temp;

	//Colocando no tom cinza, atraves de mudanças nos valores vermelho, verde e azul de cada pixel
	for (i=0; i < m->altura; i++) {
		for (j=0; j < m->largura; j++) {
			temp = 0;
			temp += (unsigned short int) ((m->M[i][j]).r) * 0.3;
			temp += (unsigned short int) ((m->M[i][j]).g) * 0.59;
			temp += (unsigned short int) ((m->M[i][j]).b) * 0.11;

			(m->M[i][j]).r = temp;
			(m->M[i][j]).g = temp;
			(m->M[i][j]).b = temp;
		}
	}
	return m;
}
