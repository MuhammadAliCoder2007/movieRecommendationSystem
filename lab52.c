#include <stdio.h>

void findDuplicate(char word[]) {
    printf("Duplicate characters: ");
    
    for (int i=0; word[i]!='\0'; i++) {
        int count = 0;
        for (int j= i+1; word[j]!= '\0'; j++) {
            if (word[i]==word[j]) {
                count++;
                word[j] = '#';
            }
        }
        if (count>0 && word[i]!='#') {
            printf("%c ", word[i]);
            
        }
    }
    printf("\n");
}

int main() {
    char word[100];
    printf("Enter a word: \n");
    scanf("%s", word);

    findDuplicate(word);
    return 0;
}