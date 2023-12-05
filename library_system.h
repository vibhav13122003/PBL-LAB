#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct Book {
    int bookID;
    char title[100];
    char author[100];
    int available;  // 1 if available, 0 if checked out
};

struct User {
    int userID;
    char username[50];
    char password[50];
};

// Declare variables as extern
extern struct User admin;
extern struct User users[100];
extern struct Book books[100];
extern int userCount;
extern int bookCount;

// Function declarations
void adminAuthentication();
void userAuthentication();
void addUser();
void deleteUser();
void addBook();
void deleteBook();
void searchBook();
void searchAuthor();
void displayBooks();
void rentBook();
void returnBook();
void displayCheckedOutBooks();

#endif // LIBRARY_SYSTEM_H
