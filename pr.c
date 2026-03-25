#include <stdio.h>

void fun6(int x) {
    if (x > 0) {
        fun6(x - 1);
        printf("%d\t", x);
        fun6(x - 3);
    }
}

int main() {
    fun6(4);
    return 0;
}