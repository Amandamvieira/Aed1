#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NODE_SIZE 38
#define PBUFFER_SIZE 22
#define TEMPNOME 10

#define IDADE 10
#define TELEFONE 14
#define ANTERIOR 18
#define PROXIMO 22

void *inserir(void *start, void *pBuffer);
void buscar(void *start);
void *excluir(void *start, void *pBuffer);

int main()
{
    SetConsoleOutputCP(65001);

    void *pBuffer = malloc(PBUFFER_SIZE);
    void *start = NULL;

    ((int *)pBuffer)[0] = 0; // switch case
    ((int *)pBuffer)[1] = 0; // contador de pessoas

    for(;;){

        printf("\n");
        printf("| 1- Incluir novo cadastro |\n");
        printf("| 2- Excluir cadastro      |\n");
        printf("| 3- Buscar                |\n");
        printf("| 4- Listar                |\n");
        printf("| 5- Sair                  |\n");
        scanf("%d", &((int *)pBuffer)[0]);
        getchar();
       ////////////////////cases//////////////////////

        switch (((int *)pBuffer)[0])
        {

        case 1:
            start = inserir(start, pBuffer);
            break;

        case 2:
            start = excluir(start, pBuffer);
            break;

        case 3:
            buscar(start);
            break;

        case 4:
            listar(start);
            break;

        case 5:
            exit(0);
            break;

        default:
            break;
        }

    }  

    free(pBuffer);
    free(start);
    return 0;
}
//inserir
void *inserir(void *start, void *pBuffer)
{
    void *nodo = malloc(NODE_SIZE);

    printf("\nInsira apenas o primeiro nome do novo usuário: ");
    scanf("%10s", (char *)nodo);
    getchar();

    printf("Insira a idade do novo usuário: ");
    scanf("%d", &*(int *)(nodo + IDADE));
    printf("Insira o telefone do novo usuário: ");
    scanf("%d", &*(int *)(nodo + TELEFONE));

    *(void **)(nodo + ANTERIOR) = NULL;

    *(void **)(nodo + PROXIMO) = NULL;

    if (start == NULL)
    {
        start = nodo;
        ((int *)pBuffer)[1]++;
        return start;
    }

    if ((strcmp((char *)start, (char *)nodo)) >= 0)
    {
        *(void **)(nodo + PROXIMO) = start;
        *(void **)(start + ANTERIOR) = nodo;
        start = nodo;
        ((int *)pBuffer)[1]++;
        return start;
    }

    void *atual = start;
    void *anterior = start;

    while (atual != NULL && (strcmp((char *)atual, (char *)nodo) <= 0))
    {
        anterior = atual;
        atual = *(void **)(atual + PROXIMO);
    }

    *(void **)(anterior + PROXIMO) = nodo;
    *(void **)(nodo + PROXIMO) = atual;
    *(void **)(nodo + ANTERIOR) = anterior;

    ((int *)pBuffer)[1]++;
    return start;
}
//excluir
void *excluir(void *start, void *pBuffer)
{
    if (start == NULL)
    {
        printf("Nenhum usuário cadastrado.\n");
        return start;
    }

    char tempNome[TEMPNOME];
    printf("Insira o primeiro nome do usuário que deseja excluir: ");
    scanf("%s", tempNome);

    void *atual = start;
    void *anterior = start;

    while (atual != NULL)
    {
        if (strcmp((char *)atual, tempNome) == 0)
        {
            if (atual == start)
            {
                start = *(void **)(start + PROXIMO);
            }
            else
            {
                *(void **)(anterior + PROXIMO) = *(void **)(atual + PROXIMO);
                if (*(void **)(atual + PROXIMO) != NULL)
                {
                    *(void **)(*(void **)(atual + PROXIMO) + ANTERIOR) = anterior;
                }
            }

            free(atual);
            ((int *)pBuffer)[1]--;
            printf("Usuário excluído com sucesso.\n");
            return start;
        }

        anterior = atual;
        atual = *(void **)(atual + PROXIMO);
    }

    printf("Usuário não encontrado.\n");
    return start;
}

//buscar
void buscar(void *start)
{
    if (start == NULL)
    {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }

    char tempNome[TEMPNOME];
    printf("Insira o primeiro nome do usuário que deseja buscar: ");
    scanf("%s", tempNome);

    void *atual = start;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (strcmp((char *)atual, tempNome) == 0)
        {
            printf("Nome: %s\n", (char *)atual);
            printf("Idade: %d\n", *(int *)(atual + IDADE));
            printf("Telefone: %d\n", *(int *)(atual + TELEFONE));
            printf("\n");
            encontrado = 1;
            break;
        }

        atual = *(void **)(atual + PROXIMO);
    }

    if (!encontrado)
    {
        printf("Usuário não encontrado.\n");
    }
}

//listar
void listar(void *start) {
    void *atual = start;
    while (atual != NULL) {
        printf("Nome: %s\n", (char *)atual);
        printf("Idade: %d\n", *(int *)(atual + IDADE));
        printf("Telefone: %d\n", *(int *)(atual + TELEFONE));
        printf("\n");
        atual = *(void **)(atual + PROXIMO);
    }
}
