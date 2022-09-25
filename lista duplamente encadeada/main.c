#include "bodega.h"

int main()
{

    CatalogoBebidas bebidas = {NULL, NULL};
    CatalogoClientes clientes = {NULL, NULL};
    Cliente *cliente;
    Bebida *aux;
    Bebida *b;
    char name[40];
    int codigo, preco, estoque, conteudo, qtde, alcoolica;
    int cod, cpf, id, fiado, verifica;
    char nomeCliente[60];

    int escolha = 0, i = 1;
    while (i)
    {
        menu();
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            i = 0;
            break;
        case 1:
            b = NULL;
            printf("Digite o nome da bebida: ");
            scanf("%s", name);
            printf("Digite o preco da bebida: ");
            scanf("%d", &preco);
            printf("Digite a quantidade em estoque: ");
            scanf("%d", &estoque);
            printf("Digite o codigo da bebida: ");
            scanf("%d", &codigo);
            printf("Volume da garrafa: ");
            scanf("%d", &conteudo);
            printf("Essa bebida possui alcool? (1-s/0-n) ");
            scanf("%d", &alcoolica);
            b = verificaCadastroBebida(&bebidas, codigo);
            if(b == NULL){
                b = criaBebida(codigo, name, conteudo, estoque, preco, alcoolica);
                insereBebida(&bebidas, b);
                break;
            }
            printf("\nCodigo de bebida ja esta cadastrado\n\n");
            

            break;

        case 2:

            mostra_lista(&bebidas);

            break;

        case 3:
            printf("Informe o codigo da bebida a ser comprada: ");
            scanf("%d", &codigo);
            printf("Quantas garrafas pretende comprar? ");
            scanf("%d", &qtde);
            b = verificaCadastroBebida(&bebidas, codigo);
            if(b == NULL)
            {
                printf("\nBebida não esta cadastrada\n");    
                break;
            }

            comprarBebida(codigo, qtde, &bebidas);
        
            break;

        // parte de vender
        case 4:
            printf("Digite seu CPF: ");
            scanf("%d", &cpf);
            printf("Quantas garrafas? ");
            scanf("%d", &qtde);
            printf("Digite o codigo da bebida: ");
            scanf("%d", &cod);

            cliente = verificaCadastroCliente(&clientes, cpf);
            b = verificaCadastroBebida(&bebidas, cod);

            if (cliente == NULL)
            {
                printf("\n\nUsuario nao cadastrado\n\n");
                break;
            }
            if (b == NULL)
            {
                printf("\n\nBebida nao cadastrada\n\n");
                break;
            }
            if (qtde > b->estoque)
            {
                printf("\n\nNao possuimos essa quantia em estoque\n\n");
                break;
            }
            if (cliente->idade < 18 && b->alcoolica == 1)
            {
                printf("\n\nNao vendemos bebidas alcoolicas para menor de idade\n\n");
                break;
            }

            printf("\n\nVenda realizada\n%d garrafas vendidas\n\n", qtde);
            b->estoque -= qtde;

            break;

        case 5:

            printf("Digite seu Nome: ");
            scanf("%s", &nomeCliente);
            printf("Digite sua Idade: ");
            scanf("%d", &id);
            printf("Digite seu codigo: ");
            scanf("%d", &cod);
            printf("Digite seu CPF: ");
            scanf("%d", &cpf);
            printf("Vender fiado para esse cliente? (1-s/0-n) ");
            scanf("%d", &fiado);
            cliente = criaCliente(cod, nomeCliente, cpf, id, fiado);
            insereCliente(&clientes, cliente);
            break;

        case 6:

            mostraClientes(&clientes);

            break;
        default:
            break;
        }
    }

    return 0;
}