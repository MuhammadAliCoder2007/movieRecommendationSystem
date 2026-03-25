#include <stdio.h>
#include <stdlib.h> 

int* createSquares(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr==NULL) {
        return NULL;
    }
    for (int i=0; i<n; i++) {
        arr[i] = (i+1)*(i+1);
    }
    return arr;
} 

int main() {
    int n;
    printf("Enter arry size: ");
    scanf("%d",&n);

    int* sqaures = createSquares(n);
    if (sqaures == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i=0; i<n; i++) {
        printf("%d ", sqaures[i]);
    }
    free(sqaures);
    return 0;
}
