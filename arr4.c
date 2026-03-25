#include <stdio.h> 

int maxSubArraySum(int arr[], int size) {
    int currentSum = arr[0];
    int maxSoFar = arr[0];

    for(int i=1; i<size; i++) {
        if(currentSum<0) {
            currentSum = arr[i];
        } else {
            currentSum+=arr[i];
        }
        if (currentSum>maxSoFar) {
            maxSoFar = currentSum;
        }
        return maxSoFar;
    }
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = 9;

    int result = maxSubarraySum(arr, size);
    printf("Maximum subarray sum = %d\n", result);

    return 0;
}