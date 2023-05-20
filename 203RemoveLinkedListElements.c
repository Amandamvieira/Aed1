//leetcode
//https://leetcode.com/problems/remove-linked-list-elements

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

// Função para remover elementos de uma lista encadeada
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* sen = (struct ListNode*)malloc(sizeof(struct ListNode));
    sen->next = head;
    struct ListNode* c = head;
    struct ListNode* p = sen;
    while (c) {
        if (c->val == val) {
            p->next = c->next;
            c = p->next;
            continue;
        }
        p = p->next;
        c = c->next;
    }
    return sen->next;
}

int main() {
    // Criação de uma lista encadeada de exemplo
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    // Chama a função removeElements para remover o valor 2 da lista
    head = removeElements(head, 2);

    // Imprime os elementos da lista atualizada
    struct ListNode* current = head;
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    // Libera a memória alocada pela lista encadeada
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}







