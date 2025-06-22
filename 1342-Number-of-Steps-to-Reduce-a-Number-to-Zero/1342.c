#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int numberOfSteps(int num) {
    int count = 0;
    while (num != 0){
        // Checks if the number is odd by comparing if its last bit is 1 or 0.
        // Using Bitwise Operations;
        if ((num & 1) == 0){ 
            // Shifts the bits of a number by the number specified;
            // By shifting the bits of a number by 1 you halve it.
            num >>= 1;
        } else {
            num--;
        }
        count++;
    }
    return count;
}

void print_usage(char *argv[]){
    printf("Usage: %s -n <NUMBER>\n", argv[0]);
    printf("Example: %s -n 200\n", argv[0]);
}

int main(int argc, char *argv[]){
    int c;
    char *numChar = NULL;

    while ((c = getopt(argc,argv,"n:")) != -1){
        switch (c){
            case 'n':
                numChar = optarg;
                break;
            case '?':
                break;

            default:
                return -1;
        }
    }

    if (numChar){
        int num = 0;
        char *endptr = NULL;
        errno = 0;
        num = strtol(numChar, &endptr, 10);
        if (errno != 0){
            perror("strtol");
            exit(EXIT_FAILURE);
        } else {
            int result = numberOfSteps(num);
            printf("The number of steps needed to reduce number %d to zero is: %d\n", num, result);
        }

    } else {
        printf("Number is a required value. \n");
        print_usage(argv);
    }
}
