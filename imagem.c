#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "imagem.h"

void make_PPM_cinza (FILE *arquivo, Imagem *m) {
	int i,j;
	int temp;

	fprintf(arquivo, "P3\n");//Fazendo com que seja do formato PPM, porem cinza
	fprintf(arquivo, "%u %u\n", m->largura, m->altura);
	fprintf(arquivo, "%u\n", m->max);

	//***CASO EU QUEIRA ESCRITO NA FORMA DE LINHAS E COLUNAS***

	// for (j=0; j < m->largura; j++) {
	// 	temp = (unsigned short int) ((m->M[0][j]).r) * 0.3;
	// 	fprintf(arquivo, "%hu ", temp);
	// 	temp = (unsigned short int) ((m->M[0][j]).g) * 0.59;
	// 	fprintf(arquivo, "%hu ", temp);
	// 	temp = (unsigned short int) ((m->M[0][j]).b) * 0.11;
	// 	fprintf(arquivo, "%hu ",temp);
	// }    

	//Colocando no tom cinza, atraves de mudanças nos valores vermelho, verde e azul de cada pixel
	for (i=0; i < m->altura; i++) {
		//fprintf(arquivo, "\n"); ***ACRESCENTAR ISSO CASO EU QUERIA ESCRITO NA FORMA DE LINHAS E COLUNAS***
		for (j=0; j < m->largura; j++) {
			temp = 0;
			temp += (unsigned short int) ((m->M[i][j]).r) * 0.3;
			temp += (unsigned short int) ((m->M[i][j]).g) * 0.59;
			temp += (unsigned short int) ((m->M[i][j]).b) * 0.11;
			fprintf(arquivo, "%hu\n", temp);
			fprintf(arquivo, "%hu\n", temp);
			fprintf(arquivo, "%hu\n", temp);
		}
	}

	fclose(arquivo);
}

Pixel **alocar_espaco_para_matriz_de_pixels(unsigned int altura, unsigned int largura){
	Pixel **M = calloc(altura,sizeof(Pixel *)); //Alocaçao de criação das linhas
	int i;
	for (i=0; i<altura; i++) {
		M[i] = calloc(largura,sizeof(Pixel));//Alocação de criação das colunas
	}
	return M;
}

