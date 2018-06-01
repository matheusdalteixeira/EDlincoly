int insere(LE * listaCir, int idade, char * nome){
	if(listaCir->cabeca->proximo == listaCir->cabeca){
		NO * aux;
		aux = (NO *)malloc(sizeof(NO));
		if(aux == NULL)
			return 0;
		strcpy(aux->nome, nome);
		aux->idade = idade;
		aux->proximo = listaCir->cabeca;
		listaCir->cabeca->proximo = aux;
	}
	else if(strcmp(nome, aux2->nome) > 0){
		insere(aux->proximo, idade, nome);
	}
}