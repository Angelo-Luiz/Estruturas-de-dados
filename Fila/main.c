#include "fila.h"

int main(){
    Fila fila = {NULL, NULL};
    Elemento *el, *aux;
    //verifica(&fila);

    for(int i = 0; i<10; i++)
    {
        el = cria_elemento(i);
        insere_fila(&fila, el);
    }


    for(aux = fila.first; aux != NULL; aux = aux->next){
        verifica(&fila);
        printf("Elemento %d\n", aux->item);
    }
    //verifica(&fila);
    limpa_fila(&fila);




}