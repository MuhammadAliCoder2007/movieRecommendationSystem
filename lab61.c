#include <stdio.h>
void computeRowAverage(int production[3][4]) {
    printf("Average Production Per Week\n");
    for(int i=0; i<3; i++) {
        float rowSum = 0;
        for(int j=0; j<4; j++) {
            rowSum+=production[i][j];
        }
        printf("Product %d: %.1f units/week\n",i+1,rowSum/4);
        
    }
}
void computeColAverage(int production[3][4]) {
    printf("Total Production Per Week\n");
    for(int i=0; i<4; i++) {
        int colSum = 0;
        for(int j=0; j<3; j++) {
            colSum+=production[j][i];
        }
        printf("Week %d: %d units/week\n",i+1,colSum);
        
    }
}
int main() {
    int production[3][4];
    for(int i =0; i<3; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d",&production[i][j]);
        }
    }
    computeRowAverage(production);
    computeColAverage(production);
    return 0;
}