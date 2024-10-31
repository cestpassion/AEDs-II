#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista *lst_cria(void); // função que cria uma lista vazia (NULL)
Lista *lst_insere(Lista *l, int v); // função que insere um elemento no início da lista
int lst_vazia(Lista *l); // função que verifica se a lista está vazia
void lst_imprime(Lista *l); // função que imprime os elementos da lista
Lista *lst_busca(int elemento, Lista *l); // função que busca um elemento na lista
Lista *lst_retira(Lista *l, int v); // função que retira um elemento da lista
void lst_libera(Lista *l); // função que libera a memória alocada para a lista
Lista *lst_insere_ordenada(Lista *l, int v); // função que insere de forma ordenada um elemento na lista
Lista *lst_ler_arquivo(char *nome_arquivo); // Função que ler de uma arquivo e armazena na lista encadeada de inteiros

int main() {
    Lista *lista = lst_cria();  // Cria uma lista encadeada vazia

    // Insere elementos na lista
    lista = lst_insere(lista, 42);
    lista = lst_insere(lista, 17);
    lista = lst_insere(lista, 65);
    lista = lst_insere(lista, 23);

    printf("Lista apos insercao de elementos:\n");
    lst_imprime(lista);
	printf("\n");

    // Verifica se a lista está vazia
    if (lst_vazia(lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("A lista nao esta vazia.\n");
    }
	printf("\n");

    // Busca um elemento na lista
    Lista *resultadoBusca = lst_busca(65, lista);
    if (resultadoBusca != NULL) {
        printf("Elemento %d encontrado na lista.\n", resultadoBusca->info);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }
	printf("\n");

    // Remove um elemento da lista
    lista = lst_retira(lista, 17);
    printf("Lista apos a remocao do elemento %d:\n", 17);
    lst_imprime(lista);
	printf("\n");

    // Insere um elemento de forma ordenada na lista
    int elementoOrdenado = 10;
    lista = lst_insere_ordenada(lista, elementoOrdenado);
    printf("Lista apos a insercao ordenada do elemento %d:\n", elementoOrdenado);
    lst_imprime(lista);
	printf("\n");

    // Libera a memória da lista
    lst_libera(lista);

    // Lê valores de um arquivo e insere na lista
    lista = lst_ler_arquivo("entrada.txt");
    printf("Lista apos a leitura do arquivo:\n");
    lst_imprime(lista);

    // Libera a memória da lista novamente
    lst_libera(lista);

    return 0;
}

struct lista
{
	int info;
	struct lista *prox;
};

// função que cria uma lista vazia (NULL)
Lista *lst_cria(void)
{
	return NULL;
}

// função que insere um elemento no início da lista
Lista *lst_insere(Lista *l, int v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	if (novo == NULL)
	{
		printf("[ERRO] memoria insuficiente!");
		exit(1);
	}
	novo->info = v;
	novo->prox = l;
	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

// função que verifica se a lista está vazia
int lst_vazia(Lista *l)
{
	return (l == NULL);
}

// função que imprime os elementos da lista
void lst_imprime(Lista *l)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		printf("\tInfo = %d \n", p->info);
	}
}

// função que busca um elemento na lista
Lista *lst_busca(int elemento, Lista *l)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		if (p->info == elemento)
			return p;
	}

	return NULL;
}

// função que retira um elemento da lista
Lista *lst_retira(Lista *l, int v)
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */
	Lista *p = l;	   /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)
	{
		if (p == NULL)
			return l; /* n�o achou: retorna lista original */
		ant = p;
		p = p->prox;
		/* verifica se achou elemento */
	}
	/* retira elemento */
	if (ant == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return l;
}

// função que libera a memória alocada para a lista
void lst_libera(Lista *l)
{
	Lista *p = l;
	Lista *t;
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

// função que insere de forma ordenada um elemento na lista
Lista *lst_insere_ordenada(Lista *l, int valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL) {
        perror("Erro ao alocar memória");
        exit(1);
    }
    novo->info = valor;
    novo->prox = NULL;

    if (l == NULL || valor < l->info) {
        novo->prox = l;
        return novo;
    }

    Lista *ant = NULL;
    Lista *atual = l;

    while (atual != NULL && valor > atual->info) {
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;

    return l;
}

// Função que ler de uma arquivo e armazena na lista encadeada de inteiros
Lista *lst_ler_arquivo(char *nome_arquivo)
{
	FILE *arquivo;
	int valor;
	Lista *l = lst_cria();
	arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)
	{
		l = lst_insere(l, valor);
	}
	fclose(arquivo);
	return l;
}