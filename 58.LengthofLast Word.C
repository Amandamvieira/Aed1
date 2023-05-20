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

// Função para imprimir a lista encadeada
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Função para mesclar duas listas encadeadas classificadas
ListNode* mergeLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    ListNode* mergedHead;
    if (list1->val <= list2->val) {
        mergedHead = list1;
        mergedHead->next = mergeLists(list1->next, list2);
    } else {
        mergedHead = list2;
        mergedHead->next = mergeLists(list1, list2->next);
    }

    return mergedHead;
}

// Função principal para testar o código
int main() {
    // Criando as listas encadeadas de exemplo
    ListNode* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(7);

    ListNode* list2 = createNode(2);
    list2->next = createNode(5);
    list2->next->next = createNode(8);

    // Imprimindo as listas encadeadas originais
    printf("Lista 1: ");
    printList(list1);

    printf("Lista 2: ");
    printList(list2);

    // Mesclando as listas encadeadas
    ListNode* mergedList = mergeLists(list1, list2);

    // Imprimindo a lista encadeada mesclada
    printf("Lista mesclada: ");
    printList(mergedList);

    return 0;
}
