#ifndef PILHA_h_INCLUDED
#define PILHA_H_INCLUDED

typedef struct sPessoa{
	int idade;
	char nome[21];
	struct sPessoa * proximo;
}PESSOA;

typedef PESSOA * PILHA;

extern void inicia(PILHA * pilha);
extern void entradaSaidaValores(int * idade, char * nome);
extern int insere(PILHA * pilha, int idade, char* nome);
extern void apaga(PILHA * pilha);
extern int lista(PILHA pilha);
extern int tamanho(PILHA pilha);

#endif