#include <stdio.h>

int main() {
    int month, year;
    int daysInMonth;

    printf("Enter month (1-12): ");
    if (scanf("%d", &month) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    printf("Enter year: ");
    if (scanf("%d", &year) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Error: Month must be between 1 and 12!\n");
        return 1;
    }

    if (year < 0) {
        printf("Error: Year must be non-negative!\n");
        return 1;
    }

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                daysInMonth = 29;
            else
                daysInMonth = 28;
            break;
    }

    char* monthNames[] = {"", "January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};

    printf("%s %d had %d days.\n", monthNames[month], year, daysInMonth);

    getchar();

    return 0;
}
