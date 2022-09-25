#include "bodega.h"

Bebida *criaBebida(int cod, char name[], int cont, int stoq, int pre, int alc){
    Bebida *aux;
    aux = (Bebida *)malloc(sizeof(Bebida));
    aux->codigo = cod;
    strcpy(aux->nome, name);
    aux->conteudo = cont;
    aux->estoque = stoq;
    aux->preco = pre;
    aux->alcoolica = alc;
    aux->next = NULL;
    aux->prev = NULL;

    return aux;
}

Cliente *criaCliente(int cod, char name[], int cpf, int idade, int fiado){
    Cliente *aux;
    aux = (Cliente *)malloc(sizeof(Cliente));
    aux->codigo = cod;
    strcpy(aux->nome, name);
    aux->cpf = cpf;
    aux->idade = idade,
    aux->fiado = fiado;
    aux->next= NULL;
    aux->prev = NULL;

    return aux;
}


void insereBebida(CatalogoBebidas *cat, Bebida *gole){
    if(cat->first == NULL){
        cat->first = gole;
        cat->last = gole;
        return;
    }
    cat->last->next = gole;
    gole->prev = cat->last;
    cat->last = gole;

}

void insereCliente(CatalogoClientes *cat, Cliente *teu){
    if(cat->first == NULL){
        cat->first = teu;
        cat->last = teu;
        return;
    }
    cat->last->next = teu;
    teu->prev = cat->last;
    cat->last = teu;
}

void comprarBebida(int cod, int qtde, CatalogoBebidas *cat){
    Bebida *aux;
    for(aux = cat->first; aux != NULL; aux = aux->next)
    {
        if(aux->codigo == cod)
        {
            aux->estoque += qtde;
            printf("\nQuantidade comprada: %d\nQuantidade em estoque: %d\nNome: %s\n", qtde, aux->estoque, aux->nome);
            return;
        }
    }
    
}

void mostraClientes(CatalogoClientes *cat){
    Cliente *aux;
    for(aux = cat->first; aux != NULL; aux = aux->next){
        printf("\nNome: %s\nCodigo: %d\nIdade: %d\nCPF: %d\n\n", aux->nome, aux->codigo, aux->idade, aux->cpf);
    }
}



void mostra_lista(CatalogoBebidas *cat){
    Bebida *aux;
    for(aux = cat->first; aux != NULL; aux = aux->next)
    {
        printf("\nNome do Gole: %s\nCodigo: %d\nVolume Garrafa: %d\nQuantidade em estoque: %d\nPreço Garrafa: %d\n\n", aux->nome, aux->codigo, aux->conteudo, aux->estoque, aux->preco);
    }
}

void menu(){
    printf("\n\n");
    printf("Digite 1 para cadastrar uma bebida\n");
    printf("Digite 2 para mostrar o catalogo de bebidas\n");
    printf("Digite 3 para comprar uma bebida\n");
    printf("Digite 4 para vender uma bebida\n");
    printf("Digite 5 para cadastrar um cliente\n");
    printf("Digite 6 para mostrar a lista de clientes\n");
    printf("Digite 0 para sair do sistema\n");
    printf("\n\n");
}

Cliente *verificaCadastroCliente(CatalogoClientes *cat, int cpf){
    Cliente *aux;
    for(aux = cat->first; aux != NULL; aux = aux->next){
        if(aux->cpf == cpf) return aux;
    }
    return NULL;
}


Bebida *verificaCadastroBebida(CatalogoBebidas *cat, int cod){
    Bebida *aux;
    for(aux = cat->first; aux != NULL; aux = aux->next){
        if(aux->codigo == cod) return aux;
    }
    return NULL;
}