#include "fila.h"

void insere_fila(Fila *f, Elemento *element){
    Elemento aux;
    if(f->first == NULL){
        f->first = element;
        f->last = element;
    }
    else{
        f->last->next = element;
        f->last = element;
    }
}

Elemento *cria_elemento(int valor){
    Elemento *aux; 
    aux = (Elemento *)malloc(sizeof(Elemento));
    aux->item = valor;
    aux->next = NULL;
    return aux;
}

void verifica(Fila *f){
    if(f->first == NULL)
    {
        printf("Fila Vazia!\n");
    }
    else{
        printf("Fila contem elementos\n");
    }
}


void remove_fila(Fila *f){
    Elemento *aux = f->first;
   f->first = f->first->next;
   free(aux);

}

void limpa_fila(Fila *f){
    Elemento *aux;
    while(f->first != NULL)
    {
        aux = f->first;
        f->first = f->first->next;
        printf("removendo elemento %d\n",aux->item);
        free(aux);
    }
        
    
}