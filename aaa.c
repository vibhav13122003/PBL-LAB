#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ADMIN_PASSWORD "admin123"

struct Book{
    int id;
    char title[100];
    char author[100];
    bool available;
};

struct User{
    int id;
    char username[100];
    char password[100];
};


void adminMenu();
void userMenu();

void login();

int main() {
    int choice;

    while (true) {
        printf("Library Management System\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                userMenu();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void adminMenu() {
    int choice;

    while (true) {
        printf("\nAdmin Menu\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Add User\n");
        printf("4. Rent Book\n");
        printf("5. Display Available Books\n");
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

       
    }
}

void userMenu() {
    int choice;

    while (true) {
        printf("\nUser Menu\n");
        printf("1. Display Available Books\n");
        printf("2. Rent Book\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

       
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
 //Functionalities to be added for admin
//  1. Add Book
// 2. Delete Book
// 3. Add User
// 4. Rent Book
// 5. Display Available Books
// 6. Logout
//for User