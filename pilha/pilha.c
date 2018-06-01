#include "pilha.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inicia(PILHA * pilha){
	*pilha = NULL;
}

//captura valores genéricos para usar em outras funções
//parâmetros da função são passados por referência
//como as variáveis são passadas por referência usamos 
//o operador de & na função scanf já que essa função pede o endereço das variáveis
void entradaSaidaValores(int * idade, char * nome){
	puts("Entre com os valores abaixo:");
	printf("\nnome: ");
	scanf("%s", nome);
	printf("\nidade: ");
	scanf("%d", idade);
}

int insere(PILHA * pilha, int idade, char * nome){
	if(*pilha == NULL){
		*pilha = (PILHA) malloc(sizeof(PESSOA));
		if(*pilha == NULL)
			return 0;
		(*pilha)->idade = idade;
		strcpy((*pilha)->nome, nome);
		(*pilha)->proximo = NULL;
		return 1;
	}
	else{
		PESSOA * tmp;
		tmp = (PILHA) malloc(sizeof(PESSOA));
		if(tmp == NULL)
			return 0;
		tmp->idade = idade;
		strcpy(tmp->nome, nome);
		tmp->proximo = *pilha;
		*pilha = tmp;
		return 1;
	}
}

void apaga(PILHA * pilha){
	PESSOA * tmp = *pilha;
	if(*pilha == NULL) return;
	else{
		*pilha = (*pilha)->proximo;
		free(tmp);
	}
}

int lista(PILHA pilha){
	if(pilha == NULL){
		return 0;
	}
	else{
		printf("%d %s\n", pilha->idade, pilha->nome);
		lista(pilha->proximo);
	}
}

int tamanho(PILHA pilha){
	int tam = 0;
	while(pilha != NULL){
		pilha = pilha->proximo;
		tam++;
	}
	return tam;
}