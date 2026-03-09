#include <stdio.h>

int main() {
    char firstWord[20];
    char secondWord[20];
    int num;

    printf("Enter two words and an integer from keyboard: \n");
    scanf("%19s %19s %d", firstWord, secondWord, &num);

    printf("%s %s \n%d \n", firstWord, secondWord, num);

    return 0;
}
