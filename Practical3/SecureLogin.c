#include <stdio.h>

#define MAX_ATTEMPTS 3
#define CORRECT_PIN 1234

int main() {
    int pin;
    int attempts = 0;

    printf("=== Secure Login System ===\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter PIN: ");

        if (scanf("%d", &pin) != 1) {
            printf("Error: Invalid input, numbers only.\n");
            while (getchar() != '\n');
            continue;
        }

        if (pin == CORRECT_PIN) {
            printf("Access Granted!\n");
            return 0;
        } else {
            attempts++;
            int attemptsLeft = MAX_ATTEMPTS - attempts;
            if (attemptsLeft > 0) {
                printf("Wrong PIN. %d attempt(s) left.\n", attemptsLeft);
            }
        }
    }

    printf("Access Denied. Account Locked.\n");
    return 0;
}
