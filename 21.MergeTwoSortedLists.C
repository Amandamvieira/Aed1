#include <stdio.h>
#include <stdlib.h>

// Função de comparação para a função qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Função para encontrar a interseção de dois arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Ordena os arrays se não estiverem classificados
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            result[k++] = nums1[i++];
            j++;
        }
    }

    *returnSize = k;
    return result;
}

// Função principal para testar o código
int main() {
    int nums1[] = {4, 9, 5};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {9, 4, 9, 8, 4};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;
    int* result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Interseção: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
