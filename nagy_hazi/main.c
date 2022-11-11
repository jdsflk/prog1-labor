#include <stdio.h>
#include <stdlib.h>

/*
 * RETURN CODES
 *      1: couldn't open file
 *      2: couldn't close file
 */

typedef struct {
    char title[30];
    char author[30];
    char publisher[20];
    int publicationDate;
    char bookID[10];
} book;

typedef struct bookListItem {
    book data;
    struct bookListItem *next;
} bookListItem;

typedef struct {
    char name[30];
    char userID[10];
} user;

typedef struct userListItem {
    user data;
    struct userListItem *next;
} userListItem;

typedef struct {
    user User;
    book Book;
} rental;

bookListItem* getBooks(FILE *bfp) {
    book currentBook;
    bookListItem *head;
    bookListItem **tail = &head;

    while (fscanf(bfp, "%s %s %s %d %s", currentBook.title, currentBook.author, currentBook.publisher,
                  &currentBook.publicationDate, currentBook.bookID) == 5) {
        bookListItem *temp = (bookListItem*)malloc(sizeof (bookListItem));
        temp->data= currentBook;
        temp->next = NULL;
        *tail =temp;
        tail= &(*tail)->next;
    }
    return head;
}

userListItem* getUsers(FILE* ufp) {
    user currentUser;
    userListItem* head = NULL;
    userListItem** tail = &head;
    char c = fgetc(ufp);
    int letterIndex = 0;
    int isName = 1;
    while(1) {
        if(feof(ufp)) {
            currentUser.userID[letterIndex] = '\0';
            userListItem *temp = (userListItem*)malloc(sizeof(userListItem));
            temp->data=currentUser;
            temp->next=NULL;
            *tail = temp;
            tail = &(*tail)->next;
            break;
        }
        if(c == '\n') {
            currentUser.userID[letterIndex] = '\0';
            userListItem *temp = (userListItem*)malloc(sizeof(userListItem));
            temp->data=currentUser;
            temp->next=NULL;
            *tail = temp;
            tail = &(*tail)->next;
            letterIndex = 0;
            isName = 1;
            c = fgetc(ufp);
        }
        if(c == ',') {
            currentUser.name[letterIndex] = '\0';
            letterIndex = 0;
            isName = 0;
            c = fgetc(ufp);
            continue;
        }
        if(isName) {
            currentUser.name[letterIndex] = c;
        }
        if(!isName) {
            currentUser.userID[letterIndex] = c;
        }
        letterIndex++;
        printf("%c",c);
        c = fgetc(ufp);
    }
    return head;
}

int main() {
    FILE *bookFilePointer = fopen("b.txt", "r");
    if(bookFilePointer == NULL) {
        return 1;
    }
    FILE *userFilePointer = fopen("users.txt", "r");
    if(userFilePointer == NULL) {
        return 1;
    }

    bookListItem* bookListHead = getBooks(bookFilePointer);
    userListItem* userListHead = getUsers(userFilePointer);

    if (fclose(bookFilePointer) || fclose(userFilePointer)) {
        return 2;
    }
    free(bookListHead);
    return 0;
}