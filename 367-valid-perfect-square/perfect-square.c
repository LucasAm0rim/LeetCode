#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>


#define NUM_PRIMES 168

bool isPerfectSquare(int num) {
    int prime_nums[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    int dividers[1344] = {0};
    int array_primes[NUM_PRIMES] = {0};

    int j = 0,
    i = 0,
    count_odd = 0;

    while (num != 1) {
        if (num % prime_nums[i] != 0) {
            if (i == NUM_PRIMES - 1) {
				if (num != 1){
					count_odd++;
				}
               break;
            }
            i++;
        } else {
            num = num / prime_nums[i];
            dividers[j] = prime_nums[i];
            j++;
        }
    }

	i = 0;
    while (dividers[i] != 0) {
        printf("%d\t", dividers[i]);
		i++;
    }

	printf("\n");

    i = 0;
    j = 0;
    while (dividers[i] != 0) {
        if (dividers[i] == prime_nums[j]){
            array_primes[j]++;
            i++;
        } else if (dividers[i] != prime_nums[j]){
            j++;
        }
    }

	printf("\n");

    for (i = 0; i < NUM_PRIMES; i++) {
		printf("%d\t", array_primes[i]);
        if (array_primes[i] % 2 != 0) {
            count_odd++;
        }
    }

	printf("\n\n");

    if (count_odd > 0) {
        return false;
    } else {
        return true;
    }
}

void print_usage(char *argv[]){
	printf("Usage: %s -n <number>\n",argv[0]);
}


int main(int argc, char *argv[]){

	int c = 0;
	char *num = NULL;

	while ((c = getopt(argc, argv, "n:")) != -1){
		switch (c){
			case 'n':
				num = optarg;
				break;
			case '?':
				printf("Unknown option -%c\n",c);
				break;
			default:
				return -1;
		}
	}

	if (num == NULL){
		printf("Number is a required argument.\n");
		print_usage(argv);
	} else {
		if (isPerfectSquare(atoi(num)) == true){
			printf("The number %s is a perfect square.\n",num);
		} else {
			printf("The number %s is not a perfect square.\n",num);
		}
	}

	return 0;
}
