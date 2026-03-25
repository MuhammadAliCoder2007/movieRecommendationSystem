#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Movie
{
    /* data */
    char *title;
    float rating;
    struct Movie *next;
}Movie;


void addMovie(Movie **head);
void removeFirst(Movie **head);
void deleteByTitle(Movie **head);
void printList(Movie *head);

Movie* createMovie(char *title, float rating) {
    Movie *newMovie = (Movie*)malloc(sizeof(Movie));
    newMovie->title = (char*)malloc(strlen(title)+1);
    strcpy(newMovie->title, title);

    newMovie->rating = rating;
    newMovie->next = NULL;
    return newMovie;
}

void addMovie(Movie **head) {
    char title[100];
    float rating;
    int choice;

    printf("Enter movie title: ");
    getchar();
    fgets(title,sizeof(title),stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter rating (out of 10): ");
    scanf("%f", &rating);

    printf("Add at (0 = beginning, 1 = end): ");
    scanf("%d", &choice);

    Movie *newMovie = createMovie(title, rating);

    if(choice==0) {
        newMovie->next = *head;
        *head = newMovie;
    } else {
        if(*head==NULL) {
            *head = newMovie;
        } else {
            Movie *temp = *head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newMovie;
        }
    }
    printf("Movie added");
}

void removeFirst(Movie **head) {
    if (*head == NULL) {
        printf("Watchlist is Empty");
        return;
    }
    Movie *temp = *head;
    *head = (*head)->next;

    free(temp->title);
    free(temp);

    printf("First movie removed");
}

void deleteByTitle(Movie **head) {
    if(*head == NULL) {
        printf("Watchlist is Empty\n");
        return;
    }
    char title[100];
    printf("Enter movie title to delete: ");
    getchar(); // clear buffer
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    Movie *temp = *head;
    Movie *prev = NULL;
    while (temp != NULL) {
        if(strcmp(temp->title, title)==0) {
            if(prev == NULL) {
                *head = temp->next;

            } else {
                prev->next = temp->next;
            }
            free(temp->title);
            free(temp);

            printf("\"%s\" is deleted from the watchlist\n", title);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Movie not found.\n");

}

void printList(Movie *head) {
    if(head == NULL) {
        printf("Watchlist is Empty. \n");
        return;
    }
    printf("Current Watchlist:\n");
    int i =1;
    while (head !=NULL) {
        printf("%d. %s (Rating: %.1f)\n",i,head->title, head->rating);
        head = head->next;
        i++;
    }
}


int main() {
    Movie *head = NULL;
    int choice;
    printf("\nWatchlist Menu:\n");
    printf("1. Add a movie\n");
    printf("2. Remove the next movie to watch\n");
    printf("3. Delete a movie by title\n");
    printf("4. Show current watchlist\n");
    printf("5. Exit\n");

    while(1) {

        printf("Please choose: ");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            /* code */
            addMovie(&head);
            break;
        case 2:
            removeFirst(&head);
            break;
        case 3:
            deleteByTitle(&head);
            break;
        case 4:
            printList(head);
            break;
        case 5:
            printf("Good bye");
            return 0;
        
        default:
            printf("Invalid Choice");
        }
    }
}
