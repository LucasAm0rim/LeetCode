int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int i = 0;
    int j = 0;
    int k = 0;
    int richest = 0;
    int wealth[51] = {0};
    //int * wealth = calloc(accountsSize + 1, sizeof(int));
    
    for (i = 0; i < accountsSize; i++){
        for (j = 0; j < *accountsColSize; j++){
            wealth[k] = accounts[i][j] + wealth[k]; 
        }
        k++;
    }

    printf("\n");

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
