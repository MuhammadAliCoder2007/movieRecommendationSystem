#include <stdio.h>

void printAscending(int n) {
    if (n <= 0) return;

    printAscending(n - 1);
    printf("%d ", n);
}

void printDescending(int n) {
    if (n <= 0) return;

    printf("%d ", n);
    printDescending(n - 1);
}

int sumNumbers(int n) {
    if (n <= 0) return 0;
    return n + sumNumbers(n - 1);
}

int main(void) {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Numbers in Ascending order: ");
    printAscending(n);
    printf("\n");

    printf("Numbers in Descending order: ");
    printDescending(n);
    printf("\n");

    printf("Sum = %d", sumNumbers(n));


    return 0;
}
