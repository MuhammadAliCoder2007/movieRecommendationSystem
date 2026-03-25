#include <stdio.h> 

int secondlargest(int arr[],int size) {
    int s =0;
    int max =0;
    for (int i=0; i<size; i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    for (int i=0; i<size; i++) {
        if(arr[i]>s && arr[i]<max) {
            s = arr[i];
        }
    }
    return s;

}
int main() {
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int sl = secondlargest(arr, size);
    printf("%d",sl);
}