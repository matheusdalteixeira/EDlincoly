#include "listaCirDup.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inicia(LE * listaCir){
	listaCir->cabeca = (NO *)malloc(sizeof(NO)); //aloca ponteiro para inicia a lista
	if (listaCir->cabeca == NULL)//se ponteiro para cabeça da lista igual a null encerra a função
		return 0;
	//aponta o ponteiro proximo e anterior para a própria cabeça
	listaCir->cabeca->proximo = listaCir->cabeca;
	listaCir->cabeca->anterior = listaCir->cabeca;
	return 1;
}

//função genérica para dar entrada em valores
void entradaSaidaValores(int * idade, char * nome){
	puts("Entre com os valores abaixo:");
	printf("\nnome: ");
	scanf("%s", nome);
	printf("\nidade: ");
	scanf("%d", idade);
}

int insere(LE * listaCir, int idade, char * nome){
	NO * aux, * ant, * ant2; //declara ponteiros
	aux = (NO *)malloc(sizeof(NO));//aloca memória para ponteiros
	if(aux == NULL)//se esse ponteiro for null encerra função por acusar falta de memória
		return 0;
	else{
		aux->idade = idade;//ponteiro aux para idade recebe o valor de idade
		strcpy(aux->nome, nome);//copia a string nome para o ponteiro aux->nome
		//se lista vazia, ou seja, lista que aponta para a sua própria cabeça, já que é uma lista circular
		//o ponteiro aux->proximo e aux->anterior apontam para a própria cabeça da lista e lista->cabeca->proximo
		// e lista->cabeca->anterior apontam para aux
		if(listaCir->cabeca->proximo == listaCir->cabeca){
			aux->anterior = listaCir->cabeca;
			aux->proximo = listaCir->cabeca;
			listaCir->cabeca->proximo = aux;
			listaCir->cabeca->anterior = aux;
			return 1;
		}
		//se lista não vazia executa o else abaixo
		else{
			//declara dois ponteiros do tipo (NO *)
			ant = (NO *)malloc(sizeof(NO));
			ant2 = (NO *)malloc(sizeof(NO));
			//se função malloc retornar null para os ponteiros acima sai da função
			if(ant == NULL || ant2 == NULL)
				return 0;
			//ponteiro ant recebe a cabeça da lista e ant2 recebe o proximo de ant para
			//percorrerem a lista
			ant = listaCir->cabeca;
			ant2 = ant->proximo;
			//enquanto ant2 não retornar a lista->cabeca percorre lista.
			//Ou seja, percorre a lista até o final.
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
			//ponteiro ant servira para encontrar o último elemento da lista e fazer
			//com que o ponteiro aux que será o ponteiro a ser incluido na lista faça
			//com que o apontador anterior de aux seja apontador para ant. Portanto, 
			//aux->anterior aponta para ant. Segue regra parecida para os demais
			//apontamentos.
			//último da lista aponta para aux;
			//aux aponta para último da lista;
			//aux aponta para cabeça da lista para torna-la circular;
			//ant2 que é a cabeça da lista aponta agora para o novo último da lista
			ant->proximo = aux;
			aux->anterior = ant;
			aux->proximo = ant2;
			ant2->anterior = aux;
		}
	}
}

int apaga(LE * listaCir, int idade, char * nome){
	//se lista vazia não pode apagar nada, logo encerra a função
	if(listaCir->cabeca->proximo == listaCir->cabeca)
		return 0;
	//caso contrário começa o else
	else{
		NO * aux, * ant;//declara dois ponteiros do tipo (NO *)
		//aloca memória para os dois ponteiros
		aux = (NO *)malloc(sizeof(NO));
		ant = (NO *)malloc(sizeof(NO));
		//caso algum ponteiro seja null, encerra função pois não existe espaço em memória
		if(aux == NULL || ant == NULL)
			return 0;
		//caso contrário começa o else
		else{
			//ponteiro ant para cabeça da lista e aux para o próximo de cabeça que é o 
			//primeiro elemento
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
		NO * ponteiroElemento;
		ponteiroElemento = (NO *)malloc(sizeof(NO));
		if(ponteiroElemento == NULL)
			return 0;
		ponteiroElemento = listaCir.cabeca->proximo;
		while(ponteiroElemento != listaCir.cabeca){
			printf("%s - %d\n", ponteiroElemento->nome, ponteiroElemento->idade);
			ponteiroElemento = ponteiroElemento->proximo;
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
		if(ponteiroElemento == NULL)
			return 0;
		ponteiroElemento = listaCir.cabeca->proximo;
		while(ponteiroElemento != listaCir.cabeca){
			if(strcmp(ponteiroElemento->nome, nome) == 0){
				printf("Achou %s - %d\n", ponteiroElemento->nome, ponteiroElemento->idade);
				return 1;
			}
			ponteiroElemento = ponteiroElemento->proximo;
		}
	}
}