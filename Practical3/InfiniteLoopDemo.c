#include <stdio.h>

int main() {
    int j = 10;
    while (j >= 0) {
        printf("%d ", j);
        j--;
    }
    printf("\nLoop completed safely!\n");

    return 0;
}
