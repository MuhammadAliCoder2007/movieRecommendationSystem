#include <stdio.h> 

void rotate(int arr[],int size, int k) {
    int tmp[size];
    
    for(int i=0; i<k; i++) {
        tmp[i] = arr[size -k+i];
    }
    for(int i =0; i<size -k; i++) {
        tmp[i+k] = arr[i];
    }
    for(int i=0; i<size; i++) {
        arr[i] = tmp[i];
    }
    
}
int main() {
    int arr[] = {1,2,3,4,5};
    rotate(arr,5,2);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}