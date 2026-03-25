#include <stdio.h>

void originalOrder(int n) {
    if (n == 0) return;
    originalOrder(n/10);
    printf("%d ", n%10);
}

void originalOrder2(int n) {
    int r = 0;

    while(n>0) {
        r = r*10 + n%10;    
        n/=10;
    }
    while(r>0) {
        printf("%d ", r%10);
        r/=10;
    }
}

void reverseOrder(int n) {
    if (n == 0) return;
    printf("%d ", n%10);
    reverseOrder(n/10);
    
}
void reverseOrder2(int n) {
    while(n>0) {
        printf("%d ", n%10);
        n/=10;
    }
}

int main(void) {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Numbers in Original order: (recursion) ");
    originalOrder(n);
    printf("\n");
    
    printf("Numbers in Original order: (iteration) ");
    originalOrder2(n);
    printf("\n");
    
    printf("Numbers in Reverse order: (recursion) ");
    reverseOrder(n);
    printf("\n");

    printf("Numbers in Reverse order: (iteration) ");
    reverseOrder2(n);
    printf("\n");
}