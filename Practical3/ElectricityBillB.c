#include <stdio.h>

#define MAX_CUSTOMERS 10

int main() {
    int numCustomers;
    int totalElectricity = 0;

    printf("Enter number of customers (max %d): ", MAX_CUSTOMERS);
    if (scanf("%d", &numCustomers) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    if (numCustomers < 1 || numCustomers > MAX_CUSTOMERS) {
        printf("Error: Number of customers must be between 1 and %d!\n", MAX_CUSTOMERS);
        return 1;
    }

    for (int i = 1; i <= numCustomers; i++) {
        int previousMetre, currentMetre, day, month;

        printf("\n--- Customer %d ---\n", i);
        printf("Enter previous metre, current metre, day and month: ");
        if (scanf("%d %d %d %d", &previousMetre, &currentMetre, &day, &month) != 4) {
            printf("Error: Invalid input format\n");
            return 1;
        }

        printf("%d %d %d %d\n", previousMetre, currentMetre, day, month);

        int hasError = 0;

        if (currentMetre < 0 || currentMetre > 9999) {
            printf("Error: current meter reading out of range \n");
            hasError = 1;
        }

        if (previousMetre < 0 || previousMetre > 9999) {
            printf("Error: previous meter reading out of range \n");
            hasError = 1;
        }

        if (previousMetre > currentMetre) {
            printf("Error: previous reading is more than present reading \n");
            hasError = 1;
        }

        int electricityUsed = 0;
        if (currentMetre >= previousMetre) {
            electricityUsed = currentMetre - previousMetre;
            if (electricityUsed > 1000) {
                printf("Error: electricity used exceeds 1000 units \n");
                hasError = 1;
            }
        }

        if (month < 1 || month > 12) {
            printf("Error: month out of range \n");
            hasError = 1;
        } else {
            int daysInMonth;
            switch (month) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    daysInMonth = 31;
                    break;
                case 4: case 6: case 9: case 11:
                    daysInMonth = 30;
                    break;
                case 2:
                    daysInMonth = 29;
                    break;
            }

            if (day < 1 || day > daysInMonth) {
                printf("Error: day out of range for the given month \n");
                hasError = 1;
            }
        }

        if (!hasError) {
            totalElectricity += electricityUsed;
        }
    }

    printf("\n=== Summary ===\n");
    printf("Total customers processed: %d\n", numCustomers);
    printf("Total electricity units used: %d\n", totalElectricity);

    return 0;
}
