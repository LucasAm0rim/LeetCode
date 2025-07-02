#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

bool isPalindrome(int x) {    
    if (x < 0){
        return false;
    } else {
        int num = x;
        int i = 0;
        int j = 0;
        unsigned int arrToNum = 0;
        int arrNum[11] = {0};
        while (num != 0){
            arrNum[i] = num % 10;
            //printf("%d", arrNum[i]); FOR DEBUG
            i++;
            num = num / 10;
        }
        while (j < i){
            arrToNum = arrToNum * 10 + arrNum[j];
            j++;
        }
        if (arrToNum == x){
            return true;
        } else {
            return false;
        }
    }    
}

void print_usage(char * argv[]){
    printf("Usage: %s -n <Number>\n",argv[0]);
    printf("Example: %s -n 123456\n",argv[0]);
}

int main(int argc, char * argv[]){
    int c;
    char * strNum = NULL;

    while ((c = getopt(argc,argv,"n:")) != -1){
        switch (c){
            case 'n':
                strNum = optarg;
                break;
            case '?':
                break;
            
            default:
                return -1;
        }
    }

    if (strNum){
       long int num = 0; 
       char *endptr = NULL;
       errno = 0;
       num = strtol(strNum, &endptr, 10);
       if (errno != 0){
           perror("strtol");
           exit(EXIT_FAILURE);
       } else {
           if (isPalindrome(num) == true){
               printf("The number %d is a palindrome.\n", num);
           } else {
               printf("The number %d is not a palindrome.\n", num);
           }
       }
    } else {
        printf("Number is a required value.\n");
        print_usage(argv);
    }
}
