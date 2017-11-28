PROJETO ITP 2017.2
Programa de detecção de Catarata

Feito por:	Daniel Oliveira Guerra
			Pedro Augusto Pessoa Paraense


Funcionalidas Extras:
	1. Imagem em RGB com contorno da pupila; (Ver processos.c)
	2. Definição da quantidade de vezes que se gostaria de aplicar o filtro de Gauss/Sobel; (Definiçao da quantidade no main.c)
	3. Ignorar comentários nas imagens (seja antes do formato; entre o formato e a linha com largura e altura; seja entre a linha com largura e altura e a linha contendo o max); (Ver em read.c e read.h)
	4. Diagnóstico também diz qual foi a imagem analisada; (Ver uteis.c)
	5. A imagem entrada pode ter qualquer diretório escrito na execução do programa (função 'tirar_diretorio_do_nome_da_imagem'; checar uteis.c e uteis.h);
	6. Perguntas para dar o poder de decisão ao usuário;
	7. Segmentação do flash, melhorando um pouco a precisão de detecção; (Ver processos.c)
	8. Manutenção da memória do computador ao dar free em todas as imagens;
	9. Programa funcionando com imagens extras; (Ver diretório in)

Funcionalidades básicas:
	Todos funcionalidas básicas foram atendidas


O que seria feito diferente:
	Implementação de uma função que obtivesse o limiar de Binarização, para uma imagem, automaticamente;
	


Para compilar:
	Acesse, no terminal, o diretório onde salvou este arquivo 'README.TXT';
	Digite 'make' no terminal;
	Execute no formato: ./catarata -i <input-image> -f <input-image-format> -o <diagnose-file>.
	
Informações adicionais:
	Acesse o arquivo makefile para orientações de 'clean'
	
#Ajeitar a segmentação do flash em Extra2.ppm
