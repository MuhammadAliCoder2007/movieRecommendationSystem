#include <stdio.h>

void sort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;

        while (j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("Sorted array: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int n;
    do {
        printf("Enter number of elements: ");
        scanf("%d",&n);
    } while (n<1 || n>100);


    int arr[n];
    printf("Enter %d integers: ",n);
    for (int i=0; i<n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }
    sort(arr, n);
    return 0;



}
