#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice(FILE *file) {
    int roll = rand() % 6 + 1;  
    printf("%d\n", roll);  
    fprintf(file, "%d\n", roll);  
}

int main() {
    srand(time(NULL));

    FILE *file = fopen("output/dice_rolls.txt", "w");
    if (file == NULL) {
        perror("cant open file");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        roll_dice(file);
    }

    fclose(file);
    return 0;
}
