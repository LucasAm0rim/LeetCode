#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

// This is probably my ugliest code so far;
// It is possible to do it in a much cleaner way, but for now thats enough;
// Ideas: Not asking the user the AccountsSize and AccountsColSize, only the AccountsValue.

int maximumWealth(int** accounts, int accountsSize, int accountsColSize) {
    int i = 0;
    int j = 0;
    int k = 0;
    int richest = 0;
    int wealth[51] = {0};
    
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

void print_usage(char *argv[]){
    printf("Usage: %s -a <Accounts> -s <AccountsSize> -c <AccountsColumnSize>\n", argv[0]);
    printf("Example: %s -a 1,2,3,4,5,6 -s 2 -c 3\n", argv[0]);
}

int main(int argc, char *argv[]){

    int richest = 0;
    int accountsSize = 0;
    int accountsColSize = 0;
    int c;

    char * acc = NULL;
    char * accSize = NULL;
    char * accColSize = NULL;

    while ((c = getopt(argc,argv,"a:s:c:")) != -1){
        switch (c){
            case 'a':
                acc = optarg;
                break;
            case 's':
                accSize = optarg;
                break;
            case 'c':
                accColSize = optarg;
                break;
            case '?':
                break;
            
            default:
                return -1;
        }
    }
    
    if (acc && accSize && accColSize){
        // Allocating memory for an array of ints, it must be sizeof(int *)
        // It is not necessary to include + 1 byte for the NULL byte. 
        // This is only needed when dealing with strings
        int i = 0;
        char *endptr;
    
        accountsSize = strtol(accSize, &endptr, 10);
        accountsColSize = strtol(accColSize, &endptr, 10);
        
        int * arrayAccounts = calloc(accountsSize * accountsColSize, sizeof(int)); 
        arrayAccounts[0] = strtol(strtok(acc,","), &endptr, 10);

        i = 0;
        for (i = 1; i < (accountsSize * accountsColSize); i++){
            arrayAccounts[i] = strtol(strtok(NULL,","), &endptr, 10);
        }
        
        // Creating multidimentional array accounts.
        int ** accounts;
        accounts = calloc(accountsSize, sizeof(int *));
        if (accounts == NULL){
            printf("Malloc Failed.\n");
            return -1;
        }
    
        // Allocating memory for each int that it will be inside the vector
        for (i = 0; i < accountsSize; i++){
            accounts[i] = calloc(accountsColSize, sizeof(int));
            if (accounts[i] == NULL){
                printf("Malloc Failed (2).\n");
                return -1;
            }
        }
        
        // Inserting the data into array Accounts
        int j = 0;
        int k = 0;
        printf("Accounts Size: %d \n", accountsSize);
        printf("Accounts Col Size: %d\n", accountsColSize);
        printf("Inserted Values: | ");
        for (i = 0; i < accountsSize; i++){
            for (j = 0; j < accountsColSize; j++){
                 accounts[i][j] = arrayAccounts[k];
                 printf("%d | ", accounts[i][j]);
                 k++;
            }
        }
        printf("\n");

        // Inserting everything into the function maximumWealth
        richest = maximumWealth(accounts, accountsSize, accountsColSize);
    
        // Cleanup
        for (i = 0; i < accountsSize; i++){
            free(accounts[i]);
        }
        free(accounts);
        free(arrayAccounts); 
   
        // Printing
        printf("Richest Customer: %d\n", richest);
        return 0;
    
    } else {
        printf("Accounts, AccountSize and AccountsColumnSize are required parameters.\n");
        print_usage(argv);
        return 0;
    }
    
}
