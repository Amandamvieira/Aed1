//leetcode https://leetcode.com/problems/reorder-list/description/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* nxt;
    
    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    return prev;
}

void reorderList(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct ListNode* first = head;
    struct ListNode* second = slow->next;
    slow->next = NULL;
    second = reverse(second);
    
    struct ListNode* temp1;
    struct ListNode* temp2;
    
    while (second != NULL) {
        temp1 = first->next;
        first->next = second;
        temp2 = second->next;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

int main() {
    // Exemplo de uso da função reorderList
    
    // Criação dos nós da lista
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    // Atribuição dos valores e ligações entre os nós
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    
    // Chamada da função para reordenar a lista
    reorderList(node1);
    
    // Impressão da lista reordenada
    struct ListNode* current = node1;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
    
    // Liberação da memória alocada pelos nós
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    
    return 0;
}