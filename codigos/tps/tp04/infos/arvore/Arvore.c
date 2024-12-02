// ÁRVORE BINÁRIA EM C

/* PONTEIROS

- São variáveis que armazenam um endereço de memória.

- Da mesma forma que um int armazena inteiro; um double, número real; um ponteiro
  armazena um endereço de memória.

- Os ponteiros possuem tipo,, ou seja, temos ponteirospara endereços de memória
  de um int, de um float de um char...

- + O asterisco na declaração de uma variável indica que essa não guardará um valor
  | e sim um endereço para o tipo especificado.
  +--> tipoPonteiro *nomeVariável;

- Operador endereço (&) determina o endereço de uma variável.
- Operador de conteúdo de um ponteiro (*) determina o conteúdo da posição de
  memória endereçada pelo ponteiro.

- + O malloc aloca o número de bytes passados como parâmetro e retorna um ponteiro
  | para a primeira posição da área alocada.
  +--+ Protótipo da função malloc(): 'void* malloc (int tamanho)'
     +-- Ex:
            • char* p1 = (char*) malloc (sizeof(char));
            • int* p2 = (int*) malloc (sizeof(int));
            • float* p3 = (float*) malloc (sizeof(float));
            • Cliente* p4 = (Cliente*) malloc (sizeof(Cliente));
            • int* p5 = (int*) malloc (MAXTAM * sizeof (int));
            • Cliente* p6 =(Cliente*) malloc (MAXTAM * sizeof (Cliente));

- + O free desaloca o espaço de memória apontado pelo ponteiro recebido como
  | parâmetro.
  +--+ Protótipo da função free(): 'void free (void*)'
     +-- Ex:  
            • free(p1);
            • free(p2);
            • free(p3);
            • free(p4);
            • free(p5);
            • free(p6);

----------------=------------------------------------------------------------------
+-----------------------+
| Registro vs. Ponteiro |
+-----------------------+

- Acessamos um atributo de um registro fazendo 'registro.atributo'

- Acessamos um atributo de um registro apontado por um ponteiro fazendo
  'ponteiro->atributo'

  ```
  Cliente registro; 
  Cliente* ponteiro = (Cliente*) malloc (sizeof(Cliente)); 

  registro.codigo = 1; 
  strcpy(registro.nome, “AA”); 
  printf(“\nCliente (%i): %s”, registro.codigo, registro.nome); 

  ponteiro->codigo = 2; 
  strcpy(ponteiro->nome, “BB”); 
  printf(“\nCliente (%i): %s”, ponteiro->codigo, ponteiro->nome)
  ```

*/

/* ESTRUTURA DE ARQUIVOS

• no.h
• no.c
• arvorebinaria.h
• arvorebinaria.c
• principal.c
• makefile

*/

