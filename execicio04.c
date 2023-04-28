//Amanda Jhennifer Marques Vieira
//20200831

//Você recebe um vetor de inteiro nums e um inteiro k. Você deseja encontrar uma subsequência em
//nums de comprimento k que tenha a maior soma.
//Retorne a subsequência como uma matriz de inteiros com comprimento k.
//Uma subsequência é uma matriz que pode ser extraída de outra matriz excluindo alguns ou nenhum
//elemento sem alterar a ordem dos elementos restantes.


#include <stdio.h>
#include <stdlib.h>

void merge(int ar[], int l, int m, int r) {
    // implementando o merge 
}

void mergeSort(int ar[], int l, int r) {
    // implementação do merge sort
}

int* valMaxSubseq(int nums[], int n, int k) {
    int* subseq = (int*) malloc(sizeof(int) * k);
    mergeSort(nums, 0, n-1);
    int i = n - 1;
    int j = k - 1;
    int sum = 0;
    while (j >= 0) {
        subseq[j] = nums[i];
        sum += nums[i];
        i--;
        j--;
    }
    printf("A subsequencia %d com a maior soma e: ", k);
    for (i = 0; i < k; i++) {
        printf("%d ", subseq[i]);
    }
    printf("\n");
    return subseq;
}

//  para o usuario 
int main() {
    int n, k;
    printf("Informe o tamanho da sequencia: ");
    scanf("%d", &n);

    int nums[n];
    printf("Informe a sequencia:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Informe o tamanho da subsequencia a ser encontrada: ");
    scanf("%d", &k);

    int* subseq = valMaxSubseq(nums, n, k);
    free(subseq);
    return 0;

}

