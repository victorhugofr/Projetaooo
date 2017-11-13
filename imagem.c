#include "imagem.h"

Imagem *criarImagem(unsigned int altura, unsigned int largura, unsigned int max) {
	Imagem *novaImagem = (Imagem *) calloc(1,sizeof(Imagem));

	novaImagem->altura = altura;
	novaImagem->largura = largura;
	novaImagem->max = max;

	novaImagem->M = alocar_espaco_para_matriz_de_pixels(altura, largura);

	return novaImagem;
}

Pixel **alocar_espaco_para_matriz_de_pixels(unsigned int altura, unsigned int largura) {
	Pixel **M = calloc(altura,sizeof(Pixel *)); //Alocaçao de criação das linhas
	unsigned int i;
	for (i=0; i<altura; i++) {
		M[i] = calloc(largura,sizeof(Pixel));//Alocação de criação das colunas
	}
	return M;
}

void freeImagem(Imagem *img) {
	unsigned int i;
	for (i=0; i < img->altura; ++i) {
		free(img->M[i]);
	}
	free(img->M);

	free(img);
}
