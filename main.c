#include <stdio.h>
#include "library.h"

int main() {

  int choice;
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    struct User users[MAX_USERS];
    int userCount = 0;
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
           userLogin(users, userCount, books, bookCount);
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
