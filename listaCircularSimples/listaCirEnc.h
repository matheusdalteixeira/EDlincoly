#ifndef LISTACIRENC_H_INCLUDED
#define LISTACIRENC_H_INCLUDED

typedef struct no_lista NO;
typedef struct lista LE;

struct no_lista{
	char nome[20];
	int idade;
	NO * proximo;
};

struct lista{
	NO * cabeca;
};

extern void inicia(LE * listaCir);
extern void entradaSaidaValores(int * idade, char * nome);
extern int insere(LE * listaCir, int idade, char * nome);
extern int apaga(LE * listaCir, int idade, char * nome);
extern int tamanho(LE listaCir);
extern int lista(LE listaCir);
extern int procura(LE listaCir, int idade, char * nome);

#endif