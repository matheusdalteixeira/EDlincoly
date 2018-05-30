#include "fila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int idade, op = 1, posicao = 1;
	char nome[50], opProcura[11];

	//declara variável f do tipo ponteiro FILA
	FILA f;
	//função que inicia com nulo fila f.
	inicia(&f);

	system("cls");

	while(op > 0 && op < 6){
		puts("----------------Menu----------------");
		puts("[6] Sair");
		puts("[1] Inserir");
		puts("[2] Apagar");
		puts("[3] Tamanho");
		puts("[4] Listar");
		puts("[5] Procurar");
		scanf("%d", &op);
		puts("[ENTER]");
		system("cls");
		switch(op){
			case 1://insere
				entradaSaidaValores(&idade, nome);
				insere(&f, idade, nome);
				system("PAUSE");
				break;
			case 2://apaga
				apaga(&f);
				system("PAUSE");
				break;
			case 3://tamanho
				printf("Numero de registros = %d\n", tamanho(f));
				system("PAUSE");
				break;
			case 4://lista
				lista(f);
				system("PAUSE");
				break;
			case 5://procura
				entradaSaidaValores(&idade, nome);
				posicao = procura(f, idade, nome, posicao);
				printf("Nome: %s\n", nome);
				printf("Idade: %d\n", idade);
				printf("Posicao: %d\n", posicao);
				posicao = 0;
				system("PAUSE");
				break;
			case 6://sai
				exit(1);
				break;
		}
		system("cls");
	}
	return 0;
}