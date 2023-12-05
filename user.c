#include "library_system.h"

void userAuthentication() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int found = 0;
    int i;
    for ( i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            found = 1;
            printf("User login successful!\n");

            int userChoice;
            while (1) {
                printf("\nUser Menu\n");
                printf("1. Search Book\n");
                printf("2. Display Books\n");
                 printf("3. Search Author\n");
                  printf("4. Rent Book\n");
                  printf("5. Return Book\n");
                  printf("6. Display Checked Book \n");
                printf("7. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &userChoice);

                switch (userChoice) {
                    case 1:
                        searchBook();
                        break;
                    case 2:
                        displayBooks();
                        break;
                         case 3:
                        rentBook();
                        break;
                         case 4:
                       returnBook();
                        break;
                         case 5:
                        displayBooks();
                        break;
                           case 6:
                       displayCheckedOutBooks();
                        break;
                    case 7:
                        printf("User logout successful!\n");
                        return;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
        }
    }

    if (!found) {
        printf("Invalid credentials. Access denied.\n");
    }
}

void rentBook() {
    int bookID;
    printf("Enter book ID to rent: ");
    scanf("%d", &bookID);

    int found = 0;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            found = 1;
            if (books[i].available) {
                books[i].available = 0;  // Book is checked out
                printf("Book rented successfully!\n");
            } else {
                printf("Book is not available for rent.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}
void returnBook() {
    int bookID;
    printf("Enter book ID to return: ");
    scanf("%d", &bookID);

    int found = 0;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            found = 1;
            books[i].available = 1;  // Book is now available
            printf("Book returned successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}


void displayCheckedOutBooks() {
    int i;
    int found = 0;

    for (i = 0; i < bookCount; i++) {
        if (!books[i].available) {
            found = 1;
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            // You can display additional book details if needed
            printf("\n");
        }
    }

    if (!found) {
        printf("No books currently checked out.\n");
    }
}