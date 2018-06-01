#include "pilha.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int idade, op = 1;
	char nome[50];

	PILHA f;

	inicia(&f);

	system("cls");//limpa a tela do console

	while(op > 0 && op < 6){
		puts("----------------Menu----------------");
		puts("[5] Sair");
		puts("[1] Inserir");
		puts("[2] Apagar");
		puts("[3] Tamanho");
		puts("[4] Listar valores");
		scanf("%d", &op);//guarda na variável op a opção escolhida no menu
		system("cls");
		switch(op){
			case 1:
				entradaSaidaValores(&idade, nome);//guarda os valores idade e nome nas respectivas variáveis
				insere(&f, idade, nome);//insere os valores na estrutura
				system("PAUSE");//pausa a execução dessas duas última funções na tela
				break;
			case 2:
				entradaSaidaValores(&idade, nome);//guarda os valores idade e nome nas respectivas variáveis
				apaga(&f);
				system("PAUSE");//pausa a execução dessas duas última funções na tela
				break;
			case 3:
				printf("tamanho = %d\n",tamanho(f));
				system("PAUSE");//pausa a execução dessas duas última funções na tela
				break;
			case 4:
				//printf("%s\n", f->nome);
				lista(f);
				system("PAUSE");//pausa a execução dessas duas última funções na tela
				break;
		}
		system("cls");
	}
	return 0;
}