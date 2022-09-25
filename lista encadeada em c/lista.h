#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    char matricula[10];
    char nome[40];
    Data nasc;
    float notas;
    struct Aluno *next;

}Aluno;

//funcao que inicia a lista
Aluno *cria_lista(Aluno *);

//funcao que insere um elemento na lista
Aluno *cria_aluno(char n[], char m[], int day, int month, int year, float media);

//funcao que imprime a lista na ordem de inserção
void imprime_lista(Aluno *);

//funcao que imprime os atributos da struct em linha
void imprimeEmLinha(Aluno *);

//funcao que insere alunos na lista
Aluno *insere_lista(Aluno *, Aluno *);

//funcao que conta quantos elementos tem na lista
int contador(Aluno *);

//funcao que exclui um aluno da lista pela matricula
Aluno *excluir_aluno(Aluno *, char[]);

//funcao que limpa toda a memoria ocupada pela lista
void limpa_lista(Aluno *);

//imprime a lista de forma inversa e recusriva
void imprime_inversa(Aluno *);

//funcao que mostra as opçoes do menu
void menu();