void ler_arq (FILE *arquivo, Imagem *m) {
	char formato[2];
	int i,j;
	char str_check[73];//Variavel para checar se ha '#'
	unsigned int a;

	//Agora ler os dados contidos no cabecalho
	while (5 < 8) { //Aqui eu checo se existem comentarios antes da informacao de formato. Se existirem, eu os pulo ate chegar no formato
		fscanf(arquivo, "%s", str_check);
		if (str_check[0] == '#') {
			fgets(str_check, 71, arquivo);
		}
		else {
			if (strcmp(str_check, "P3") != 0) {
				fprintf(stderr,"Erro");
				fclose(arquivo);
				exit(1);
			}
			break;
		}
	}
	
	while(5 < 8) {  //Aqui eu checo se existem comentarios entre a linha que informa formato, e a linha que informa largura e altura. Se existirem, eu os pulo ate chegar na linha de largura e altura
		fscanf(arquivo, "%s", str_check);
		if (str_check[0] == '#') {
			fgets(str_check, 71, arquivo);
		}
		else {
			a = strlen(str_check);
			m->largura = 0; //A largura (em pixels) da imagem
			for (i=0, j=a-1; i<a; i++, j--) { //Como a largura (um unsigned int) foi salva no str_check(uma string de char), preciso converter para obter minha largura
				m->largura += (unsigned int) (str_check[i] - 48) * pow(10,j);//Convertendo o valor do caracter para um valor decimal (de acordo com a tabela ASCII)
			}
			break;
		}
	}

	fscanf(arquivo, " %u", &(m->altura));//A altura (em pixels) da imagem

	while (5 < 8) { //Aqui eu checo se existem comentarios entre a linha de lagura e altura, e a linha do max. Se existirem, eu os pulo ate chegar na linha que me informa o max
		fscanf(arquivo, "%s", str_check);
		if (str_check[0] == '#') {
			fgets(str_check, 71, arquivo);
		}
		else {
			a = strlen(str_check);
			m->max = 0; //Valor maximo de um tom de cor
			for (i=0, j=a-1; i<a; i++, j--) { //Como o max (um unsigned int) foi salvo no str_check(uma string de char), preciso converter para obter meu max
				m->max += (int) (str_check[i] - 48) * pow(10,j); //Convertendo o valor do caracter para um valor decimal (de acordo com a tabela ASCII)
			}
		break;
		}
	}

	m->M = alocar_espaco_para_matriz_de_pixels(m->altura, m->largura);

	unsigned short int temp;

	// while (5 < 8) { //Aqui eu checo se existem comentarios entre o max e os valores dos pixels. Se existirem, eu os pulo ate chegar nos valores dos pixels
	// 	fscanf(arquivo, "%s", str_check);
	// 	if (str_check[0] == '#') {
	// 		fgets(str_check, 71, arquivo);
	// 	}
	// 	else {
	// 		a = strlen(str_check);
	// 		(m->M[0][0]).r = 0;
	// 		for (i=0, j=a-1; i<a; i++, j--) {
	// 			(m->M[0][0]).r += (unsigned short int) (str_check[i] - 48) * pow(10,j); 
	// 		}
	// 	}

	for (i=0; i < m->altura; i++) {
		for (j=0; j < m->largura; j++) {
			fscanf(arquivo, "%hu", &temp);//Lendo a cor vermelha do pixel
			(m->M[i][j]).r = temp;
			fscanf(arquivo, "%hu", &temp);//Lendo a cor verde do pixel
			(m->M[i][j]).g = temp;
			fscanf(arquivo, "%hu", &temp);//Lendo a cor azul do pixel
			(m->M[i][j]).b = temp;
		}
	}

	fclose(arquivo);
}

void ler_arq (FILE *arquivo, Imagem *m) {
	char formato[2];
	int i,j;
	char str_check[75];//Variavel para checar se ha '#'

	//Agora ler os dados contidos no cabecalho
	// while (5 < 8) {
	// 	fscanf(arquivo, "%s", str_check);
	// 	if (strcmp(str_check[0], '#') != 0) {
	// 		//fscanf(arquivo, "%s", formato);
	// 		formato = str_check;
	// 		if (strcmp(formato, "P3") != 0
	// 			fprintf(stderr,"Arquivo nao esta no formato PPM!");
	// 			fclose(arquivo);
	// 			exit(1);
	// 		}
	// 	}
	// 	else 
			fscanf(arquivo, "%s", formato);
			if (strcmp(formato, "P3") != 0) {
				fprintf(stderr,"Arquivo nao esta no formato PPM!");
				fclose(arquivo);
				exit(1);
			}
	// 		fgets(str_check, 72, arquivo);
	// }
	//while (strcmp(str_check[0], '#') != 0) {}

	fscanf(arquivo, "%u %u", &(m->largura), &(m->altura));//A largura e altura, respectivamente,(em pixels) da imagem
	fscanf(arquivo, "%u", &(m->max));//Valor maximo de um tom de cor
	printf("%u %u\n", m->largura, m->altura);

	m->M = alocar_espaco_para_matriz_de_pixels(m->altura, m->largura);

	unsigned short int temp;

	for (i=0; i < m->altura; i++) {
		for (j=0; j < m->largura; j++) {
			fscanf(arquivo, "%hu", &temp);//Lendo a cor vermelha do pixel
			(m->M[i][j]).r = temp;
			fscanf(arquivo, "%hu", &temp);//Lendo a cor verde do pixel
			(m->M[i][j]).g = temp;
			fscanf(arquivo, "%hu", &temp);//Lendo a cor azul do pixel
			(m->M[i][j]).b = temp;
		}
	}

	fclose(arquivo);
}
