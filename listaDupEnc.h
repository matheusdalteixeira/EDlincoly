#ifndef LISTADUPENC_H_INCLUDED
#define LISTADUPENC_H_INCLUDED

#define tamnhoStringOpcoes 20;

typedef struct estrutura{
	int idade;
	char nome[21];
	struct estrutura * proximo;
	struct estrutura * anterior;
}ESTRUTURA;

typedef ESTRUTURA * LISTADUPENC;

extern void inicia(LISTADUPENC * listaDup);//Inicia
extern int insere(LISTADUPENC * listaDup, int idade, char * nome);//Insere registro em ordem alfabética
extern int apaga(LISTADUPENC * listaDup, int idade, char * nome);//Deleta em ordem alfabética
extern void lista(LISTADUPENC listaDup);//Lista em ordem alfabética
extern int tamanho(LISTADUPENC listaDup);//Retorna tamanho
extern void entradaSaidaValores(int * idade, char * nome);//Retorna por qual elemento deseja procurar
extern int procura(LISTADUPENC listaDup, int * idade, char * nome);//Retorna inteiro se achou

#endif