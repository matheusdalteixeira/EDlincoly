#ifndef LISTACIRDUPENC_H_INCLUDED
#define LISTACIRDUPENC_H_INCLUDED

typedef struct no_lista NO;
typedef struct lista LE;

struct no_lista{
	char nome[20];
	int idade;
	NO * proximo;
	NO * anterior;
};

struct lista{
	NO * cabeca;
};

extern int inicia(LE * listaCir);
extern void entradaSaidaValores(int * idade, char * nome);
extern int insere(LE * listaCir, int idade, char * nome);
extern int apaga(LE * listaCir, int idade, char * nome);
extern int tamanho(LE listaCir);
extern int lista(LE listaCir);
extern int procura(LE listaCir, int idade, char * nome);

#endif