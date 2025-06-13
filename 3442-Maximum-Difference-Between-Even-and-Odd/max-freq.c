#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define MAX_LETTERS 27

int maxDifference(char* s) {
    int i = 0;
    int j = 0;
    int k = 0;
    int highest_odd = 0;
    int lowest_even = 100;
    int result = 0;
    char diff_letters[MAX_LETTERS] = {0};
    int freq[MAX_LETTERS] = {0};

	// This loop registers every different character in the string s.

    diff_letters[0] = s[0];
    while (s[i] != 0){
        if (diff_letters[j] == s[i]){
            i++;
        } else {
           k = 0;
           while (0 == 0){
                if (diff_letters[k] == s[i]){
                    j = k;
                    break;
                } else if (diff_letters[k] != s[i]){
                    k++;
                }
                if (diff_letters[k] == 0){
                    diff_letters[k] = s[i];
                    j++;
                    break;
                }
           }
           i++;
        }
    }

    // This loop make use of diff_letters array to count the frequency of each different character.

    i = 0;
    j = 0;
    while (s[i] != 0){
        if (s[i] == diff_letters[j]){
            freq[j]++;
            i++;
        } else {
            j = 0;
            while (diff_letters[j] != 0){
                if (s[i] == diff_letters[j]){
                    break;
                } else {
                    j++;
                    continue;
                }
            }
        }
    }

	// This loop prints the diff_letters array.
	printf("\n");
	printf("Different Characters: ");
    i = 0;
    while (diff_letters[i] != 0){
        printf("%c",diff_letters[i]);
        i++;
    }
    printf("\n\n");

	// In this piece of code I uncover the highest odd number and the highest even number within the fraq array.
    for (i = 0; i < MAX_LETTERS; i++){
        if (freq[i] % 2 != 0 && freq[i] > highest_odd){
            highest_odd = freq[i];
        }
        if (freq[i] % 2 == 0 && freq[i] != 0 && freq[i] < lowest_even){
            lowest_even = freq[i];
        }
    }

     printf("Current Highest Odd: %d\n",highest_odd);
     printf("Current Lowest Even: %d\n\n",lowest_even);

    // This loop prints the fraq[] array.
    for (i = 0; i < MAX_LETTERS; i++){
        printf("%d | ",freq[i]);
    }
	printf("\n\n");

    // Final Result
    result = highest_odd - lowest_even;
    return result;

}

void print_usage(char *argv[]){
    printf("Usage: %s -w <word>\n",argv[0]);
}

int main(int argc, char *argv[]){
	int c = 0;
	char *s = NULL;

	while ((c = getopt(argc, argv, "w:")) != -1){
        switch (c){
            case 'w':
                s = optarg;
                break;
            case '?':
                printf("Unknown option -%c\n",c);
				print_usage(argv);
                break;
            default:
                return -1;
        }
    }

	if (s == NULL){
		printf("Word is a required argument.\n");
		print_usage(argv);
	} else {
		int maxDiff = maxDifference(s);
		printf("The maximum difference between Even and Odd frequency of characters are: %d\n", maxDiff);
	}
}





