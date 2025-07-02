#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#define MAX_SIZE 27

bool canConstruct(char* ransomNote, char* magazine) {
    int ArrRansomNote[MAX_SIZE] = {0};
    int QtdRansomNote[MAX_SIZE] = {0};
    int ArrMagazine[MAX_SIZE] = {0};
    int QtdMagazine[MAX_SIZE] = {0};
    int sizeRansomNote = 0;
    int sizeMagazine = 0;
    int i = 0;
    int j = 0;
    
    // Checking RansomNote Different Characters and its quantity.
    i = 0;
    j = 0;
    ArrRansomNote[0] = (int)ransomNote[0];
    while (ransomNote[i] != 0){
        if (ArrRansomNote[j] == (int)ransomNote[i]){
            j = 0;
            while (ArrRansomNote[j] != 0){
                if (ArrRansomNote[j] != (int)ransomNote[i]){
                    j++;
                } else {
                    QtdRansomNote[j]++;
                    i++;
                    continue;
                }
            }
        } else {
            j = 0;
            while (ArrRansomNote[j] != 0){
                if (ArrRansomNote[j] != (int)ransomNote[i]){
                    j++;
                } else {
                    break;
                }
            }
            ArrRansomNote[j] = (int)ransomNote[i];
            QtdRansomNote[j]++;
            i++;
        }
    }

    // Printing RansomNote value and quantity.
    i = 0;
    printf("RansomNote Stats:\n");
    while (ArrRansomNote[i] != 0){
        printf("Valor: %d | Qtd: %d\n", ArrRansomNote[i], QtdRansomNote[i]);
        sizeRansomNote++;
        i++;
    }

    // Checking Magazine Different Characters and its quantity.
    i = 0;
    j = 0;
    ArrMagazine[0] = (int)magazine[0];
    while (magazine[i] != 0){
        if (ArrMagazine[j] == (int)magazine[i]){
            j = 0;
            while (ArrMagazine[j] != 0){
                if (ArrMagazine[j] != (int)magazine[i]){
                    j++;
                } else {
                    QtdMagazine[j]++;
                    i++;
                    continue;
                }
            }
        } else {
            j = 0;
            while (ArrMagazine[j] != 0){
                if (ArrMagazine[j] != (int)magazine[i]){
                    j++;
                } else {
                    break;
                }
            }
            ArrMagazine[j] = (int)magazine[i];
            QtdMagazine[j]++;
            i++;
        }
    }
    // Printing Magazine value and quantity.
    i = 0;
    printf("\nMagazine Stats:\n");
    while (ArrMagazine[i] != 0){
        printf("Valor: %d | Qtd: %d\n", ArrMagazine[i], QtdMagazine[i]);
        sizeMagazine++;
        i++;
    }

    // Checking if RansomNote can be written using Magazine characters.
    i = 0;
    j = 0;
    if (sizeRansomNote > sizeMagazine){
        return false;
    } else {
        while (ArrRansomNote[i] != 0 && ArrMagazine[j] != 0){
            if (ArrRansomNote[i] == ArrMagazine[j]){
                if (QtdRansomNote[i] <= QtdMagazine[j]){
                    i++;
                    j++;
                } else {
                    return false;
                }
            } else {
                j = 0;
                while (ArrMagazine[j] != ArrRansomNote[i]){
                    if (ArrMagazine[j] == 0){
                        return false;
                    }
                    j++;
                }
            }
        }
    }
    return true;
}

void print_usage(char * argv[]){
    printf("Usage: %s -r <RansomNote> -m <Magazine>\n", argv[0]);
}

int main(int argc, char * argv[]){
    int c;
    char * ransomNote = NULL;
    char * magazine = NULL;

    while ((c = getopt(argc,argv,"r:m:")) != -1){
        switch (c){
            case 'r':
                ransomNote = optarg;
                break;
            case 'm':
                magazine = optarg;
                break;
            case '?':
                break;
            
            default:
                return -1;
        }
    }

    if (ransomNote && magazine){
        bool result = canConstruct(ransomNote, magazine);
        printf("\n");
        if (result == true){
            printf("Ransom Note can be constructed using the letters from magazine.\n");
        } else {
            printf("Ransom Note cannot be constructed using the letters from magazine.\n");
        }
    } else {
        printf("Ransom Note and Magazine are required values.\n");
        print_usage(argv);
    }
    return 0;
}
