#include "lista.h"

Aluno *cria_lista(Aluno *a)
{
    return NULL;
}


Aluno *cria_aluno(char n[], char m[], int day, int month, int year, float media)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    strcpy(aluno->matricula, n);
    strcpy(aluno->nome, m);
    aluno->nasc.dia = day;
    aluno->nasc.mes = month;
    aluno->nasc.ano = year;
    aluno->notas = media;
    aluno->next = NULL;

    return aluno;
}





void imprime_lista(Aluno *a)
{
    Aluno *aux = a;

    if (aux == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        for (aux = a; aux != NULL; aux = aux->next)
        {
            printf("%s\n%s\n%d/%d/%d\n%.2f\n", aux->matricula, aux->nome, aux->nasc.dia, aux->nasc.mes,
                   aux->nasc.ano, aux->notas);
            printf("\n\n");
        }
    }
}





void imprimeEmLinha(Aluno *a)
{
    Aluno *aux = a;

    if (aux == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        for (aux = a; aux != NULL; aux = aux->next)
        {
            printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nasc.dia, aux->nasc.mes,
                   aux->nasc.ano, aux->notas);
            
        }
        
    }
    
}




Aluno *insere_lista(Aluno *first, Aluno *aluno)
{
    Aluno *aux = first;
    if (aux == NULL)
    {
        aux = aluno;
        first = aluno;
        return first;
    }
    else
    {
        for (aux = first; aux != NULL; aux = aux->next)
        {
            if (aux->next == NULL)
            {
                aux->next = aluno;
                aux = aluno;
            }
        }
        return first;
    }
}




int contador(Aluno *a)
{
    Aluno *aux;
    int cont = 0;
    for (aux = a; aux != NULL; aux = aux->next)
    {
        cont++;
    }
    return cont;
}





Aluno *excluir_aluno(Aluno *f, char n[])
{
    Aluno *aux , *previous_aux;
    aux = f;
    char string[10];
    strcpy(string, n);
    if (aux == NULL)
    {
        printf("Lista Vazia!\n");
    }

    for (aux = f; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->matricula, string) == 0)
        {
            if (aux == f)
            {
                f = f->next;
                break;
            }
            previous_aux->next = aux->next;
            aux = f;
            
        }

        previous_aux = aux;
    }
    return f;
}



void limpa_lista(Aluno *f){
    Aluno *aux, *previous_aux = f;

    while(previous_aux != NULL){
        aux = previous_aux;
        previous_aux = previous_aux->next;
        free(aux);
        printf("-");
    }

}

void imprime_inversa(Aluno *f){
    Aluno *aux = f;
    if(aux == NULL){
        printf("Lista Vazia!\n");
    }
    
    else if(aux->next == NULL){
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nasc.dia, aux->nasc.mes,
                   aux->nasc.ano, aux->notas);
    }
    else{
        imprime_inversa(aux->next);
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nasc.dia, aux->nasc.mes,
                   aux->nasc.ano, aux->notas);
        

    }
    
}


void menu(){
    printf("Opção 1: Incluir elemento na lista;\n");
    printf("Opção 2: Excluir elemento da lista;\n");
    printf("Opção 3: Listar todos os elementos da lista na ordem de inclusão;\n");
    printf("Opção 4: Listar todos os elementos da lista na ordem inversa de inclusão;\n");
    printf("Opção 5: Apresentar quantos elementos existem na lista;\n");
    printf("Opção 0: Sair do programa;\n");

}