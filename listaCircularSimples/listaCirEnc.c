#include "listaCirEnc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//função com lista passada por referência para a função
void inicia(LE * listaCir){
	//é alocada memória para a cabeca da lista
	listaCir->cabeca = (NO *) malloc(sizeof(NO));
	//ponteiro cabeca para próximo da lista aponta para própria cabeca da lista
	listaCir->cabeca->proximo = listaCir->cabeca;
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

int insere(LE * listaCir, int idade, char * nome){
	NO * aux, * ant, *ant2;//declaração de três variáveis do tipo ponteiro
	aux = (NO *)malloc(sizeof(NO));//alocação de memória
	if(aux == NULL)//erro de alocação de memória por falta de espaço
		return 0;
	else{
		//ponteiro aux recebe o inteiro e a string passada por parâmetro para a função
		aux->idade = idade;
		strcpy(aux->nome, nome);
		//caso em que a lista está vazia pois o ponteiro lista->cabeca->proximo aponta para
		//ele mesmo
		if(listaCir->cabeca->proximo == listaCir->cabeca){
			//ponteiro aux->proximo recebe o endereço da cabeca da lista
			aux->proximo = listaCir->cabeca;
			//ponteiro listaCir->cabeca->proximo, ou seja, ponteiro para o próximo da cabeça
			//da lista
			listaCir->cabeca->proximo = aux;
			return 1;
		}
		else{
			//aloca espaço em memória para dois ponteiros percorrerem a lista
			ant = (NO *)malloc(sizeof(NO));
			ant2 = (NO *)malloc(sizeof(NO));
			ant = listaCir->cabeca;
			ant2 = ant->proximo;
			//laço while percorre a lista
			while(ant2 != listaCir->cabeca){
				//se ordem alfabética de variável nome maior que o ponteiro para o
				//nome alocado na lista ponteiros apontam para o próximo elemento da lista
				if(strcmp(nome, ant2->nome) > 0){
					ant = ant2;
					ant2 = ant->proximo;
				}
				//caso contrário para o loop while
				else
					break;
			}
			//acha a posição de encaixa na ordem alfabética
			ant->proximo = aux;
			aux->proximo = ant2;
			return 1;
		}
	}
}

int apaga(LE * listaCir, int idade, char * nome){
	if(listaCir->cabeca->proximo == listaCir->cabeca)
		return 0;
	else{		
		NO * aux, * ant;
		aux = (NO *)malloc(sizeof(NO));
		ant = (NO *)malloc(sizeof(NO));
		if(aux == NULL || ant == NULL)
			return 0;
		else{
			ant = listaCir->cabeca;
			aux = ant->proximo;
			while(aux != listaCir->cabeca){
				if(strcmp(aux->nome, nome) == 0 && aux->idade = idade){
					if(ant == listaCir->cabeca && aux->proximo == listaCir->cabeca){
						listaCir->cabeca->proximo = listaCir->cabeca;
						free(aux);
						aux = NULL;
						return 1;
					}
					else{
						if(ant == listaCir->cabeca && aux->proximo != listaCir->cabeca){
							listaCir->cabeca->proximo = aux->proximo;
							free(aux);
							aux = NULL;
							return 1;
						}
						else{
							if(ant != listaCir->cabeca && aux->proximo == listaCir->cabeca){
								ant->proximo = listaCir->cabeca;
								free(aux);
								aux = NULL;
								return 1;
							}
							else{
								ant->proximo = aux->proximo;
								free(aux);
								aux = NULL;
								return 1;
							}
						}
					}
				}
				ant = ant->proximo;
				aux = aux->proximo;
			}
		}
	}

}

int tamanho(LE listaCir){
	int tam = 0;
	NO * aux = (NO *) malloc(sizeof(NO));
	aux = listaCir.cabeca->proximo;
	while(aux != listaCir.cabeca){
		aux = aux->proximo;
		tam++;
	}
	return tam;
}

int lista(LE listaCir){
	if(listaCir.cabeca->proximo == listaCir.cabeca)
		return 0;
	else{
		NO * ponteiroElementos;
		ponteiroElementos = (NO *) malloc(sizeof(NO));
		ponteiroElementos = listaCir.cabeca->proximo;
		while(ponteiroElementos != listaCir.cabeca){
			printf("%s - %d\n", ponteiroElementos->nome, ponteiroElementos->idade);
			ponteiroElementos = ponteiroElementos->proximo;
		}
		return 1;
	}
}

int procura(LE listaCir, int idade, char * nome){
	if(listaCir.cabeca->proximo == listaCir.cabeca)
		return 0;
	else{
		int i = 0;
		NO * ponteiroElemento;
		ponteiroElemento = (NO *)malloc(sizeof(NO));
		ponteiroElemento = listaCir.cabeca->proximo;
		while(ponteiroElemento != listaCir.cabeca){
			if (strcmp(ponteiroElemento->nome, nome) == 0 && ponteiroElemento->idade == idade){
				printf("Achou %s - %d\n", ponteiroElemento->nome, ponteiroElemento->idade);
				return 1;
			}
			ponteiroElemento = ponteiroElemento->proximo;
		}
	}
}