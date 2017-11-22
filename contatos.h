int contador = -1;
typedef struct Contato{ //Estrutura que guarda um contato
    char nome[50];
    char email[50];
    int ddd;
    int telefone;
    int dia_nascimento;
    int mes_nascimento;
    int ano_nascimento;
    struct Contato *prox;
    struct Endereco *endereco;
}Contato;
typedef struct Endereco{ //Estrutura que guarda endereço
    char rua[50];
    char numero[50];
    char complemento[50];
    char bairro[50];
    int cep;
    char cidade[50];
    char estado[50];
    char pais[50];

}Endereco;
Endereco* criaEndereco(){//Retorna um endereço
    Endereco *endereco;
    endereco = (Endereco *)malloc(sizeof(Endereco));
    printf("Informe a Rua: "); //Rua
    fflush(stdin);
    gets(endereco->rua);

    printf("Informe o número: "); //Numero
    fflush(stdin);
    gets(endereco->numero);

    printf("Informe o Complemento: "); //Complemento
    fflush(stdin);
    gets(endereco->complemento);

    printf("Informe o Bairro: "); //Bairro
    fflush(stdin);
    gets(endereco->bairro);

    printf("Informe o Cep: "); //Cep
    fflush(stdin);
    scanf("%d", &endereco->cep);

    printf("Informe sua Cidade: ");//Cidade
    fflush(stdin);
    gets(endereco->cidade);

    printf("Informe seu Estado: ");//Estado
    fflush(stdin);
    gets(endereco->estado);

    printf("Informe o País: ");//País
    fflush(stdin);
    gets(endereco->pais);

    return endereco; //Retorna o endereço pronto
}
typedef struct ListaContatos{ //Lista com um elemento inicio e fim. (Ambos do tipo contato)
    Contato *inicio;
    Contato *fim;
}ListaContatos;
void iniciarLista(ListaContatos *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}
void adicionarContato(ListaContatos *lista){ //Adiciona um elemento na lista
    Contato *contato; //Cria um elemento contato
    contato = (Contato *)malloc(sizeof(Contato)); //Aloca memória pra ele
    contato->prox = NULL;
    printf("Dê um nome: ");
    fflush(stdin);
    gets(contato->nome);

    printf("Informe seu DDD: ");
    fflush(stdin);
    scanf("%d",&contato->ddd);

    printf("Informe o telefone: ");
    fflush(stdin);
    scanf("%d",&contato->telefone);

    printf("Informe o email: ");
    fflush(stdin);
    gets(contato->email);

    printf("Informe o dia do nascimento: ");
    fflush(stdin);
    scanf("%d",&contato->dia_nascimento);

    printf("Informe o mês do nascimento: ");
    fflush(stdin);
    scanf("%d",&contato->mes_nascimento);

    printf("Informe o ano do nascimento: ");
    fflush(stdin);
    scanf("%d",&contato->ano_nascimento);

    contato->endereco = criaEndereco();
    gravaNoArquivo(contato);
    if(lista->inicio == NULL){ //Caso a lista esteja vazia
        lista->inicio = contato;
        lista->fim = contato;
    }
    else{//Senão
        lista->fim->prox = contato;
        lista->fim = contato;
    }
}
void adicionarContatoDireto(ListaContatos *lista,Contato *contato){ //Adiciona um elemento na lista(Adiciona o elemento que é passado por argumento)
    if(lista->inicio == NULL){ //Caso a lista esteja vazia
        lista->inicio = contato;
        lista->fim = contato;
    }
    else{//Senão
        lista->fim->prox = contato;
        lista->fim = contato;
    }
}
void imprimirDados(ListaContatos *lista){ //Imprime todos os elementos da lista
    Contato *contato;
    contato = (Contato *)malloc(sizeof(Contato));
    contato = lista->inicio;
    if(contato==NULL){
        printf("A lista esta vazia!\n");
    }else{
        while(contato != NULL){
            printf("- %s\n",contato->nome);
            contato = contato->prox;
        }
    }
}
void visualizarContato(ListaContatos *lista){ //Visualiza todos os elementos da lista
    char nomei[50];
    char encontrado = 0; //1 para encontrado
    printf("Informe o nome que deseja visualizar: ");
    fflush(stdin);
    gets(nomei);
    Contato *contato;
    contato = (Contato *)malloc(sizeof(Contato));
    contato = lista->inicio;
    if(contato==NULL){
        printf("Lista vazia!\n");
    }else{
        while(contato != NULL){
            if(!strcmp(contato->nome,nomei)){
                printf("---------------------------------------------------\n");
                printf("Nome: %s\n", contato->nome);
                printf("Telefone: %d - %d\n",contato->ddd,contato->telefone);
                printf("Email: %s\n",contato->email);
                printf("Nascimento: %d\\%d\\%d\n",contato->dia_nascimento,contato->mes_nascimento,contato->ano_nascimento);
                printf("\t\tEndereço\n");
                printf("Rua: %s\n", contato->endereco->rua);
                printf("Bairro: %s\n", contato->endereco->bairro);
                printf("Complemento: %s\n", contato->endereco->complemento);
                printf("Cep: %d\n", contato->endereco->cep);
                printf("Número: %s\n", contato->endereco->numero);
                printf("Cidade: %s\n", contato->endereco->cidade);
                printf("Estado: %s\n", contato->endereco->estado);
                printf("País: %s\n", contato->endereco->pais);
                printf("---------------------------------------------------\n");
                encontrado = 1;
                break;
            }
            contato = contato->prox;
        }
    }
    if(encontrado==0){
        printf("Contato não encontrado\n");
    }
}
void removerContato(ListaContatos *lista){ //Remove elemento específico da lista
    char nomei[50];
    Contato *ant,*now;
    printf("Informe o nome do contato que você deseja remover: ");
    fflush(stdin);
    gets(nomei);
    if(lista->inicio == NULL){
        printf("A lista esta vazia\n");
    }
    else{
        ant = lista->inicio;
        now = lista->inicio;
        while(now!=NULL){
            if(!strcmp(now->nome,nomei)){
                if(now == lista->inicio){
                    lista->inicio = lista->inicio->prox;
                    free(now);//Desaloca o atual
                    break;
                }else{
                    if(now==lista->fim){
                        lista->fim = ant;
                    }
                    ant->prox = now->prox;
                    free(now);
                    break;
                }
            }
            else
                {
                ant = now;
                now = now->prox;
            }
        }
    }
}
void atualizarContato(ListaContatos *lista){ //Edita contato
    char nomei[50];
    int encontrado = 0, opcao = 0, opcao2 = 0;;
    printf("Informe o nome do contato que você deseja editar: ");
    fflush(stdin);
    gets(nomei);
    Contato *contato;
    contato = (Contato *)malloc(sizeof(Contato));
    contato = lista->inicio;
    if(contato==NULL){
        printf("Lista vazia!\n");
    }else{
        while(contato != NULL){
            if(!strcmp(contato->nome,nomei)){
                while(opcao!=6){
                    printf("Qual dado você deseja modificar: \n");
                    printf("1 - Nome\n2 - Telefone\n3 - Email\n4 - Data de nascimento\n5 - Endereço\n6 - Nenhum\n");
                    fflush(stdin);
                    scanf("%d",&opcao);
                    switch(opcao){
                        case 1:
                            system("cls");
                            printf("Informe o novo nome: ");
                            fflush(stdin);
                            gets(contato->nome);
                            break;
                        case 2:
                            system("cls");
                            printf("Informe o novo DDD: ");
                            fflush(stdin);
                            scanf("%d",&contato->ddd);
                            printf("Informe o novo Telefone: ");
                            fflush(stdin);
                            scanf("%d",&contato->telefone);
                            break;
                        case 3:
                            system("cls");
                            printf("Informe o novo email: ");
                            fflush(stdin);
                            gets(contato->email);
                            break;
                        case 4:
                            system("cls");
                            printf("Informe o dia do seu nascimento: ");
                            fflush(stdin);
                            scanf("%d",&contato->dia_nascimento);
                            printf("Informe o mês do seu nascimento: ");
                            fflush(stdin);
                            scanf("%d",&contato->mes_nascimento);
                            printf("Informe o ano do seu nascimento: ");
                            fflush(stdin);
                            scanf("%d",&contato->ano_nascimento);
                            break;
                        case 5:
                            while(opcao2!=10){
                                system("cls");
                                printf("O que deseja atualizar\n1 - Rua\n2 - Numero\n3 - Complemento\n4 - Bairro\n5 - Cep\n6 - Cidade\n7 - Estado\n8 - Pais\n9 - Todos\n10 - Sair");
                                scanf("%d",&opcao2);
                                switch(opcao2){
                                    case 1:
                                        system("cls");
                                        printf("Informe a nova Rua: "); //Rua
                                        fflush(stdin);
                                        gets(contato->endereco->rua);
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("Informe o novo numero: "); //Numero
                                        fflush(stdin);
                                        gets(contato->endereco->numero);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("Informe o novo Complemento: "); //Complemento
                                        fflush(stdin);
                                        gets(contato->endereco->complemento);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("Informe o novo Bairro: "); //Bairro
                                        fflush(stdin);
                                        gets(contato->endereco->bairro);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 5:
                                        system("cls");
                                        printf("Informe o novo Cep: "); //Cep
                                        fflush(stdin);
                                        scanf("%d", &contato->endereco->cep);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 6:
                                        system("cls");
                                        printf("Informe sua nova Cidade: ");//Cidade
                                        fflush(stdin);
                                        gets(contato->endereco->cidade);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 7:
                                        system("cls");
                                        printf("Informe seu novo Estado: ");//Estado
                                        fflush(stdin);
                                        gets(contato->endereco->estado);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 8:
                                        system("cls");
                                        printf("Informe o novo País: ");//País
                                        fflush(stdin);
                                        gets(contato->endereco->pais);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 9:
                                        system("cls");
                                        printf("Informe a nova Rua: "); //Rua
                                        fflush(stdin);
                                        gets(contato->endereco->rua);

                                        printf("Informe o novo numero: "); //Numero
                                        fflush(stdin);
                                        gets(contato->endereco->numero);

                                        printf("Informe o novo Complemento: "); //Complemento
                                        fflush(stdin);
                                        gets(contato->endereco->complemento);

                                        printf("Informe o novo Bairro: "); //Bairro
                                        fflush(stdin);
                                        gets(contato->endereco->bairro);

                                        printf("Informe o novo Cep: "); //Cep
                                        fflush(stdin);
                                        scanf("%d", &contato->endereco->cep);

                                        printf("Informe sua nova Cidade: ");//Cidade
                                        fflush(stdin);
                                        gets(contato->endereco->cidade);

                                        printf("Informe seu novo Estado: ");//Estado
                                        fflush(stdin);
                                        gets(contato->endereco->estado);

                                        printf("Informe o novo País: ");//País
                                        fflush(stdin);
                                        gets(contato->endereco->pais);
                                        system("cls");
                                        printf("Dado atualizado!\n");
                                        break;
                                    case 10:
                                        system("cls");
                                        break;
                                    default:
                                        system("cls");
                                        printf("Informe uma opção váliad!\n");
                                        break;
                                }
                            }
                            break;
                        case 6:
                            system("cls");
                            printf("Saindo\n");
                            Sleep(1000);
                            system("cls");
                            break;
                        default:

                            printf("Informe uma opção válida!\n");
                            break;
                    }
                }
                encontrado = 1;
                break;
            }
            contato = contato->prox;
        }
    }
    if(encontrado==0){
        system("cls");
        printf("Contato não encontrado\n");
    }
}
void menu(ListaContatos *lista){ //Imprime o menu na tela
    int opcao=0;
    while(opcao!=6){
        printf("\t\tAgenda v0.4\n");
        printf("Informe a ação que deseja realizar: \n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Visualizar contatos\n");
        printf("4 - Atualizar contato\n");
        printf("5 - Remover contato\n");
        printf("6 - Fechar agenda\n");
        fflush(stdin);
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                system("cls");
                adicionarContato(lista);
                system("cls");
                printf("Contato adicionado com sucesso!\n");
                Sleep(1000);
                system("cls");
                break;
            case 2:
                system("cls");
                imprimirDados(lista);
                break;
            case 3:
                system("cls");
                imprimirDados(lista);
                visualizarContato(lista);
                break;
            case 4:
                system("cls");
                imprimirDados(lista);
                atualizarContato(lista);
                break;
            case 5:
                system("cls");
                imprimirDados(lista);
                removerContato(lista);
                system("cls");
                printf("Contato removido com sucesso\n");
                Sleep(1000);
                system("cls");
                break;
            case 6:
                system("cls");
                printf("Programa finalizado!\n");
                break;
            default:
                system("cls");
                printf("Informe uma opção válida!\n");
                break;
        }
    }
}
void gravaNoArquivo(Contato *contato){ //Grava os dados no arquivo
    FILE *arquivo;
    arquivo = fopen("contatos.csv","a"); //Abre um arquivo pra gravação
        fprintf(arquivo, "%s;", contato->nome);
        fprintf(arquivo, "%s;", contato->email);
        fprintf(arquivo, "%d;", contato->ddd);
        fprintf(arquivo, "%d;", contato->telefone);
        fprintf(arquivo, "%d;", contato->dia_nascimento);
        fprintf(arquivo, "%d;", contato->mes_nascimento);
        fprintf(arquivo, "%d;", contato->ano_nascimento);
        fprintf(arquivo, "%s;", contato->endereco->rua);
        fprintf(arquivo, "%s;", contato->endereco->numero);
        fprintf(arquivo, "%s;", contato->endereco->complemento);
        fprintf(arquivo, "%s;", contato->endereco->bairro);
        fprintf(arquivo, "%d;", contato->endereco->cep);
        fprintf(arquivo, "%s;", contato->endereco->cidade);
        fprintf(arquivo, "%s;", contato->endereco->estado);
        fprintf(arquivo, "%s;", contato->endereco->pais);
        fprintf(arquivo,"\n");
    fclose(arquivo);
}


