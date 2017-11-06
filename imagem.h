#ifndef NaoImporta_h
#define NaoImporta_h

typedef struct {
	unsigned short int r, g, b; //tons vermelho, verde e azul de cada pixel
} Pixel;

typedef struct{
	unsigned int altura, largura, max;
	char titulo[30];
	Pixel **M;
} Imagem;

void make_PPM_cinza (FILE *arquivo, Imagem *m);

Pixel **alocar_espaco_para_matriz_de_pixels(unsigned int altura, unsigned int largura);

void ler_arq (FILE *arquivo, Imagem *m);

#endif
