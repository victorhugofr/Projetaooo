#include "read.h"

//FUNCAO DE LEITURA DE ARQUIVO, IDENTIFICACAO DA IMAGEM(CABECALHO E PIXELS) E RETIRADA DE COMENTARIOS
void ler_arq (FILE *arquivo, Imagem *m) {
	unsigned int i,j;
	char str_check[73];//Variavel para checar se ha '#'
	unsigned int a;

	//Agora ler os dados contidos no cabecalho
	while (5 < 8) { //Aqui eu checo se existem comentarios antes da informacao do header. Se existirem, eu os pulo ate chegar no header
		fscanf(arquivo, "%s", str_check);
		if (str_check[0] == '#') {
			fgets(str_check, 71, arquivo);
		}
		else {
			strcpy(m->header, str_check);
			if (strcmp(str_check, "P3") != 0) {
				fprintf(stderr,"Fudeu meu bom!");
				fclose(arquivo);
				exit(1);
			}
			break;
		}
	}
	
	while(5 < 8) {  //Aqui eu checo se existem comentarios entre a linha que informa header, e a linha que informa largura e altura. Se existirem, eu os pulo ate chegar na linha de largura e altura
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
