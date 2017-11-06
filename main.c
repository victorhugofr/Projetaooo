int main() {
	FILE *imagem;//Ponteiro para o arquivo que contem a imagem de entrada
	FILE *nova_imagem;//Ponteiro para o arquivo onde sera salva imagem resultante
	char nome_imagem[50], nome_nova_imagem[50];

	printf("Digite o nome do arquivo de entrada: ");
	scanf("%s", nome_imagem);//Le o nome do arquivo de entrada
	printf("Digite o nome de onde a nova imagem sera salva: ");
	scanf("%s", nome_nova_imagem);

	imagem = fopen(nome_imagem, "r");//Abre o arquivo de leitura da imagem
	if (imagem == NULL) {
		fprintf(stderr,"Arquivo nao esta no formato PPM!");
		return 0;
	}

	Imagem *minha_imagem_que_vai_ser_lida = malloc(sizeof(Imagem)); //;-;

	ler_arq(imagem, minha_imagem_que_vai_ser_lida);

	nova_imagem = fopen(nome_nova_imagem, "w");//Criando arquivo que recebera nova imagem
	make_PPM_cinza(nova_imagem, minha_imagem_que_vai_ser_lida);

}
