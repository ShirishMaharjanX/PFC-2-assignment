#include <stdio.h>

int main() {
    int previousMetre, currentMetre, day, month;

    printf("Enter previous metre, current metre, day and month: ");
    if (scanf("%d %d %d %d", &previousMetre, &currentMetre, &day, &month) != 4) {
        printf("Error: Invalid input format\n");
        return 1;
    }

    printf("%d %d %d %d\n", previousMetre, currentMetre, day, month);

    if (currentMetre < 0 || currentMetre > 9999)
        printf("Error: current meter reading out of range \n");

    if (previousMetre < 0 || previousMetre > 9999)
        printf("Error: previous meter reading out of range \n");

    if (previousMetre > currentMetre)
        printf("Error: previous reading is more than present reading \n");

    if (currentMetre >= previousMetre) {
        int electricityUsed = currentMetre - previousMetre;
        if (electricityUsed > 1000)
            printf("Error: electricity used exceeds 1000 units \n");
    }

    if (month < 1 || month > 12)
        printf("Error: month out of range \n");
    else {
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

        if (day < 1 || day > daysInMonth)
            printf("Error: day out of range for the given month \n");
    }

    return 0;
}
