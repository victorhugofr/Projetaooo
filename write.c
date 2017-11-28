#include "write.h"

//Funcao de escrita da imagem passada por parametro, em um arquivo cujo nome tambem e passado por parametro
void write_img(Imagem *m, char *outfilename) {
	FILE* imagem;
	unsigned int i,j;

	imagem = fopen(outfilename, "w");

	//Inserindo o formato da imagem criada
	fprintf(imagem, "%s\n#BY DANIEL O. GUERRA E PEDRO AUGUSTO P. PESSOA\n", m->header); //A imagem criada sera do mesmo tipo da imagem inserida
	//fprintf(imagem, "P3\n") Caso queira sempre em PPM
	//Porem, em nosso caso, a imagem continua sempre sendo PPM

	//Inserindo a largura e altura da matriz imagem, respectivamente
	fprintf(imagem, "%u %u\n", m->largura, m->altura);

	//Inserindo o valor maximo para um tom de RGB da imagem
	fprintf(imagem, "%u\n", m->max);

	//Inserindo os valores RGB de cada pixel da imagem
	for (i=0; i < m->altura; i++) {
		for (j=0; j < m->largura; j++) {
			fprintf(imagem, "%hu\n", m->M[i][j].r);
			fprintf(imagem, "%hu\n", m->M[i][j].g);
			fprintf(imagem, "%hu\n", m->M[i][j].b);
		}
	}

	fclose(imagem);
}
