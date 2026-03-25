
#include <stdio.h>

void updateMarks(int *ref_mark, int bonus) {
    *ref_mark +=bonus;
    return;

}

int updateMarks2(int value_mark, int bonus) {
    value_mark += bonus;
    return value_mark;

}

int main(void) {

    int mark, bonus;
    printf("Enter student marks: ");
    scanf("%d ", &mark);

    printf("Enter bonus marks: ");
    scanf("%d ", &bonus);

    int original = mark;
    int mark2 = updateMarks2(mark, bonus);
    updateMarks2(&mark, bonus);


    printf("Before update");

}