/* MAKEFILE

- Arquivo contendo um conjunto de diretivas usadas pela ferramenta de automação de
  compilação make para gerar um alvo / meta.

- Nesse caso, os arquivos serão compilados digitando make.

    all: exec

    exec: principal.o arvorebinaria.o no.o
        gcc -o exec principal.o arvorebinaria.o no.o
  
    principal.o: principal.c
        gcc -o principal.o principal.c -c -W -Wall -ansi -pedantic
  
    arvorebinaria.o: arvorebinaria.c
        gcc -o arvorebinaria.o arvorebinaria.c -c -W -Wall -ansi -pedantic

    no.o: no.c
        gcc -o no.o no.c -c -W -Wall -ansi -pedantic

    clean:
        rm -rf *.o *~ exec

    limpa: 
        rm -rf *.o


- Alvos:                     - Pré-requisitos:
        > all:                                > exec
        > exec:                               > principal.o arvorebinaria.o no.o
        > principal.o:                        > principal.c
        > arvorebinaria.o:                    > arvorebinaria.c
        > no.o:                               > no.c
        > clean:                             
        > limpa:                              

- Comandos:
        > gcc -o exec principal.o arvorebinaria.o no.o
        > gcc -o principal.o principal.c -c -W -Wall -ansi -pedantic
        > gcc -o arvorebinaria.o arvorebinaria.c -c -W -Wall -ansi -pedantic
        > gcc -o no.o no.c -c -W -Wall -ansi -pedantic
        > rm -rf *.o *~ exec
        > rm -rf *.o

- Na pasta da árvore em C, digite a sequência de comandos abaixo e explique a
  saída

------
  > make all ; ls 
  > make clean ; ls 

    ```
    :$  make all ; ls
    
    gcc -o principal.o principal.c -c -W -Wall -ansi -pedantic 
    gcc -o arvorebinaria.o arvorebinaria.c -c -W -Wall -ansi -pedantic 
    gcc -o no.o no.c -c -W -Wall -ansi -pedantic 
    gcc -o exec principal.o arvorebinaria.o no.o 
    
    arvorebinaria.c  arvorebinaria.h  arvorebinaria.o  exec  makefile   
    no.c  no.h  no.o  principal.c  principal.o 
    
    :$  make clean ; ls 
    
    rm -rf *.o *~ exec 
    arvorebinaria.c  arvorebinaria.h  makefile  no.c  no.h  principal.c
    ```

------
  > make ; ls 
  > make clean ; ls 

    ```
    :$  make ; ls

    gcc -o principal.o principal.c -c -W -Wall -ansi -pedantic
    gcc -o arvorebinaria.o arvorebinaria.c -c -W -Wall -ansi -pedantic
    gcc -o no.o no.c -c -W -Wall -ansi -pedantic
    gcc -o exec principal.o arvorebinaria.o no.o

    arvorebinaria.c  arvorebinaria.h  arvorebinaria.o  exec  makefile  
    no.c  no.h  no.o  principal.c  principal.o

    :$  make clean ; ls

    rm -rf *.o *~ exec
    
    arvorebinaria.c  arvorebinaria.h  makefile  no.c  no.h  principal.c
    ```

------
  > make exec ; ls 
  > make limpa ; ls 

    ```
    :$  make exec ; ls

    gcc -o principal.o principal.c -c -W -Wall -ansi -pedantic
    gcc -o arvorebinaria.o arvorebinaria.c -c -W -Wall -ansi -pedantic
    gcc -o no.o no.c -c -W -Wall -ansi -pedantic
    gcc -o exec principal.o arvorebinaria.o no.o

    arvorebinaria.c  arvorebinaria.h  arvorebinaria.o  exec  makefile  
    no.c  no.h  no.o  principal.c  principal.o

    :$  make limpa ; ls

    rm -rf *.o *
    
    arvorebinaria.c  arvorebinaria.h  exec makefile  no.c  no.h  
    principal.c
    ```

------
  > make no.o ; ls
    
    ```
    :$  make no.o ; ls
    
    gcc -o no.o no.c -c -W -Wall -ansi -pedantic
    
    arvorebinaria.c  arvorebinaria.h  arvorebinaria.o  exec  makefile  
    no.c  no.h  no.o  principal.c  principal.o
    ```
*/

/* ARQUIVOS "NO"

--------
// no.h

typedef struct No {
    int elemento;
    struct No *esq, *dir;
} No;

No* novoNo(int);

--------
// no.c

#include <stdlib.h>
#include "no.h"

No* novoNo(int elemento) {
    No* novo = (No*) malloc(sizeof(No));
    
    novo->elemento = elemento;
    novo->esq = NULL;
    novo->dir = NULL;
    
    return novo;
}
*/

