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

int openFiles(FILE *bfp, FILE *ufp, FILE *rfp) {
    bfp = fopen("C:\\Users\\Asus\\Documents\\Egyetem\\Progi 1\\nagy_hazi\\cmake-build-debug\\b.txt", "r");
    ufp = fopen("users.txt", "r");
    rfp = fopen("rentals.txt", "r");
    if (bfp == NULL || ufp == NULL || rfp == NULL) {
        return 1;
    }
    return 0;
}

int closeFiles(FILE *bfp, FILE *ufp, FILE *rfp) {
    if (fclose(bfp) || fclose(rfp) || fclose(ufp)) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *bookFilePointer = fopen("b.txt", "r");
    /*if (openFiles(bookFilePointer, userFilePointer, rentalFilePointer) == 1) {
        return 1;
    }*/
    bookListItem* bookListHead = getBooks(bookFilePointer);
    if (fclose(bookFilePointer)) {
        return 2;
    }
    free(bookListHead);
    return 0;
}
