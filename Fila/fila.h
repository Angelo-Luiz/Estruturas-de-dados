#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct elemFila{
    int item;
    struct elemFila *next;
};
typedef struct elemFila Elemento;

struct fila{
    Elemento *first;
    Elemento *last;
};

typedef struct fila Fila;

//cria elemento para inserir na fila
Elemento *cria_elemento(int);

//insere um elemento na fila
void insere_fila(Fila *, Elemento *);

//verifica se a fila esta vazia
void verifica(Fila *);

//remove algum elemento da fila
void remove_fila(Fila *);

//remove todos os elementos da fila
void limpa_fila(Fila *);







