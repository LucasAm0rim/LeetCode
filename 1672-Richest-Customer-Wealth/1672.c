#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int** accounts, int accountsSize, int accountsColSize) {
    int i = 0;
    int j = 0;
    int k = 0;
    int richest = 0;
    int wealth[51] = {0};
    //int * wealth = calloc(accountsSize + 1, sizeof(int));
    
    for (i = 0; i < accountsSize; i++){
        for (j = 0; j < accountsColSize; j++){
            wealth[k] = accounts[i][j] + wealth[k]; 
        }
        k++;
    }

    k = 0;
    richest = wealth[0];
    while (wealth[k] != 0){
        if (wealth[k] > richest){
            richest = wealth[k];
        }
        k++;
    }

    return richest;
}

int main(int argc, char *argv[]){

    int richest = 0;
    int accountsSize = 3;
    int accountsColSize = 3;
    int ** accounts;
    
    // Allocating memory for an array of ints, it must be sizeof(int *)
    // It is not necessary to include + 1 byte for the NULL byte. This is only needed when dealing with strings
    accounts = calloc(accountsSize, sizeof(int *));
    if (accounts == NULL){
        printf("Malloc Failed.\n");
        return -1;
    }

    for (int i = 0; i < accountsSize; i++){
        accounts[i] = calloc(accountsColSize, sizeof(int));
        if (accounts[i] == NULL){
            printf("Malloc Failed (2).\n");
            return -1;
        }
    }

    printf("Inserted Numbers: ");
    int N = 10;
    for (int i = 0; i < accountsSize; i++){
        for (int j = 0; j < accountsColSize; j++){
            accounts[i][j] = rand() % (N + 1);
            printf("%d ", accounts[i][j]);
        }
        printf("| ");
    }

    richest = maximumWealth(accounts, accountsSize, accountsColSize);

    printf("\nRichest Customer: %d\n", richest);
    return 0;
}