/* ARQUIVOS "ARVOREBINÁRIA"

--------
//arvorebinaria.h

#include "no.h"
#define bool   short
#define true   1
#define false  0

bool pesquisarRec(int, No*);
void caminharCentralRec(No*);
void caminharPreRec(No*);
void caminharPosRec(No*);
void inserirRec(int, No**);
void removerRec(int, No**);
void maiorEsq(No**, No**);

void start();
bool pesquisar(int);
void caminharCentral();
void caminharPre();
void caminharPos();
void inserir(int);
void remover(int);

--------
//arvorebinaria.c

#include "no.h"
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include "arvorebinaria.h"

No* raiz;

void start() {
    raiz = NULL;
}

--------

- Como o C tem apenas a passagem de parâmetros por valor, neste material, optamos
  por fazer a inserção usando o endereço de ponteiro.

- Poderíamos, também, usar as duas estratégias implementadas em nosso código Java.

- Anteriormente, em Java, apresentamos duas implementações do inserir()
        No inserir(int x, No i) //Java
        void inserir(int x, No i, No pai) //Java

- As implementações correspondentes em C seriam, respectivamente:
        No* inserir(int x, No* i) //C
        void inserir(int x, No* i, No* pai) //C


//código em Java                            //código em C                                   //código em C

void inserir(int x) {                       void inserir(int x) {                           void inserir(int x) {
    raiz = inserir(x, raiz);                    raiz = inserirRec(x, raiz);                     raiz = inserirRec(x, &raiz);
}                                           }                                               }

No inserir(int x, No i) {                   No* inserirRec(int x, No* i) {                  void inserirRec(int x, No* i) {  
    if (i == null) {                            if (i == NULL) {                                if (*i == NULL) {
        i = new No(x);                              i = novoNo(x);                                  *i = novoNo(x);
    } else if (x < i.elemento) {                } else if (x < i->elemento) {                   } else if (x < (*i)->elemento) {
        i.esq = inserir(x, i.esq);                  i->esq = inserirRec(x, i->esq);                 i->esq = inserirRec(x, &(*i)->esq);  
    } else if (x > i.elemento) {                } else if (x > i->elemento) {                   } else if (x > (*i)->elemento) {      
        i.dir = inserir(x, i.dir);                  i->dir = inserirRec(x, i->dir);                 i->dir = inserirRec(x, &(*i)->dir); 
    } else {                                    } else {                                        } else {   
        throw new(“Erro!”);                         errx(1, "Erro ao inserir!");                    errx(1, "Erro ao inserir!");
    }                                           }                                               }
    return i;                                   return i;                                       return i;
}                                           }                                               }


//código em Java                            //código em C

void inserirPai(int x) {                    void inserirPai(int x) {
    if (raiz == null) {                         if(raiz == NULL){
        raiz = new No(x);                            raiz = novoNo(x);
    } else if (x < raiz.elemento) {             } else if(x < raiz->elemento) {
        inserirPai(x, raiz.esq, raiz);               inserirPaiRec(x, raiz->esq, raiz);
    } else if (x > raiz.elemento) {             } else if(x > raiz.elemento) {
        inserirPai(x, raiz.dir, raiz);               inserirPaiRec(x, raiz->dir, raiz);
    } else {                                    } else {    
        throw new(“Erro!”);                          errx(1, "Erro ao inserir!"); 
    }                                           }
}                                           }
  
void inserirPai(int x, No i, No pai) {      void inserirPaiRec(int x, No* i, No* pai) {
    if (i == null) {                            if (i == NULL) {
        If (x < pai.elemento) {                     if(x <pai->elemento) {
            pai.esq = new No(x);                        pai->esq = novoNo(x);
        } else {                                    } else { 
            pai.dir = new No(x);                        pai->dir = novoNo(x); 
        }                                           }
    } else if (x < i.elemento) {                } else if (x < i->elemento) {
        inserirPai(x, i.esq, i);                    inserirPaiRec(x, i->esq, i);
    } else if (x > i.elemento) {                } else if (x > i->elemento) {
        inserirPai(x, i.dir, i);                    inserirPaiRec(x, i->dir, i);
    } else {                                    } else { 
        throw new(“Erro!”);                         errx(1, "Erro ao inserir!");
    }                                           }
}                                           }

*/

#include <stdio.h>
#include <stdlib.h>

#define bool   short
#define true   1
#define false  0

typedef struct No {
    int elemento;
    struct No *esq, *dir;
} No;

No* novoNo(int elemento) {
    No* novo = (No*) malloc(sizeof(No));
    
    novo->elemento = elemento;
    novo->esq = NULL;
    novo->dir = NULL;
    
    return novo;
}

bool pesquisarRec(int, No*);
void caminharCentralRec(No*);
void caminharPreRec(No*);
void caminharPosRec(No*);
/* void inserirRec(int, No**);
void removerRec(int, No**);
void maiorEsq(No**, No**); */

void start();
bool pesquisar(int);
void caminharCentral();
void caminharPre();
void caminharPos();
void inserir(int);
void remover(int);

No* raiz;

void start() {
    raiz = NULL;
}

void inserir(int x) {
    raiz = inserirRec(x, raiz);             // raiz = inserirRec(x, &raiz);
}

No* inserirRec(int x, No* i) {              //  void inserirRec(int x, No** i) {
    if (i == NULL) {                        //      if (*i == NULL) {
        i = novoNo(x);                      //          *i = novoNo(x)
    } else if (x < i->elemento) {           //      } else if (x < (*i)->elemento) {
        i->esq = inserirRec(x, i->esq);     //          inserirRec(x, &((*i)->esq));
    } else if (x > i->elemento) {           //      } else if (x > (*i)->elemento) {
        i->dir = inserirRec(x, i->dir);     //          inserirRec(x, &((*i)->dir));
    } else {                                
        errx(1, "Erro ao inserir!");
    }
    return i;
}

void inserirPai(int x) {
    if(raiz == NULL) {
        raiz = novoNo(x);
    } else if(x < raiz->elemento) {
        inserirPaiRec(x, raiz->esq, raiz);
    } else if(x > raiz.elemento) {
        inserirPaiRec(x, raiz->dir, raiz);
    } else {
        errx(1, "Erro ao inserir!");   
    }
}
void inserirPaiRec(int x, No* i, No* pai) {
    if (i == NULL) {
        if(x <pai->elemento){ pai->esq = novoNo(x);
        } else {                    
            pai->dir = novoNo(x); 
        }
    } else if (x < i->elemento) {
        inserirPaiRec(x, i->esq, i);
    } else if (x > i->elemento) {
        inserirPaiRec(x, i->dir, i);
    } else {  
        errx(1, "Erro ao inserir!");
    }   
}