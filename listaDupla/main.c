#include "listaDupEnc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int idade, op = 1;
	char nome[50];

	LISTADUPENC L;// Declaração da lista encadeada
	inicia(&L);//inicializa a estrutura de lista encadeada

	system("cls");//limpa a tela do console

	while(op > 0 && op < 6){
		puts("----------------Menu----------------");
		puts("[6] Sair");
		puts("[1] Inserir");
		puts("[2] Apagar");
		puts("[3] Tamanho");
		puts("[4] Listar valores");
		puts("[5] Procurar");
		scanf("%d", &op);//guarda na variável op a opção escolhida no menu
		system("cls");
		switch(op){
			case 1://insere
				entradaSaidaValores(&idade, nome);//guarda os valores idade e nome nas respectivas variáveis
				insere(&L, idade, nome);//insere os valores na estrutura
				system("PAUSE");//pausa a execução dessas duas última funções na tela
				break;
			case 2://apaga
				entradaSaidaValores(&idade, nome);//guarda os valores idade e nome nas respectivas variáveis
				apaga(&L, idade, nome);//apaga os valores na estrutura
				system("PAUSE");
				break;
			case 3://tamanho
				printf("Numero de registros = %d\n", tamanho(L));//conta o tamanho de registros na tela
				system("PAUSE");
				break;
			case 4://lista
				lista(L);//lista os valores na 
				system("PAUSE");
				break;
			case 5://procura
				puts("Especifique por qual elemento deseja procurar:");
				entradaSaidaValores(&idade, nome);//guarda os valores idade e nome nas respectivas variáveis
				if(procura(L, &idade, nome) == 0)//procura os valores informados na função procura
					printf("Não achou %s - %d\n", nome, idade);
				else
					printf("Achou %s - %d\n", nome, idade);
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