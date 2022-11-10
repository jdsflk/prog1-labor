#include <stdio.h>

/*
Kölcsönzéseket tartalmazó fájl
- Könyv ID-je (string)
- Kölcsönző felhasználó ID-je (string)
- visszaadás határideje (string), formátum YYYY-MM-DD*/

typedef struct {
    char title[30];
    char author[30];
    char publisher[20];
    int publicationDate;
    char bookID[10];
} book;

typedef struct {
    char name[30];
    char userID[10];
} user;

typedef struct {
    user User;
    book Book;
} rental;

int main() {
    printf("Hello, World!\n");
    return 0;
}
