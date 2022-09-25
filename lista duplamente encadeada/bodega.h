#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bebida{
    int codigo;
    char nome[40];
    int conteudo;
    int preco; 
    int estoque;
    int alcoolica;
    struct bebida *next;
    struct bebida *prev;
};
typedef struct bebida Bebida;


struct listaBebida{
    Bebida *first;
    Bebida *last;
};
typedef struct listaBebida CatalogoBebidas;


struct empresa{
    char nome[40];
    int cnpj;
};
typedef struct empresa Empresa;


struct cliente{
    int codigo;
    char nome[40];
    int cpf;
    int idade;
    int fiado;
    struct cliente *next;
    struct cliente *prev;
};
typedef struct cliente Cliente;

struct listaClientes{
    Cliente *first;
    Cliente *last;
};
typedef struct listaClientes CatalogoClientes;




//cria uma bebida com seus ponteiros apontando pra NULL
Bebida *criaBebida(int, char name[], int, int, int, int);

//cria uma cliente com seus ponteiros apontando pra NULL
Cliente *criaCliente(int, char name[], int, int, int);

//insere uma bebida no catalogo da bodega
void insereBebida(CatalogoBebidas *, Bebida *);

//insere um cliente no catalogo da bodega
void insereCliente(CatalogoClientes *, Cliente *);

//funçao que compra bebida
void comprarBebida(int, int, CatalogoBebidas *);

//funçao que mostra o catalogo de bebidas
void mostra_lista(CatalogoBebidas *);

//funçao que mostra lista de clientes
void mostraClientes(CatalogoClientes *);

//mostra as opçoes do menu
void menu();

//funcao que verifica e efetua a venda de uma bebida
void venderBebida(CatalogoBebidas *, Cliente *, int, int, int);

//verifica se o usuario esta cadastrado
Cliente *verificaCadastroCliente(CatalogoClientes *, int);

//verifica se a bebida esta cadastrada
Bebida *verificaCadastroBebida(CatalogoBebidas *, int);

