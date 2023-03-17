//Amanda Jhennifer Marques Vieira

//MATRÍCULA: 20200831

//CiÊncia da computação

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

int isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    ListNode *prev = NULL, *temp;

    // Encontra o meio da lista pra fazr a comparação
    while (fast && fast->next) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // Se o tamanho da lista for impar, desconsidera o elemento do meio
    if (fast != NULL) {
        slow = slow->next;
    }

    // compara a primeira metade com a segunda metade da lista invertida
    while (slow != NULL) {
        if (prev->val != slow->val) {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

// solicitar pro usuario o numero de elementos que ele quer usar na lista para verificar se eh ou nao palindromo
int main() {
    int n;
    printf("Digite o numero de elementos da lista: ");
    scanf("%d", &n);

    // Cria a lista ligada a partir dos numeros digitados
    ListNode *head = NULL, *current = NULL;

    for (int i = 0; i < n; i++) {
        int num;
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &num);

        ListNode *node = (ListNode*) malloc(sizeof(ListNode));
        node->val = num;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }

    // Testa a funcao isPalindrome()
    if (isPalindrome(head)) {
        printf("A lista e um palindromo.\n");
    } else {
        printf("A lista nao e um palindromo.\n");
    }

    // libera a memoria  alocada p a lista     // inclusive eu nao tinha feito isso e quando fui testar no dr memory deu mto leak
    current = head;
    ListNode *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}