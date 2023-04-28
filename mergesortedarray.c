#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=m-1, j=n-1, k;
    for (k=m+n-1; k>=0; k--) {
        if (i<0 || j<0) {
            break;
        }
        if (nums2[j] > nums1[i]) {
            nums1[k] = nums2[j];
            j--;
        } else {
            nums1[k] = nums1[i];
            i--;
        }
    }
    if (i>=0) {
        for(;i>=0; i--,k--){
            nums1[k]=nums1[i];
        }
    }
    if (j>=0) {
        for(;j>=0; j--,k--){
            nums1[k]=nums2[j];
        }
    }
}

int main() {
    int nums1[6] = {1,2,3,0,0,0};
    int m = 3;
    int nums2[3] = {2,5,6};
    int n = 3;

    merge(nums1, 6, m, nums2, 3, n);

    for (int i=0; i<6; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}