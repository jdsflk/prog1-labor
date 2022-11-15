#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct rentalListItem {
    rental data;
    struct rentalListItem* next;
} rentalListItem;

typedef enum {
    TITLE,
    AUTHOR,
    PUBLISHER,
    PUBLICATION_DATE,
    BOOK_ID
} bookFields;

bookListItem* getBooks(FILE *bfp) {
    book currentBook;
    bookListItem *head;
    bookListItem **tail = &head;

    char c = fgetc(bfp);
    int letterIndex = 0;
    char yearStr[4] = {0};
    bookFields bookField = TITLE;
    while(1) {
        if(feof(bfp)) {
            currentBook.bookID[letterIndex] = 0;
            bookListItem *temp = (bookListItem*) malloc(sizeof (bookListItem));
            temp->data = currentBook;
            temp->next = NULL;
            *tail = temp;
            tail = &(*tail)->next;
            break;
        }
        if(c == '\n') {
            bookListItem *temp = (bookListItem *)malloc(sizeof(bookListItem));
            temp->data=currentBook;
            temp->next=NULL;
            *tail = temp;
            tail = &(*tail)->next;
            letterIndex = 0;
            c = fgetc(bfp);
        }
        switch (bookField) {
            case TITLE: {
                if(c == ',' && letterIndex!=0) {
                    currentBook.title[letterIndex] = '\0';
                    bookField = AUTHOR;
                    letterIndex = 0;
                    break;
                }
                currentBook.title[letterIndex]=c;
                letterIndex++;
                break;
            }
            case AUTHOR: {
                if(c == ',' && letterIndex!= 0) {
                    currentBook.author[letterIndex] = '\0';
                    bookField = PUBLISHER;
                    letterIndex = 0;
                    break;
                }
                currentBook.author[letterIndex]=c;
                letterIndex++;
                break;
            }
            case PUBLISHER: {
                if(c == ',' && letterIndex!=0) {
                    currentBook.publisher[letterIndex] = '\0';
                    bookField = PUBLICATION_DATE;
                    letterIndex = 0;
                    break;
                }
                currentBook.publisher[letterIndex]=c;
                letterIndex++;
                break;
            }
            case PUBLICATION_DATE: {
                if(c == ',' &&letterIndex!=0) {
                    currentBook.publicationDate=yearStr[0]*1000+yearStr[1]*100+yearStr[2]*10+yearStr[3];
                    bookField = BOOK_ID;
                    letterIndex = 0;
                    break;
                }
                yearStr[letterIndex]=c;
                letterIndex++;
                break;
            }
            case BOOK_ID: {
                if(c == ',' && letterIndex!=0) {
                    currentBook.bookID[letterIndex] = '\0';
                    bookField=TITLE;
                    letterIndex = 0;
                    break;
                }
                currentBook.bookID[letterIndex]=c;
                letterIndex++;
                break;
            }
            default: {
                printf("Unknown book field");
                break;
            }
        }
        c = fgetc(bfp);
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

rentalListItem* getRentals (FILE* rfp, userListItem* ulh, bookListItem* blh) {
    rental currentRental;
    rentalListItem* head = NULL;
    rentalListItem** tail = &head;

    char c = fgetc(rfp);
    int letterIndex = 0;
    char currentID[10];

    while (1) {
        if(feof(rfp)) {
            bookListItem * iterator = blh;
            currentID[letterIndex] = '\0';
            while(iterator != NULL) {
                if(!strcmp(currentID, iterator->data.bookID)) {
                    currentRental.Book = iterator->data;
                }
                iterator = iterator->next;
            }

            rentalListItem* temp = (rentalListItem*) malloc(sizeof(rentalListItem));
            temp->data = currentRental;
            temp->next = NULL;
            *tail = temp;
            tail = &(*tail)->next;

            break;
        }
        if(c == '\n') {
            bookListItem* iterator = blh;
            currentID[letterIndex] = '\0';
            while (iterator != NULL) {
                if(!strcmp(currentID, iterator->data.bookID)) {
                    currentRental.Book = iterator->data;
                    break;
                }
                iterator = iterator->next;
            }

            rentalListItem* temp = (rentalListItem*) malloc(sizeof(rentalListItem));
            temp->data = currentRental;
            temp->next = NULL;
            *tail = temp;
            tail = &(*tail)->next;

            letterIndex = 0;
            c = fgetc(rfp);
            continue;
        }
        if(c == ',') {
            userListItem* iterator = ulh;
            currentID[letterIndex] = '\0';
            while(iterator != NULL) {
                if(!strcmp(currentID, iterator->data.userID)) {
                    currentRental.User = iterator->data;
                }
                iterator = iterator->next;
            }
            letterIndex = 0;
            c = fgetc(rfp);
            continue;
        }

        currentID[letterIndex] = c;
        letterIndex++;
        c = fgetc(rfp);
    }
    return head;
}

int main() {
    FILE *bookFilePointer = fopen("books.txt", "r");
    if(bookFilePointer == NULL) {
        return 1;
    }
    FILE *userFilePointer = fopen("users.txt", "r");
    if(userFilePointer == NULL) {
        return 1;
    }

    FILE* rentalFilePointer = fopen("rentals.txt", "r");
    if(rentalFilePointer == NULL) {
        return 1;
    }

    bookListItem* bookListHead = getBooks(bookFilePointer);
    userListItem* userListHead = getUsers(userFilePointer);
    rentalListItem* rentalListHead = getRentals(rentalFilePointer, userListHead, bookListHead);

    if (fclose(bookFilePointer) || fclose(userFilePointer) || fclose(rentalFilePointer)) {
        return 2;
    }
    free(bookListHead);
    free(userListHead);
    return 0;
}