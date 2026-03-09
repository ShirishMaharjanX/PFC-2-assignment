#include <stdio.h>

int main() {
    int number;
    int sum = 0;
    int count = 0;

    printf("=== Sum Calculator ===\n");
    printf("Enter positive numbers (negative to stop):\n");

    while (1) {
        printf("Enter number: ");
        if (scanf("%d", &number) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        if (number < 0) {
            break;
        }

        sum += number;
        count++;
        printf("Current sum: %d\n", sum);
    }

    printf("\nFinal sum: %d\n", sum);
    printf("Total numbers entered: %d\n", count);

    return 0;
}
