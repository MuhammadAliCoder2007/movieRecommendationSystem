#include <stdio.h>
int sumNumbers(int n) {
    if (n <= 0) return 0;
    return n%10 + sumNumbers(n/10);
}


int main(void) {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Sum = %d", sumNumbers(n));


}