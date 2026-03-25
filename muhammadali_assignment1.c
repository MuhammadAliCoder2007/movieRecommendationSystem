#include <stdio.h>
#include <string.h>
#include <math.h>

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
char* getLetterGrade(int grade) {

    if (grade >= 90) return "A+";  
    else if (grade >= 85) return "A";
    else if (grade >= 80) return "A-";
    else if (grade >= 75) return "B+";
    else if (grade >= 70) return "B";
    else if (grade >= 65) return "C+";
    else if (grade >= 60) return "C";
    else if (grade >= 50) return "D";
    else return "F";
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
        scanf("%lf",&scores[i]);
        if (scores[i] > maxPoints[i] || scores[i] < 0) {
            printf("Invalid score.\n");
            return;
        }
    }

    double finalGrade = calculateFinalGrade(m, scores, maxPoints, weights);
    int rounded = round(finalGrade);
    printf("Final Weighted Grade: %d%%\n", rounded);
    printf("Letter Grade: %s\n", getLetterGrade(rounded));

}

void sort(double arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[j] > arr[i]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void multipleStudents() {
    int m,n;
    printf("Number of componenets: ");
    scanf("%d",&m);
    char names[MAX_COMPONENTS][NAME_LEN];
    double weights[MAX_COMPONENTS];
    double maxPoints[MAX_COMPONENTS];
    
    read(m,names, weights, maxPoints);

    printf("Number of students: ");
    scanf("%d",&n);

    double finalGrades[MAX_STUDENTS];

    for (int s=0; s<n; s++) {
        printf("-- Student %d --\n", s+1);
        double scores[MAX_COMPONENTS];
        for (int i=0; i<m; i++) {
            printf("Score for \"%s\": ", names[i]);
            scanf("%lf",&scores[i]);
        if (scores[i] > maxPoints[i] || scores[i] < 0) {
            printf("Invalid score.\n");
            return;
        }

    }
    double finalGrade = calculateFinalGrade(m, scores, maxPoints, weights);
    int rounded = round(finalGrade);
    finalGrades[s] = finalGrade;
    printf("Final Weighted Grade: %d%%\n", rounded);
    printf("Letter Grade: %s\n", getLetterGrade(rounded));

    }
    sort(finalGrades,n);
    double max = finalGrades[0];
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum+= finalGrades[i];
    }
    double avg = sum/n;

    double med = 0;

    if (n%2 ==0) {
    med = (finalGrades[n/2 -1] + finalGrades[n/2]) / 2;
} else {
    med = finalGrades[n/2];
}

    printf("Class Summary:\n");

    printf("Maximum: %.2f\n", max);
    printf("Average: %.2f\n", avg);
    printf("Median: %.2f\n", med);

}

int main() {
    int choice;
    while(1) {
    printf("======================================\n");
    printf("Weighted Grade Calculation Program\n");
    printf("======================================\n");
    printf("1. Single Student Grades\n");
    printf("2. Multiple Students Grades\n");
    printf("3. Exit\n");

    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    if (choice ==1) {
        singleStudent();
    }
    else if (choice ==2) {
        multipleStudents();
    } 
    else if (choice ==3) {
    printf("--- HAVE A GOOD DAY! ---\n");
    break;
}
    else {
        printf("Invalid Choice");
    }
    }
    return 0;
}