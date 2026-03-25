#include <stdio.h>

void printReverseIndex(int arr[], int n) {

    for (int i=n-1; i>=0; i--) {
        printf("%d ", arr[i]);
    }
}
void printReversePointer(int *arr, int n) {
    int *ptr = arr + n -1;

    printf("\n");
    for (int i=0; i<n; i++){
        printf("%d ", *ptr);
        ptr--;
    }
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printReverseIndex(arr, n);
    printReversePointer(arr, n);

}