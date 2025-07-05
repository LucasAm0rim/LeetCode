#include <stdio.h>
#include <getopt.h>

int romanToInt(char* s) {
    char romanSTR[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', 0};
    int romanValues[7] = {1,5,10,50,100,500,1000};
    int romanNums[7] = {0};
    int i = 0;
    int j = 0;
    int result = 0;

    i = 0;
    j = 0;
    while (s[i] != 0){
        if (s[i] == romanSTR[j]){
            if (s[i] == 'I' && s[i+1] == 'V'){
                romanNums[j] = romanNums[j] + 4;
                i = i + 2;
            } else if (s[i] == 'I' && s[i+1] == 'X'){
                romanNums[j] = romanNums[j] + 9;
                i = i + 2;
            } else if (s[i] == 'X' && s[i+1] == 'L'){
                romanNums[j] = romanNums[j] + 4;
                i = i + 2;
            } else if (s[i] == 'X' && s[i+1] == 'C'){
                romanNums[j] = romanNums[j] + 9;
                i = i + 2;
            } else if (s[i] == 'C' && s[i+1] == 'D'){
                romanNums[j] = romanNums[j] + 4;
                i = i + 2;
            } else if (s[i] == 'C' && s[i+1] == 'M'){
                romanNums[j] = romanNums[j] + 9;
                i = i + 2;
            } else {
                romanNums[j]++;
                i++;
            }
        } else {
            j = 0;
            while (s[i] != romanSTR[j]){
                j++;
            }
        }
    }
    
    for ( i = 0; i < 7; i++){
        printf("%d ", romanNums[i]);
        if (romanNums[i] != 0){
            result = result + (romanNums[i] * romanValues[i]);
        }
    }

    return result;
}

void print_usage(char *argv[]){
    printf("Usage: %s -n <RomanNumber>\n", argv[0]);
    printf("Example: %s -n MCL\n", argv[0]);
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
        int result = 0; 
        result = romanToInt(numChar);
        printf("\nResult: %d\n", result);
    } else {
        printf("Number is a required value.\n");
        print_usage(argv);
    }
}
