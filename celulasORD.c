#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pair {
    int x;
    int y;
    int dis;
};

int cmp(const void* a, const void* b) {
    struct pair pa = *(const struct pair*) a;
    struct pair pb = *(const struct pair*) b;
    return pa.dis - pb.dis;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int arrSize = rows * cols;
    *returnSize = arrSize;
    *returnColumnSizes = (int*) malloc((*returnSize) * sizeof(int));
    for(int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }
    
    struct pair* arr = (struct pair*) calloc(arrSize, sizeof(struct pair));
    int idx = 0;
    for(int i = 0; i < rows; i++) {
        int rdis = abs(rCenter - i);
        for(int j = 0; j < cols; j++) {
            arr[idx].y = i;
            arr[idx].x = j;
            arr[idx].dis = rdis + abs(cCenter - j);
            idx++;
        }
    }
    qsort(arr, arrSize, sizeof(struct pair), cmp);
    int** res = (int**) malloc((*returnSize) * sizeof(int*));
    for(int i = 0; i < (*returnSize); i++) {
        res[i] = (int*) malloc(2 * sizeof(int));
        res[i][0] = arr[i].y;
        res[i][1] = arr[i].x;
    }
    free(arr);
    return res;
}

int main() {
    int rows = 2;
    int cols = 3;
    int rCenter = 1;
    int cCenter = 2;
    int returnSize;
    int* returnColumnSizes;
    int** res = allCellsDistOrder(rows, cols, rCenter, cCenter, &returnSize, &returnColumnSizes);
    printf("Result:\n");
    for(int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", res[i][0], res[i][1]);
    }
    printf("\n");
    for(int i = 0; i < returnSize; i++) {
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);
    return 0;
}