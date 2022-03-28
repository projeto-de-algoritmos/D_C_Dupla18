#include <stdio.h>
#include <stdlib.h>
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (B<A) exch(A,B); }

/*int separa(int *V,int l,int r){
  int c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(V[k]<c)
    {
      exch(V[k],V[j]);
      j++;
    }
  exch(V[j],V[r]);
  return j;
}

int quickselect(int *V, int l, int r, int pos){
	int j = separa(V,l,r);
	if(j>pos)
		return quickselect(V,l,j-1,pos);
	else if(j<pos)
		return quickselect(V,j+1,r,pos);
	return j;
	
}
*/

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}


int findKthLargest(int* nums, int numsSize, int k){

    mergeSort(nums,0,numsSize-1); 
    //quickselect(nums,0,numsSize-1,k);
   
    // Print do vetor ordenado
    /*
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d - ",nums[i]);
    }*/
    
    k = numsSize - k;

   return nums[k];

}



int main(){
    printf("Kth Largest Element\n");

    //Modifique aqui os valores de entrada, caso deseje;

    // Input 1 do leetCode
    int k = 2;
    int nums[] = {3,2,1,5,6,4};
    int numsSize = 6;
    /* Input 2 do leetCode
    int k = 4;
    int nums[] = {3,2,3,1,2,4,5,5,6};
    int numsSize = 9;*/

    int resposta = findKthLargest(nums, numsSize, k);
    printf("\nResultado: %d\n",resposta);
  

    return 0;
}