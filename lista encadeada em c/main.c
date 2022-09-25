#include "lista.h"

int main(){

    Aluno *aux, *first = NULL;
    int escolha, dia, mes, ano, i = 1;
    float media;
    char mat[10];
    char name[40];
    while(i){
       // menu  ();
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 0:
                limpa_lista(first);
                first = NULL;
                printf("\n\n");
                i = 0;
                break;
            
            case 1:
                scanf("%s", &mat);
                scanf("%s", &name);
                scanf("%d/%d/%d", &dia, &mes, &ano);
                scanf("%f", &media);
                aux = cria_aluno(mat, name, dia, mes, ano, media);
                first = insere_lista(first, aux);
                break;

            case 2:
                if(first == NULL){
                    printf("Lista Vazia!\n");
                    break;
                }
                scanf("%s", &name);
                first = excluir_aluno(first, name);
                break;

            case 3:
                imprimeEmLinha(first);
                break;

            case 4:
                imprime_inversa(first);
                break;

            case 5:
                printf("%d\n", contador(first));
                break;

            default:
                break;     
    
        }

    }

    
    return 0;
}