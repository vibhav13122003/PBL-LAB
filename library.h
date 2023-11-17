#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdbool.h>

#define ADMIN_PASSWORD "admin123"
#define MAX_BOOKS 100
#define MAX_USERS 50

struct Book {
    int id;
    char title[100];
    char author[100];
    bool available;
};

struct User {
    int id;
    char username[100];
    char password[100];
};

// Function prototypes for main menu
void adminMenu();
void userLogin(struct User users[], int userCount, struct Book books[], int bookCount);
void userMenu();
void login();

#endif  // LIBRARY_H
