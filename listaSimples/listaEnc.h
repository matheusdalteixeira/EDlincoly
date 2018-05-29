#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED

#define tamanhoStringOpcoes 10

typedef struct sPessoa{
	int idade;
	char nome[21];
	struct sPessoa * proximo;
}PESSOA;

typedef PESSOA * LISTAENCADEADA;

extern void inicia(LISTAENCADEADA * listaEnc);
extern void entradaSaidaValores(int * idade, char * nome);//Retorna por qual elemento deseja procurar
extern int insere(LISTAENCADEADA * listaEnc, int idade, char * nome);
extern void escolhePosicaoDelete(int * indiceReferencia);
extern int apaga(LISTAENCADEADA * listaEnc, int idade, char * nome);
extern void lista(LISTAENCADEADA listaEnc);
extern int tamanho(LISTAENCADEADA * listaEnc);
extern int procura(LISTAENCADEADA listaEnc, char * opcao, char * nome, int * idade);
extern char * retornaValores(char * nome, int * idade);

#endif