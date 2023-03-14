#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_to_generate;
    printf("How many random numbers do you want to generate? ");
    scanf("%d", &num_to_generate);

    srand(time(NULL)); // Initialize the random number generator

    FILE *fp;
    fp = fopen("random_numbers.txt", "w"); // Open the file for writing

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < num_to_generate; i++) {
        int num = rand();
        fprintf(fp, "%d ", num);
    }

    fclose(fp); // Close the file

    printf("Random numbers written to file 'random_numbers.txt'.\n");

    return 0;
}
