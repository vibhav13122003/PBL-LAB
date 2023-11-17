#include "library.h"
#include "book.c"
#include "user.c"
#include <stdio.h>
#include <string.h>
void addBook(struct Book books[], int *bookCount);
void deleteBook(struct Book books[], int *bookCount);
void addUser(struct User users[], int *userCount);
void deleteUser(struct User users[], int *userCount);
void rentBook(struct Book books[], int bookCount);
void displayAvailableBooks(const struct Book books[], int bookCount);
void searchUser(const struct User users[], int userCount);
void searchBook(const struct Book books[], int bookCount);

void adminMenu() {
      int choice;
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    struct User users[MAX_USERS];
    int userCount = 0;
    while (1) {
        printf("\nAdmin Menu\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Add User\n");
        printf("4. Delete User\n");
        printf("5. Rent Book\n");
        printf("6. Display Available Books\n");
        printf("7. Search User\n");
        printf("8. Search Book\n");
        printf("9. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
              case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                deleteBook(books, &bookCount);
                break;
            case 3:
                addUser(users, &userCount);
                break;
            case 4:
                deleteUser(users, &userCount);
                break;
            case 5:
                rentBook(books, bookCount);
                break;
            case 6:
                displayAvailableBooks(books, bookCount);
                break;
            case 7:
                searchUser(users, userCount);
                break;
            case 8:
                searchBook(books, bookCount);
                break;
            case 9:
                printf("Logging out.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


void userMenu() {
    int choice;
    struct Book books[MAX_BOOKS];
    int bookCount = 0;

    while (true) {
        printf("\nUser Menu\n");
        printf("1. Display Available Books\n");
        printf("2. Rent Book\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableBooks(books, bookCount);
                break;
            case 2:
                rentBook(books, bookCount);
                break;
            case 3:
                printf("Logging out.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void login() {
    char password[100];
    printf("Enter the admin password: ");
    scanf(" %[^\n]", password);

    if (strcmp(password, ADMIN_PASSWORD) == 0) {
        printf("Admin login successful.\n");
        adminMenu();
    } else {
        printf("Invalid password. Access denied.\n");
    }
}

void userLogin(struct User users[], int userCount, struct Book books[], int bookCount) {
    char enteredUsername[100];
    char enteredPassword[100];
    printf("Enter your username: ");
    scanf(" %[^\n]", enteredUsername);
    printf("Enter your password: ");
    scanf(" %[^\n]", enteredPassword);

    // Authenticate the user
    int i;
    int count = 0;
    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, enteredUsername) == 0 && strcmp(users[i].password, enteredPassword) == 0) {
            printf("User login successful.\n");
            count++;
            userMenu(books, bookCount);
            return;
        }
    }

    if (count == 0) {
        printf("Invalid username or password. Access denied.\n");
    }
}

       
