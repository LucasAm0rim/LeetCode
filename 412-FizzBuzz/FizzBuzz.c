#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 8

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n; 
    int i = 1;

    char ** FizzBuzz;
    FizzBuzz = calloc(n + 1, sizeof(char *));
    for (; i <= n; i++){
        FizzBuzz[i - 1] = calloc(WORD_LEN + 1, sizeof(char));
        if (i % 3 == 0 && i % 5 == 0){
            FizzBuzz[i - 1] = "FizzBuzz";
        } else if (i % 3 == 0){
            FizzBuzz[i - 1] = "Fizz";
        } else if (i % 5 == 0){
            FizzBuzz[i - 1] = "Buzz";
        } else {
            sprintf(FizzBuzz[i - 1], "%d", i);
        }
    }
    
    return FizzBuzz;
}
