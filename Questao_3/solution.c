#include<stdio.h>
#include<stdlib.h>

int maxSubArray(int* nums, int numsSize){

    int tamanho = numsSize;
    
    if(tamanho == 0)
        return 0;
    
    int first = nums[0];
    
    int soma = first;
    int soma_in = first;
    
    for (int i=1; i<tamanho; ++i){
        
        if(soma_in + nums[i] >= nums[i])
            soma_in = soma_in + nums[i];
        
        else
            soma_in = nums[i];
        
        if(soma_in >= soma)
            soma = soma_in;
    }
    
    return soma;
}

int main(){
    printf("---------------------------\n");
    printf("Maximun Sub-arrey Problem\n");

    //Modifique aqui os valores de entrada, caso deseje;
    int input_1 = 9;
    int input_2[200] = {-2,1,-3,4,-1,2,1,-5,4};

    int resposta = maxSubArray(input_2, input_1);
    printf("Resultado: %d\n",resposta);
    printf("---------------------------\n");
}