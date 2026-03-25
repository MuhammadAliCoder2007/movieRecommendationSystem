#include <stdio.h>

void printArray(int arr[],int n) {
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
void move_zeroes_to_the_end(int arr[], int n) {
    int pos = 0;
    for (int i =0; i<n; i++) {
        if (arr[i] != 0) {
            arr[pos] = arr[i];
            pos++;
        }
    
    }
    while (pos<n) {
        arr[pos] = 0;
        pos++;
    }
}


int main(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements: ",n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    move_zeroes_to_the_end(arr,n);
    printArray(arr,n);



}