#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_49 7
#define NUM_36 6

void generate_unique_numbers(int *numbers, int range, int count) {
    for (int i = 0; i < count; i++) {
        int num;
        int is_unique;
        do {
            is_unique = 1;
            num = rand() % range + 1; 
            for (int j = 0; j < i; j++) {
                if (numbers[j] == num) {
                    is_unique = 0;
                    break;
                }
            }
        } while (!is_unique);
        numbers[i] = num;
    }
}

void print_numbers_to_file(FILE *file, int *numbers, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fprintf(file, "\n");
}

int main() {
    srand(time(NULL));  

    int numbers_49[NUM_49];
    int numbers_36[NUM_36];

    FILE *file = fopen("output/lottery_results.txt", "w");
    if (file == NULL) {
        perror("cant open file");
        return 1;
    }

    while (1) {  
        generate_unique_numbers(numbers_49, 49, NUM_49);
        generate_unique_numbers(numbers_36, 36, NUM_36);

        fprintf(file, "7 чисел з 49: ");
        print_numbers_to_file(file, numbers_49, NUM_49);

        fprintf(file, "6 чисел з 36: ");
        print_numbers_to_file(file, numbers_36, NUM_36);
    }

    fclose(file);  
    return 0;
}


