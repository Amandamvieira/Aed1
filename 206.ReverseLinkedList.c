//206. Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Função para criar um novo nó da lista encadeada
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no início da lista
void insertAtHead(ListNode** head, int val) {
    ListNode* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

// Função para imprimir a lista encadeada
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Função para inverter a lista encadeada
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Função principal para testar o código
int main() {
    ListNode* head = NULL;

    // Inserindo elementos na lista
    insertAtHead(&head, 5);
    insertAtHead(&head, 4);
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);

    // Imprimindo a lista original
    printf("Lista original: ");
    printList(head);

    // Invertendo a lista
    ListNode* reversedHead = reverseList(head);

    // Imprimindo a lista invertida
    printf("Lista invertida: ");
    printList(reversedHead);

    return 0;
}
