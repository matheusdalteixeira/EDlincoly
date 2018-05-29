#include "listaDupEnc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inicia(LISTADUPENC * listaDup){
	*listaDup = NULL;//inicia a estrutura com o ponteiro para nulo
}

int insere(LISTADUPENC * listaDup, int idade, char * nome){//função insere nomes ordenadamente
	int cmpstring;
	if(*listaDup == NULL){//se a lista estiver vazia faça...
		*listaDup = (LISTADUPENC) malloc(sizeof(ESTRUTURA));//aloca espaço no ponteiro para iniciar a lista
		if(*listaDup == NULL) return 0;//se a função malloc retornar null é porque não existe espaço em memória para ser alocada
		strcpy((*listaDup)->nome, nome);//copia o parâmetro "nome" da função para o campo (*listaDup)->nome
		(*listaDup)->idade = idade;//copia o parâmetro "idade" da função para o campo (*listaDup)->idade
		(*listaDup)->anterior = NULL;
		(*listaDup)->proximo = NULL;
	}
	else{
		//puts("-------------Dentro de insere->else-------------");
		LISTADUPENC tmp, tmp2;//inicializa dois ponteiros 
		tmp = (LISTADUPENC) malloc(sizeof(ESTRUTURA));//alocada dois espaços de memória para dois ponteiros
		tmp2 = (LISTADUPENC) malloc(sizeof(ESTRUTURA));
		if(tmp == NULL || tmp2 == NULL)//se as variáveis ponteiros retornarem nulo indica que não há espaço disponível na memória
			return 0;
		tmp2 = *listaDup;//tmp2 aponta para o inicio da lista
		strcpy(tmp->nome, nome);//copia o parâmetro "nome" para o campo nome do ponteiro "tmp"
		tmp->idade = idade;//copia o parâmetro "idade" para o campo idade do ponteiro "tmp"
		while((*listaDup)->proximo != NULL){//enquanto a váriável do tipo ponteiro não apontar para nulo a instrução if segue
			if(strcmp(nome, (*listaDup)->nome) > 0)//verifica se "nome" está antes ou depois de (*lista)->nome na ordem alabetica
				*listaDup = (*listaDup)->proximo;//já descrito no while
			else
				break;// caso esteja antes de (*lista)->nome na ordem alabetica said do laço while
		}
		
		//observação para função strcmp:
		
		//1 - se a primeira string for maior que a segunda o retorno
		// da função será positivo										exemplo:strcmp(carlos, andre)
		//2 - se a primeira string for igual a segunda o retorno da
		// função será zero												exemplo:strcmp(carlos, carlos)
		//3 - se a primeira string for menor que a segunda o retorno
		// da função será negativo										exemplo:strcmp(andre, carlos)
		
		//observação para o primeiro if logo após a saida do while:

		//1 - caso o retorno da função strcmp dentro do loop while tenha sido positivo até
		// que o ponteiro para nulo tenha sido alcançado, isso significa que a primeira string
		// é maior que a segunda string. logo maior que todas as strings presentes na lista
		if(strcmp(nome, (*listaDup)->nome) > 0){
			tmp->proximo = NULL;			
			tmp->anterior = *listaDup;
			(*listaDup)->proximo = tmp;
			*listaDup = tmp2;
			return 1;
		}
		//2 - caso o retorno da função strcmp dentro do loop while tenha sido negativo antes  
		// de o ponteiro para nulo ter sido alcançado, isso significa que foi encontranda uma
		// posição no inicio ou no meio da lista para inserir o nome
		if(strcmp(nome, (*listaDup)->nome) <= 0){
			if((*listaDup)->anterior == NULL){//insere no inicio da lista
				tmp->proximo = *listaDup;//ponteiro proximo para o inicio da lista
				tmp->anterior = NULL;//ponteiro anterior para nulo para referenciar o inicio da lista
				(*listaDup)->anterior = tmp;//ponteiro inicio da lista para o novo inicio da lista
				*listaDup = tmp;//ponteiro da lista para o novo inicio da lista
				return 1;
			}
			if((*listaDup)->anterior != NULL){//insere no meio da lista
				tmp->proximo = *listaDup;//ponteiro para o próximo elemento da lista com "nome" de valor maior que o ponteiro temp
				tmp->anterior = (*listaDup)->anterior;//...
				(*listaDup)->anterior->proximo = tmp;//...
				(*listaDup)->anterior = tmp;//..
				//como foi percorrida a lista com o próprio ponteiro da 
				//lista é necessário apontar a lista para o inicio novamente
				*listaDup = tmp2;
				return 1;
			}
		}
	}
}

