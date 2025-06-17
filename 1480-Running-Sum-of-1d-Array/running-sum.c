#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>


int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize; 
    int * totalsum = calloc(numsSize + 1,sizeof(int));
    int i = 0;
    int j = 0;
    totalsum[0] = nums[0];
    for (i = 1; i < numsSize; i++){
        j = 0;
        while (j < i){
            totalsum[i] = nums[i] + totalsum[j];
            j++;
        }
    }
    return totalsum;
}

void print_usage(char *argv[]){
    printf("usage: %s -n <nums> -s <numsSize>\n",argv[0]);
}

int main(int argc, char *argv[]){
    int c;
    char *nums = NULL;
    char *nSize = NULL;

    while ((c = getopt(argc, argv, "n:s:")) != -1){
        switch (c){
            case 'n':
                nums = optarg;
                break;
            case 's':
                nSize = optarg;
                break;
            case '?':
                break;
            
            default:
                return -1;
        }
    }

    if (nums && nSize){
        int *numsValues = calloc(1,sizeof(int) * atoi(nSize));
        for (int i = 0; i < atoi(nSize); i++){
            if (i == 0){
                numsValues[i] = atoi(strtok(nums,","));
            } else {
                numsValues[i] = atoi(strtok(NULL,","));
            }    
        }

        int returnSize = 0;
        int *newArray = runningSum(numsValues, atoi(nSize), &returnSize);

        printf("Running Sum of nums Array: ");
        for (int i = 0; i < returnSize; i++){
            printf("%d ",newArray[i]);
        }

        printf("\n");

        free(newArray);
        free(numsValues);
        newArray = NULL;
        numsValues = NULL;

        return 0;

        } else {
            printf("The nums array and nSize are required values.\n");
            print_usage(argv);
            return 0;
        }
}
