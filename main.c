#include "imagem.h"

int main() {
	FILE *imagem;//Ponteiro para o arquivo que contem a imagem de entrada
	FILE *nova_imagem;//Ponteiro para o arquivo onde sera salva imagem resultante
	char nome_imagem[50], nome_nova_imagem[50];
	unsigned int i,j;

	printf("Digite o nome do arquivo de entrada: ");
	scanf("%s", nome_imagem);//Le o nome do arquivo de entrada
	printf("Digite o nome de onde a nova imagem sera salva: ");
	scanf("%s", nome_nova_imagem);

	imagem = fopen(nome_imagem, "r");//Abre o arquivo de leitura da imagem
	if (imagem == NULL) {
		fprintf(stderr,"FUCKING ERRO\n");
		return 0;
	}

	nova_imagem = fopen(nome_nova_imagem, "w");//Criando arquivo que recebera nova imagem

	Imagem *minha_imagem_que_vai_ser_lida = (Imagem *) malloc(sizeof(Imagem));
	ler_arq(imagem, minha_imagem_que_vai_ser_lida);

	Imagem *Img_de_saida; 
	Img_de_saida = make_PPM_cinza(minha_imagem_que_vai_ser_lida);

	//Img_de_saida = GaussFilter(minha_imagem_que_vai_ser_lida);//Aqui eu salvo a imagem pos filtro na variavel Img_de_saida

	fprintf(nova_imagem, "%s\n", Img_de_saida->header);
	fprintf(nova_imagem, "%u %u\n", Img_de_saida->largura, Img_de_saida->altura);
	fprintf(nova_imagem, "%u\n", Img_de_saida->max);
	for (i=0; i < Img_de_saida->altura; i++) {
		for (j=0; j < Img_de_saida->largura; j++) {
			fprintf(nova_imagem, "%hu\n", Img_de_saida->M[i][j].r);
			fprintf(nova_imagem, "%hu\n", Img_de_saida->M[i][j].g);
			fprintf(nova_imagem, "%hu\n", Img_de_saida->M[i][j].b);
		}
	}
	fclose(nova_imagem);
}
