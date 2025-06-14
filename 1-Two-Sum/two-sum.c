#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int returnSize){
    
    int sum = 0;
    int i = 0;
    int j = 1;
    while (sum != target || nums[i] + nums[j] != target){
        sum = nums[i] + nums[j]; 
        if (sum != target){
            j++;
        }
        if (j == numsSize){
            i++;
            j = 0;
            j = i + 1;
        }
    }

    printf("Indexes: | %d | %d |\n", i, j);
    printf("Target: %d \n", sum);
    
    
    int *result = calloc(1,sizeof(int) * 2);
    result[0] = i;
    result[1] = j;
    returnSize = 2;
    return result;
}

void print_usage(char *argv[]){
    printf("usage: %s -n <nums> -s <numsSize> -t <target>\n",argv[0]);
}

int main(int argc, char *argv[]){
    int c;
    int size = 1;
    char *numS = NULL;
    char *numSize = NULL;
    char *target = NULL;

    while ((c = getopt(argc,argv,"n:s:t:")) != -1){
        switch (c){
            case 'n':
                numS = optarg;
                break;
            case 's':
                numSize = optarg;
                break;
            case 't':
                target = optarg;
                break;
            case '?':
                break;

            default:
                return -1;
       }
    }

    if (numS && numSize && target){
        int *num = calloc(1,sizeof(int) * atoi(numSize));

        for (int i = 0; i < atoi(numSize); i++){
            if (i == 0){
                num[i] = atoi(strtok(numS,","));
                printf("Array:   | %d |",num[i]);
                continue;
            }
            num[i] = atoi(strtok(NULL,","));
            printf(" %d |", num[i]);
        }
    
        printf("\n");

        int *result = twoSum(num, atoi(numSize), atoi(target), 2);        
        
        free(num);
        free(result);

    } else {
        printf("The nums array, numSize and target are required variables.\n");
        print_usage(argv);
        return 0;
    }
}
