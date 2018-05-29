#include "listaEnc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//inicia lista encadeada com ponteiro para nulo para indicar arvore vazia
void inicia(LISTAENCADEADA * listaEnc){
	*listaEnc = NULL;
}

//captura valores genéricos para usar em outras funções
//parâmetros da função são passados por referência
//como as variáveis são passadas por referência usamos o operador de & na função scanf já que essa função pede o endereço das variáveis
void entradaSaidaValores(int * idade, char * nome){
	printf("Nome:");
	scanf("%s", nome);
	printf("\n");	
	printf("Idade:");
	scanf("%d", idade);
	printf("\n");
}

//insere os ponteiros com os valores na lista
//obs: strings sempre são passadas como referência para funções
//obs2: função insere registro a partir de uma posição passada como parâmetro para a função
//função insere nomes ordenadamente
int insere(LISTAENCADEADA * listaEnc, int idade, char * nome){
	int cmpstring;
	if(*listaEnc == NULL){//se a lista estiver vazia faça...
		*listaEnc = (LISTAENCADEADA) malloc(sizeof(PESSOA));//aloca espaço no ponteiro para iniciar a lista
		if(*listaEnc == NULL) return 0;//se a função malloc retornar null é porque não existe espaço em memória para ser alocada
		strcpy((*listaEnc)->nome, nome);//copia o parâmetro "nome" da função para o campo (*listaDup)->nome
		(*listaEnc)->idade = idade;//copia o parâmetro "idade" da função para o campo (*listaDup)->idade
		(*listaEnc)->proximo = NULL;
	}
	else{
		//puts("-------------Dentro de insere->else-------------");
		LISTAENCADEADA tmp, tmp2, listaAnterior;//inicializa dois ponteiros 
		tmp 			= (LISTAENCADEADA) malloc(sizeof(PESSOA));//alocada dois espaços de memória para dois ponteiros
		tmp2 			= (LISTAENCADEADA) malloc(sizeof(PESSOA));
		listaAnterior 	= (LISTAENCADEADA) malloc(sizeof(PESSOA));
		if(tmp == NULL || tmp2 == NULL || listaAnterior == NULL)//se as variáveis ponteiros retornarem nulo indica que não há espaço disponível na memória
			return 0;
		tmp2 = *listaEnc;//tmp2 aponta para o inicio da lista
		strcpy(tmp->nome, nome);//copia o parâmetro "nome" para o campo nome do ponteiro "tmp"
		tmp->idade = idade;//copia o parâmetro "idade" para o campo idade do ponteiro "tmp"
		while((*listaEnc)->proximo != NULL){//enquanto a váriável do tipo ponteiro não apontar para nulo a instrução if segue
			if(strcmp(nome, (*listaEnc)->nome) > 0){//verifica se "nome" está antes ou depois de (*lista)->nome na ordem alabetica
				listaAnterior = *listaEnc;//...
				*listaEnc = (*listaEnc)->proximo;//já descrito no while
			}
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
		if(strcmp(nome, (*listaEnc)->nome) > 0){
			puts("fim");
			tmp->proximo = NULL;			
			(*listaEnc)->proximo = tmp;
			*listaEnc = tmp2;
			system("PAUSE");
			return 1;
		}
		//2 - caso o retorno da função strcmp dentro do loop while tenha sido negativo antes  
		// de o ponteiro para nulo ter sido alcançado, isso significa que foi encontranda uma
		// posição no inicio ou no meio da lista para inserir o nome
		if(strcmp(nome, (*listaEnc)->nome) <= 0){
			if(*listaEnc == tmp2){//insere no inicio da lista
				puts("inicio");
				tmp->proximo = *listaEnc;//ponteiro proximo para o inicio da lista
				*listaEnc = tmp;//ponteiro da lista para o novo inicio da lista
				system("PAUSE");
				return 1;
			}
			else{//insere no meio da lista
				puts("meio");
				tmp->proximo = *listaEnc;//ponteiro para o próximo elemento da lista com "nome" de valor maior que o ponteiro temp
				listaAnterior->proximo = tmp;//...
				//como foi percorrida a lista com o próprio ponteiro da 
				//lista é necessário apontar a lista para o inicio novamente
				*listaEnc = tmp2;
				system("PAUSE");
				return 1;
			}
		}
	}
}

int apaga(LISTAENCADEADA * listaEnc, int idade, char * nome){
	LISTAENCADEADA tmp, aux, auxAnt;//declara variáveis

	//lista vazia
	if(*listaEnc == NULL)
		return 0;
	//lista não vazia
	else{
		//alocação de memória para ponteiros
		tmp = (LISTAENCADEADA) malloc(sizeof(PESSOA));
		aux = (LISTAENCADEADA) malloc(sizeof(PESSOA));
		auxAnt = (LISTAENCADEADA) malloc(sizeof(PESSOA));
		//falha na alocação de memória
		if(tmp == NULL || aux == NULL || auxAnt == NULL)
			return 0;
		//ponteiro para o inicio da lista
		tmp = *listaEnc;
		//loop para percorrer a lista
		while(*listaEnc != NULL){
			//compara o ponteiro de campo nome e idade com as variáveis passadas como
			//parâmetro para a função. Logo caso seja diferentes os ponteiros percorrem
			//a lista
			if(strcmp((*listaEnc)->nome, nome) != 0 && (*listaEnc)->idade != idade){
				//como a lista não é duplamente encadeada é necessário seguir com dois
				//ponteiros na lista para os casos de exclusão no meio e no fim da lista
				auxAnt = *listaEnc;
				*listaEnc = (*listaEnc)->proximo;
			}
			else
				break;
		}
		//encontrou no inicio da lista
		if(*listaEnc == tmp){
			//lista só contém um elemento, pois o ponteiro para o próximo é nulo
			if((*listaEnc)->proximo == NULL){
				free(*listaEnc);
				*listaEnc = NULL;
			}
			//lista contém mais de um elemento, pois ponteiro para o próximo é 
			//diferente de nulo
			else{
				//inicio da lista aponta para o próximo
				*listaEnc = (*listaEnc)->proximo;
				//ponteiro para o inicio da lista será apagado
				free(tmp);
				//?
				tmp = NULL;
			}
		}
		//não encontrou no início da lista
		else{
			//encontrou no fim de uma lista de mais de um elemento
			if((*listaEnc)->proximo == NULL){
				aux = *listaEnc;//ponteiro para o elemento a ser excluido
				//ponteiro auxAnt será o novo último da lista e por isso tem ponteiro para o proximo NULL
				auxAnt->proximo = NULL;
				//libera espaço em memória do registro excluido
				free(aux);
				//??
				aux = NULL;
				//lista aponta para o inicio novamente
				*listaEnc = tmp;
			}
			//encontrou no meio de uma lista de mais de um elemento
			else{
				//aponta para o endereço de memória a ser apagado
				aux = *listaEnc;
				//ponteiro anterior ao que será apagado da lista aponta para o próximo do próximo
				//pulando assim o endereço de memória que será apagado
				auxAnt->proximo = aux->proximo;
				//..
				free(aux);
				//??
				aux = NULL;
				//..
				*listaEnc = tmp;
			}
		}
	}

/*	LISTAENCADEADA tmp;//declara ponteiro do tipo LISTAENCADEADA
	int indAux = 1;//índices de comparação com as posições na lista

	//encerra a função caso o índice que se deseja apagar seja inválido
	//ou a lista esteja vazia e não se possa apagar nada
	if(indice < 1 || indice > tamanho(listaEnc)+1 || (*listaEnc) == NULL){
		return;
	}
	//caso contrário executa o else
	else{
		//apaga na primeira posição
		if(indice == 1){
			//...
			if(tamanho(listaEnc) == 1){
				tmp = *listaEnc;//ponteiro para o inicio da lista
				free(tmp);//libera o espaço alocado para aquela variável
				*listaEnc = NULL;//configura null para o ponteiro
			}
			//...
			if(tamanho(listaEnc) > 1){
				tmp = (*listaEnc);//...
				(*listaEnc) = (*listaEnc)->proximo;//muda ponteiro para o novo inicio da lista
				free(tmp);//...
			}
		}
		//apaga no meio ou no fim
		else if(indice > 1 && indice < tamanho(listaEnc)){
			tmp = (*listaEnc);//...
			//enquanto não chegar ao indice do ponteiro
			//anterior ao que se deseja ponteiro *listaEnc aponta para próximo registro
			while(indAux < indice-1){
				*listaEnc = (*listaEnc)->proximo;
				indAux++;
			}
			tmp = (*listaEnc)->proximo;//ponteiro tmp aponta para o ponteiro a ser apagado
			//ponteiro *listaEnc->proximo passa a apontar para dois ponteiros a frente, pois
			//(*listaEnc)->proximo será apagado
			(*listaEnc)->proximo = (*listaEnc)->proximo->proximo;
			free(tmp);//...
		}
		else{
			tmp = (*listaEnc);
			while(tmp->proximo != NULL)
				tmp = tmp->proximo;
		}
	}*/
}

void lista(LISTAENCADEADA listaEnc){
	int contador = 0;//variável que conta quantidade de caracteres em ma string
	char stringColuna[14] = "";//string vazia para gerar saída de texto por linha no terminal
	printf("Nome          - Idade\n");//..
	//enquanto não chegar no fim da lista...
	while(listaEnc != NULL){
		//variável contador recebe a quantidade de caracteres do ponteiro listaEnc->nome
		contador = strlen(listaEnc->nome);
		//copia os caracteres para stringColuna
		strcpy(stringColuna, listaEnc->nome);
		//formata todas as string para exibição com 13 colunas
		while(contador < 13){
			//concatena duas string para formatar terminal
			strcat(stringColuna, " ");
			//conta o número de colunas
			contador++;
		}
		//imprimi registros
		printf("%s - %d\n", stringColuna, listaEnc->idade);
		//aponta para o próximo registro
		listaEnc = listaEnc->proximo;
	}
}

//imprimi tamanho da lista
int tamanho(LISTAENCADEADA * listaEnc){
	int tam = 0;
	LISTAENCADEADA tmp;//declara ponteiro para percorrer a lista
	tmp = *listaEnc;//aponta ponteiro para o inicio da lista
	//percorre a lista de ponteiro em ponteiro
	while(tmp != NULL){
		tmp = tmp->proximo;
		tam++;
	}
	return tam;
}

char * retornaValores(char * nome, int * idade){
	static char op[tamanhoStringOpcoes];//variável para escolha de qual campo deseja ser pesquisado
	scanf("%s",op);
	if(op[0] == 'n'){
		puts("Digite o nome:");
		scanf("%s", nome);//armazena o nome na string nome
		return op;
	}
	else if(op[0] == 'i'){
		puts("Digite a idade:");
		scanf("%d", &idade);//armazena um valor inteiro na variável idade passada por referência
		return op;
	}
	//caso a string op[0] seja diferente 'i' ou 'n' o usuário não escolheu a forma de pesquisar adequadamente
	else{
		puts("Opcao invalida! Você sera redirecionado para o menu principal.");
		strcpy(op, "opcaoInvalida");
		return op;
	}
}

int procura(LISTAENCADEADA listaEnc, char * opcao, char * nome, int * idade){
	//caso a string op no índice zero tenha o caractere 'n', a pesquisa será feita
	//pelo campo nome, caso tenha o caractere 'i' a pesquisa será feita pela idade
	if(opcao[0] == 'n'){
		//percorre a lista enquanto o ponteiro para nulo não for encontrado
		while(listaEnc != NULL){
			//caso a string nome seja igual ao ponteiro para o campo nome a função strcmp retorna zero
			if(strcmp(listaEnc->nome, nome) == 0){
				*idade = listaEnc->idade;//valor do ponteiro idade recebe o valor do ponteiro da lista para o campo idade
				printf("\n%s - %d\n", nome, *idade);
				return 1;
			}
			//ponteiro recebe o próximo da lista
			listaEnc = listaEnc->proximo;
		}
	}
	if(opcao[0] == 'i'){
		//percorre a lista enquanto o ponteiro para nulo não for encontrado
		while(listaEnc != NULL){
			//caso o valor da variável do tipo ponteiro inteiro passsada por 
			//referência para a função seja igual ao valor do ponteiro da lista
			//para o campo idade execute o if
			if(listaEnc->idade == *idade){
				//copia o conteúdo da string do tipo ponteiro da lista para a string nome
				strcpy(nome, listaEnc->nome);
				return 1;
			}
			//ponteiro recebe o próximo da lista
			listaEnc = listaEnc->proximo;
		}
	}
	return 0;
}