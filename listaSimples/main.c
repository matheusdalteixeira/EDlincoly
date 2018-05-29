#include "listaEnc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int idade, op = 1, indice = 0;
	char nome[50], opProcura[11];

	LISTAENCADEADA L;
	inicia(&L);

	system("cls");

	while(op > 0 && op < 6){
		puts("----------------Menu----------------");
		puts("[6] Sai");
		puts("[1] Insere");
		puts("[2] Apaga");
		puts("[3] Tamanho");
		puts("[4] Relatorio");
		puts("[5] Procura");
		scanf("%d", &op);
		puts("[ENTER]");
		system("cls");
		switch(op){
			case 1://insere
				//passa variáveis por referência para função
				entradaSaidaValores(&idade, nome);
				//insere os valores retornados através do parâmetro da função anterior
				insere(&L, idade, nome);
				break;
			case 2://apaga
				//passa variáveis por referência para função
				entradaSaidaValores(&idade, nome);
				//apaga os valores retornados através do parâmetro da função anterior
				apaga(&L, idade, nome);
				break;
			case 3://tamanho
				printf("Número de registros = %d\n", tamanho(&L));
				system("PAUSE");
				break;
			case 4://lista
				lista(L);
				system("PAUSE");
				break;
			case 5://procura
				puts("Especifique por qual elemento deseja procurar:");
				puts("Nome[n] + ENTER[ENTER]");
				puts("Idade[i] + ENTER[ENTER]");
				strcpy(opProcura, retornaValores(nome, &idade));
				procura(L, opProcura, nome, &idade);
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