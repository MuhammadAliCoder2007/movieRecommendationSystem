#include <stdio.h>
#include <string.h>

void reverseString(char word[], int size) {
    char word2[size+1];
    for (int i=0; i<size; i++) {
        word2[i] = word[(size -1)-i];
    }
    word2[size]='\0';
    printf("%s", word2);

}
void palindromeCheck(char word[]) {
    int size = strlen(word);
    int v =1;
    for(int i=0; i<size; i++) {
        if (word[i]!=word[size-1-i]) {
            v =0;
        }
    }
    if (v==1) {
        printf("word is a palindrome");
    } else {
            printf("word is not a palindrome");
    }
}

void characterCounting(char word[]) {
    int upper = 0;
    int lower = 0;
    int digits = 0;
    int scase = 0;
    int s = strlen(word);
    for (int i=0; i<s; i++) {
        if(word[i]>='A' && word[i]<'Z') {
            upper+=1;
        } else if (word[i]>='a' && word[i]<'z') {
            lower+=1;
        } else if(word[i]>='1' && word[i]<'9') {
            digits+=1;
        } else {
            scase+=1;
        }
    }
    printf("UpperCase %d\n",upper);
    printf("LowerCase %d\n",lower);
    printf("Dgits %d\n",digits);
    printf("Special %d\n",scase);
}

void compareStrings(char s1[], char s2[]) {
    int result = strcmp(s1,s2);
    if (result==0) {
        printf("Equal");
    } else {
        printf("Not equal");
    }
}
int main() {
    char word[] = "abc";
    char word2[] = "abcd";
    // reverseString(word, 4);
    // palindromeCheck(word);
    // characterCounting(word);
    compareStrings(word,word2);
    return 0;

}