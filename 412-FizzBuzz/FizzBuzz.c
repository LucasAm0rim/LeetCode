#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define WORD_LEN 8

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n; 
    int i = 1;

    char ** FizzBuzz;
    FizzBuzz = calloc(n + 1, sizeof(char *));
    for (; i <= n; i++){
        FizzBuzz[i - 1] = calloc(WORD_LEN + 1, sizeof(char));
        if (i % 3 == 0 && i % 5 == 0){
            strcpy(FizzBuzz[i - 1], "FizzBuzz");
        } else if (i % 3 == 0){
            strcpy(FizzBuzz[i - 1], "Fizz");
        } else if (i % 5 == 0){
            strcpy(FizzBuzz[i - 1], "Buzz");
        } else {
            sprintf(FizzBuzz[i - 1], "%d", i);
        }
    }
    
    return FizzBuzz;
}

void print_usage(char *argv[]){
    printf("Usage: %s -n <number> \n", argv[0]);
}

int main(int argc, char *argv[]){
    char ** answer = NULL;
    int returnSize = 0;
    int c;
    char * num = NULL;

    while ((c = getopt(argc,argv,"n:")) != -1 ){
        switch (c){
            case 'n':
                num = optarg;
                break;
            case '?':
                break;
            
            default:
                return -1;
        }
    }

    if (num){
        answer = fizzBuzz(atoi(num),&returnSize);
        
        for (int i = 0; i < atoi(num); i++){
            printf("| %s ", answer[i]);
        }

        free(answer);
        answer = NULL;
        printf("\n");
    } else {
        printf("Num is a required argument.\n");
        print_usage(argv);
        return 0;
    }

    return 0;
}
