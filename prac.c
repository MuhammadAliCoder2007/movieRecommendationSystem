// #include <stdio.h>

// void fun5(int x) {
//     if (x > 0) {
//         fun5(--x);
//         printf("%d ", x);
//         fun5(--x);
//     }
// }

// int main() {
//     fun5(4);
//     return 0;
// }
#include <stdio.h>

// int main() {
//     int myNumber = 42;
//     float myFloat = 3.14;

//     // 1. The "Universal Adapter"
//     // We can point to an int or a float using the SAME pointer type
//     void *vPtr;

//     // Point it to the integer
//     vPtr = &myNumber;
    
//     // 2. The "Casting" Step
//     // We can't use *vPtr directly. We must tell C it's an (int *) first.
//     printf("Integer value: %d\n", *(int *)vPtr);

//     // Now point the SAME pointer to the float
//     vPtr = &myFloat;

//     // Tell C it's a (float *) this time
//     printf("Float value: %.2f\n", *(float *)vPtr);

//     return 0;
// }
#include <stdio.h>

void fun5(int x) {
    //printf("%d \n", x);
    if (x > 0) {
        fun5(--x);
        printf("%d ", x);
        fun5(--x);
    }
}

int main() {
    fun5(4);
    return 0;
}
