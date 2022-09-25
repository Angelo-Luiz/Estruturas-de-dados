#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemPilha {
  char string[60];
  struct elemPilha *next;
};
typedef struct elemPilha Pilha;

struct elemento {
  Pilha *topo;
};
typedef struct elemento Topo;

Pilha *criaElemento(char caractere[]) {
  Pilha *aux;
  aux = (Pilha *)malloc(sizeof(Pilha));
  strcpy(aux->string, caractere);
  aux->next = NULL;

  return aux;
}

void inserePilha(Topo *t, Pilha *elemento) {
  Pilha *aux = elemento;
  if (t->topo == NULL) {
    t->topo = aux;
    // t->topo->next = NULL;
  } else {
    aux->next = t->topo;
    t->topo = aux;
  }
}

void removePilha(Topo *t) {
  Pilha *aux;
  aux = t->topo;
  if (aux == NULL) {
    printf("Vazio\n");
  } else {
    t->topo = t->topo->next;
    printf("%s\n", aux->string);
    free(aux);
  }
}

void mostraPilha(Topo *t) {
  Pilha *aux;
  for (aux = t->topo; aux != NULL; aux = aux->next) {
    printf("%s\n", aux->string);
  }
  printf("=======\n\n\n");
}

void limpaPilha(Topo *top) {
  Pilha *aux, *prev;
  for (aux = top->topo; aux != NULL; aux = aux->next) {
    prev = top->topo;
    top->topo = top->topo->next;
    printf("@");
    free(prev);
  }
}

int main(void) {

  Pilha *el;
  Topo topo = {NULL};
  int escolha, i = 1;
  char caractere[60];

  while (i) {

    scanf("%s", &caractere);
    if (caractere[0] == 'B') {
      removePilha(&topo);
      // mostraPilha(&topo);
    } else if (caractere[0] == 'E') {

      if (topo.topo == NULL) {
        printf("!");
        i = 0;
      }

      limpaPilha(&topo);
      i = 0;

    } else {
      el = criaElemento(caractere);
      inserePilha(&topo, el);
      // mostraPilha(&topo);
    }
  }

  return 0;
}