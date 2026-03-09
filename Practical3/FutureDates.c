#include <stdio.h>

int main() {
    int today, daysAfter, futureDay;
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    printf("Enter today's day of the week (0=Sunday, 1=Monday, ..., 6=Saturday): ");
    if (scanf("%d", &today) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    if (today < 0 || today > 6) {
        printf("Error: Day must be between 0 and 6!\n");
        return 1;
    }

    printf("Enter number of days after today: ");
    if (scanf("%d", &daysAfter) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    if (daysAfter < 0) {
        printf("Error: Number of days must be non-negative!\n");
        return 1;
    }

    futureDay = (today + daysAfter) % 7;

    printf("Today is %s\n", days[today]);
    printf("Future day is %s\n", days[futureDay]);

    return 0;
}
