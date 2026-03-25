#include <stdio.h>

#define MAX_COMPONENTS 50
#define MAX_STUDENTS 100
#define NAME_LEN 50
double recursiveSum(double arr[], int n) {
    if (n==0) {
        return 0;
    }
    return arr[n-1] + recursiveSum(arr, n-1);
}
double calculateFinalGrade(int m, double scores[], double maxPoints[], double weights[]){
    double weighted[MAX_COMPONENTS];
    for (int i=0; i<m; i++) {
        weighted[i] = (scores[i]/maxPoints[i]) *weights[i];
    }
    return recursiveSum(weighted, m);
    
}
char getLetterGrade(int grade) {

    if (grade >= 90) return 'A+';  
    else if (grade >= 85) return 'A';
    else if (grade >= 80) return 'A-';
    else if (grade >= 75) return 'B+';
    else if (grade >= 70) return 'B';
    else if (grade >= 65) return 'C+';
    else if (grade >= 60) return 'C';
    else if (grade >= 50) return 'D';
    else return 'F';
    
}

void read(int m, char names[][NAME_LEN], double weights[], double maxPoints[]) {
    double totalWeight =0;
    for (int i=0; i<m; i++) {
        printf("Componenets %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]", names[i]);

        printf("Weight: ");
        scanf("%lf", &weights[i]);

        printf("Max Allocated Point: ");
        scanf("%lf", &maxPoints[i]);
        if (weights[i] < 0 || maxPoints[i] <= 0) {
            printf("Invalid input. Exiting.\n");
            return;
        }

        totalWeight+=weights[i];

    }
    if (totalWeight != 100) {
        printf("Total weight must equal 100. Exiting.\n");
    }
}
void singleStudent() {
    int m;
    printf("Number of componenets: ");\
    scanf("%d",&m);
    char names[MAX_COMPONENTS][NAME_LEN];
    double weights[MAX_COMPONENTS];
    double maxPoints[MAX_COMPONENTS];
    double scores[MAX_COMPONENTS];
    read(m,names, weights, maxPoints);

    printf("--Summary of Score--\n");

    for (int i=0; i<m; i++) {
        printf("Score for \"%s\": ", names[i]);
        scanf("%1f",scores[i]);
        if (scores[i] > maxPoints[i] || scores[i] < 0) {
            printf("Invalid score.\n");
            return;
        }
    }

    double finalGrade = calculateFinalGrade(m, scores, maxPoints, weights);
    int rounded = round(finalGrade);
    printf("Final Weighted Grade: %d%%\n", rounded);

}

int main() {
    int choice;
    printf("======================================\n");
    printf("Weighted Grade Calculation Program\n");
    printf("======================================\n");
    printf("1. Single Student Grades\n");
    printf("2. Multiple Students Grades\n");
    printf("3. Exit\n");

    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);
}