#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 10

// Define a estrutura de uma pessoa
typedef struct {
    char nome[MAX_NAME_LEN + 1];
    int idade;
    int telefone;
} Pessoa;

// Define a estrutura de um nó da lista duplamente ligada
typedef struct node {
    void *data;
    struct node *next;
    struct node *prev;
} Node;

// Cria uma nova pessoa
Pessoa *criar_pessoa(char *nome, int idade, int telefone) {
    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    if (pessoa == NULL) {
        printf("Erro ao alocar memória para nova pessoa.\n");
        exit(1);
    }
    strncpy(pessoa->nome, nome, MAX_NAME_LEN);
    pessoa->nome[MAX_NAME_LEN] = '\0';
    pessoa->idade = idade;
    pessoa->telefone = telefone;
    return pessoa;
}

// Adiciona uma nova pessoa à lista ordenada alfabeticamente
void adicionar_pessoa(Node **head, Pessoa *nova_pessoa) {
    // Criar novo nó para a nova pessoa
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória para novo nó.\n");
        exit(1);
    }
    new_node->data = nova_pessoa;

    // Encontrar posição na lista para inserir a nova pessoa
    Node *current_node = (*head)->next;
    Node *previous_node = *head;
    while (current_node != NULL && strcasecmp(((Pessoa *)current_node->data)->nome, nova_pessoa->nome) < 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    // Inserir novo nó na lista
    previous_node->next = new_node;
    new_node->prev = previous_node;
    new_node->next = current_node;
    if (current_node != NULL) {
        current_node->prev = new_node;
    }
}

// Remove uma pessoa da lista pelo nome
void remover_pessoa(Node **head, char *nome) {
    Node *current_node = (*head)->next;
    while (current_node != NULL) {
        if (strcasecmp(((Pessoa *)current_node->data)->nome, nome) == 0) {
            // Remover nó da lista
            Node *previous_node = current_node->prev;
            Node *next_node = current_node->next;
            previous_node->next = next_node;
            if (next_node != NULL) {
                next_node->prev = previous_node;
            }
            free(current_node->data);
            free(current_node);
            return;
        }
        current_node = current_node->next;
    }
    printf("Pessoa com nome '%s' não encontrada.\n", nome);
}

// Busca uma pessoa na lista pelo nome e exibe suas informações
void buscar_pessoa(Node *head, char *nome) {
    Node *current_node = head->next;
    while (current_node != NULL) {
        if (strcasecmp(((Pessoa *)current_node->data)->nome, nome) == 0) {
            printf("Nome: %s\n", ((Pessoa *)current_node->data)->nome);
            printf("Idade: %d\n", ((Pessoa *)current_node->data)->idade);
            printf("Telefone: %d\n\n",((Pessoa *)current_node->data)->telefone);
        return;
    }
    current_node = current_node->next;
}
printf("Pessoa com nome '%s' não encontrada.\n", nome);
}

// Exibe todas as pessoas da lista
void listar_pessoas(Node *head) {
Node *current_node = head->next;
while (current_node != NULL) {
printf("Nome: %s\n", ((Pessoa *)current_node->data)->nome);
printf("Idade: %d\n", ((Pessoa *)current_node->data)->idade);
printf("Telefone: %d\n\n", ((Pessoa *)current_node->data)->telefone);
current_node = current_node->next;
}
}

int main() {
Node *head = (Node *)malloc(sizeof(Node));
if (head == NULL) {
printf("Erro ao alocar memória para nó cabeça.\n");
return 1;
}
head->data = NULL;
head->next = NULL;
head->prev = NULL;
int opcao;
char nome[MAX_NAME_LEN + 1];
int idade, telefone;

while (1) {
    printf("Selecione uma opção:\n");
    printf("1 - Adicionar pessoa\n");
    printf("2 - Remover pessoa\n");
    printf("3 - Buscar pessoa\n");
    printf("4 - Listar pessoas\n");
    printf("5 - Sair\n");
    printf("> ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o nome da pessoa: ");
            scanf("%s", nome);
            printf("Digite a idade da pessoa: ");
            scanf("%d", &idade);
            printf("Digite o telefone da pessoa: ");
            scanf("%d", &telefone);
            adicionar_pessoa(&head, criar_pessoa(nome, idade, telefone));
            break;
        case 2:
            printf("Digite o nome da pessoa a ser removida: ");
            scanf("%s", nome);
            remover_pessoa(&head, nome);
            break;
        case 3:
            printf("Digite o nome da pessoa a ser buscada: ");
            scanf("%s", nome);
            buscar_pessoa(head, nome);
            break;
        case 4:
            listar_pessoas(head);
            break;
        case 5:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

return 0;
}