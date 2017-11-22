#include <stdio.h>
#include <stdlib.h>
#include "contatos.h"
#include <locale.h>
#include <windows.h>


int main()
{
    setlocale(LC_ALL,""); //Resolvendo problemas com acentuações
    ListaContatos *lista;
    lista = (ListaContatos *)malloc(sizeof(ListaContatos));
    iniciarLista(lista);
    menu(lista);
    return 0;
}
