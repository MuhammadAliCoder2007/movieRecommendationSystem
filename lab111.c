#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void prime_factors(int num) {
    printf("Prime factors of %d are: ", num);

    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            while (num % i == 0) {
                printf("%d ", i);
                num /= i;
            }
        }
        if (num == 1) break;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    prime_factors(n);
    return 0;
}