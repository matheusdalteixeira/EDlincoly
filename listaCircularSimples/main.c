#include "listaCirEnc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int idade, op = 1; //indice = 0, rodandoPesquisa;
	char nome[50], opProcura[11];

	LE L;
	inicia(&L);

	system("cls");

	while(op > 0 && op < 6){
		puts("----------------Menu----------------");
		puts("[6] Sair");
		puts("[1] Inserir");
		puts("[2] Apagar");
		puts("[3] Tamanho");
		puts("[4] Listar valores");
		puts("[5] Procurar");
		scanf("%d", &op);
		puts("[ENTER]");
		system("cls");
		switch(op){
			case 1://insere
				//puts("-------------Antes de insereValores-------------");
				entradaSaidaValores(&idade, nome);
				//puts("-------------Antes de insere-------------");
				insere(&L, idade, nome);
				//insere(&L, 32, "chris");
				//insere(&L, 36, "flavio");
				//insere(&L, 25, "matheus");
				system("PAUSE");
				break;
			case 2://apaga
				entradaSaidaValores(&idade, nome);
				apaga(&L, idade, nome);
				system("PAUSE");
				break;
			case 3://tamanho
				printf("Numero de registros = %d\n", tamanho(L));
				system("PAUSE");
				break;
			case 4://lista
				lista(L);
				system("PAUSE");
				break;
			case 5://procura
				//puts("===========Antes da funcao retornaValores===========");
				entradaSaidaValores(&idade, nome);
				//puts("===========Antes da funcao procura===========");
				procura(L, idade, nome);
				//puts("===========Antes do teste de retorno da funcao procura===========");
				//printf("\n%d - %s - %d\n", rodandoPesquisa, nome, idade);
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