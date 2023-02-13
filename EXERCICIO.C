//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

//You must implement a solution with a linear runtime complexity and use only constant extra space.

// Declaração da função
int singleNumber(int* nums, int numsSize);

#include <stdio.h>

/* No main criamos um vetor pra passar pra essa função,
 * e também temos que passar o tamanho do vetor.
 * nesse caso fiz um vetor com 9 valores e passei 9 pra função.
 */

int main(){

  int array[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
  int result = singleNumber(array, 9); //Result pega o retorno da função
  
  printf("A resposta é %d", result); 
  
  return 0;
}

int singleNumber(int* nums, int numsSize){
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans ^= nums[i];
    }
    return ans; 
}