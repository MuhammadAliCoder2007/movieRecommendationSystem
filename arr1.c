#include <stdio.h>

void sorted(int arr[], int size) {
    int v =0;
    for(int i=0; i<size-1; i++) {
        if(arr[i]>arr[i+1]) {
            printf("1");
            v=1;
            break;
        }
        
    }
    if(v==0) {
         printf("True");
        }
    
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = 5;

    sorted(arr,size);
}