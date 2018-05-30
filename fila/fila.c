#include "fila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inicia(FILA *fila){
	*fila = NULL; //Inicia a fiila co o valor nulo
}

void insere(FILA *fila, int idade, char *nome){
	if(*fila == NULL){//se a estrutura fila estiver vazia faça...
		*fila = (FILA) malloc(sizeof(PESSOA));//aloca espaço na memória para inserir elemento na fila
		if(*fila == NULL) return;//se retorno da função malloc for nulo encerra a função, ou seja não existe espaço em memória
		(*fila)->idade = idade;//insere a variável idade na posíção de memória alocada no campo idade do registro
		strcpy((*fila)->nome, nome);//insere o valor da variável nome na posíção de memória alocada dentro do campo nome do registro
		(*fila)->proximo = NULL;//configura o próximo registro para nulo, para indicar o fim da estrutura fila
	}
	else//se a estrutura não estiver vazia faça...
		insere(&((*fila)->proximo), idade, nome);//insere um campo no registro não vazio
}

void apaga(FILA *fila){
	PESSOA *tmp = *fila;//declaração de um ponteiro para o inicio da fila
	if(*fila == NULL) return;//caso a fila esteja vazia nada pode ser apagado
	else{//caso a fila não esteja vazia...
		*fila = (*fila)->proximo;//o inicio da fila é deslocado para o próximoo endereço
		free(tmp);//é liberado o espaço em memória da variável tmp
	}
}

void lista(FILA fila){
	if(fila == NULL){//fila vazia
		return;
	}
	else{//fila não vazia
		printf("%d %s\n", fila->idade, fila->nome);//imprimi os valores contidos no ponteiros
		lista(fila->proximo);//passa o endereço do proximo endereço através da função recursiva
	}
}

int tamanho(FILA fila){
	int tam = 0;
	while(fila != NULL){//enquanto não chegar ao endereço nulo...
		fila = fila->proximo;//ponteiro é deslocado para o próximo endereço
		tam++;
	}
	return tam;
}

void entradaSaidaValores(int * idade, char * nome){
	puts("Entre com os valores abaixo:");
	printf("\nnome: ");
	scanf("%s", nome);//configura o valor da variável no ponteiro nome
	printf("\nidade: ");
	scanf("%d", idade);//configura o valor da variável no ponteiro *idade
}

//retona a posição de um elemento na fila para
//para futura implementação de testes de eficiencia
//do projeto
int procura(FILA fila, int idade, char * nome, int posicao){
	//fila vazia
	if(fila == NULL){
		printf("if-%d\n",posicao);
		return 0;
	}
	//fila não vazia
	else{
		//função recursiva
		//caso esteja na primeira posição, a função
		//retorna o valor passado a função pela variável
		//"posicao" que foi 1
		if(strcmp(fila->nome, nome) == 0 && fila->idade == idade){
			printf("if-else-if-%d\n",posicao);
			return posicao;
		}
		//caso não esteja na primeira posição, o else
		//realiza força a recursividade passado o endereço
		//do próximo ponteiro da fila e incrementa a posição
		//da fila
		else{
			posicao++;
			printf("if-else-else-%d\n", posicao);
			posicao = procura(fila->proximo, idade, nome, posicao);
		}	
	}
}