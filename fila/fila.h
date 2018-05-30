#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED

typedef struct sPessoa{
	int 	idade;
	char	nome[21];
	struct 	sPessoa *proximo;
}PESSOA;

typedef PESSOA * FILA;

extern void inicia(FILA * fila);
extern void insere(FILA * fila, int idade, char *nome);
extern void apaga(FILA * fila);
extern void lista(FILA fila);
extern int tamanho(FILA fila);
extern void entradaSaidaValores(int * idade, char * nome);
extern int procura(FILA fila, int idade, char * nome, int posicao);

#endif