int apaga(LISTADUPENC *listaDup, int idade, char * nome){
	//Aloca espaço para três variáveis do tipo ponteiro
	LISTADUPENC tmp = (LISTADUPENC) malloc(sizeof(ESTRUTURA));
	LISTADUPENC ant = (LISTADUPENC) malloc(sizeof(ESTRUTURA));
	LISTADUPENC inicio = (LISTADUPENC) malloc(sizeof(ESTRUTURA));
	//Se qualquer uma das três for nulo não é possí executar a operação de apagar a variável
	if(tmp == NULL || ant == NULL || inicio == NULL)
		return 0;
	//Como foi utilizado para percorrer a lista o próprio ponteiro da lista
	inicio = *listaDup;
	//Enquanto o ponteiro para o próximo elemento não encontrar nulo e os nomes comparados não
	// forem iguais, ou seja retorno da função strcmp não for 0 o while segue apontando para
	// o próximo elemento
	while((*listaDup)->proximo != NULL){
		if(strcmp((*listaDup)->nome, nome) == 0)
			break;
		*listaDup = (*listaDup)->proximo;
	}
	//se as estruturas nome e idade baterem com o que foi dado como entrada if é executado
	if(strcmp((*listaDup)->nome, nome) == 0 && (*listaDup)->idade == idade){
		//se o primeiro registro for encontrado esse if é executado
		if((*listaDup)->anterior == NULL){
			//se houver um registro o ponteiro para o próximo e para o anterior é nulo
			if((*listaDup)->proximo == NULL){
				free(*listaDup);
				*listaDup = NULL;
			}
			//esse ellse indica que o primeiro registro vai ser apagado
			else{
				tmp 					= *listaDup;//tmp recebe o endereço a ser apagado
				*listaDup 				= (*listaDup)->proximo;//inicio da lista aponta para ao próximo ponteiro
				free(tmp);//variável temp é liberada pelo sistema
				//novo ponteiro para inicio da lista tem ponteiro anterior para NULL, indicando o inicio da lista
				(*listaDup)->anterior 	= NULL;
			}
			return 1;
		}
		if((*listaDup)->anterior != NULL){//inserçãoa partir da segunda posição
			tmp = *listaDup;
			if((*listaDup)->proximo == NULL){//apaga na última posição
				*listaDup = (*listaDup)->anterior;
				free(tmp);
				(*listaDup)->proximo = NULL;
			}
			else{//apaga da última até a penúltima posição
				(*listaDup)->anterior->proximo = (*listaDup)->proximo;
				(*listaDup)->proximo->anterior = (*listaDup)->anterior;
				free(tmp);
			}
			*listaDup = inicio;
			return 1;
		}
	}
	return 0;
}

int tamanho(LISTADUPENC listaDup){
	int tam = 0;
	while(listaDup != NULL){//enquanto não apontar para nulo segue while
		listaDup = listaDup->proximo;//aponta para o próximo registro
		tam++;//incrementa o tamanho
	}
	return tam;
}

void lista(LISTADUPENC listaDup){
	while(listaDup != NULL){
		printf("%s - %d\n", listaDup->nome, listaDup->idade);//exibe cconteúdo dos registros
		listaDup = listaDup->proximo;//aponta para o próximo registro
	}
}

//recebe valores para inserir na funções apaga, insere e procura
void entradaSaidaValores(int * idade, char * nome){
	printf("Nome:");
	scanf("%s", nome);
	printf("\n");	
	printf("Idade:");
	scanf("%d", idade);
	printf("\n");
}

//procura registro por nome
int procura(LISTADUPENC listaDup, int * idade, char * nome){
	//enquanto o registro com o nome especificado não for encontrado o ponteiro listaDup
	//aponta para o próximo registro
	while(listaDup->proximo != NULL && strcmp(listaDup->nome, nome) != 0)
		listaDup = listaDup->proximo;
	if(strcmp(listaDup->nome, nome) == 0){
		strcpy(nome, listaDup->nome);//retorna os valores para nome passado por referência para a função
		*idade = listaDup->idade;//retorna para varíável idade
		return 1;
	}
	else return 0;
}