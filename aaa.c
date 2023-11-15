#include <stdio.h>
#include <string.h>
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

// Function prototypes
void adminMenu();
void userMenu();
void login();
void addBook(struct Book books[], int *bookCount);
void deleteBook(struct Book books[], int *bookCount);
void addUser(struct User users[], int *userCount);
void rentBook(struct Book books[], int bookCount);
void displayAvailableBooks(const struct Book books[], int bookCount);

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
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    struct User users[MAX_USERS];
    int userCount = 0;

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
                rentBook(books, bookCount);
                break;
            case 5:
                displayAvailableBooks(books, bookCount);
                break;
            case 6:
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

void addBook(struct Book books[], int *bookCount) {
    if (*bookCount < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]", books[*bookCount].title);
        printf("Enter book author: ");
        scanf(" %[^\n]", books[*bookCount].author);
        books[*bookCount].id = *bookCount + 1; // Assign a simple ID
        books[*bookCount].available = true;
        (*bookCount)++;
        printf("Book added successfully.\n");
    } else {
        printf("Maximum number of books reached. Cannot add more.\n");
    }
}

void deleteBook(struct Book books[], int *bookCount) {
    if (*bookCount > 0) {
        int bookId;
        printf("Enter the ID of the book to delete: ");
        scanf("%d", &bookId);

        int index = -1;
        int i;
        for (i = 0; i < *bookCount; i++) {
            if (books[i].id == bookId) {
                index = i;
                break;
            }
        }

        if (index != -1) {
        	int i;
            // Shift the array to remove the book
            for (i = index; i < *bookCount - 1; i++) {
                books[i] = books[i + 1];
            }
            (*bookCount)--;
            printf("Book deleted successfully.\n");
        } else {
            printf("Book not found with ID %d.\n", bookId);
        }
    } else {
        printf("No books available to delete.\n");
    }
}

void addUser(struct User users[], int *userCount) {
    if (*userCount < MAX_USERS) {
        printf("Enter username: ");
        scanf(" %[^\n]", users[*userCount].username);
        printf("Enter password: ");
        scanf(" %[^\n]", users[*userCount].password);
        users[*userCount].id = *userCount + 1; // Assign a simple ID
        (*userCount)++;
        printf("User added successfully.\n");
    } else {
        printf("Maximum number of users reached. Cannot add more.\n");
    }
}

void rentBook(struct Book books[], int bookCount) {
    if (bookCount > 0) {
        int bookId;
        printf("Enter the ID of the book to rent: ");
        scanf("%d", &bookId);
int i;
        for ( i = 0; i < bookCount; i++) {
            if (books[i].id == bookId) {
                if (books[i].available) {
                    books[i].available = false;
                    printf("Book rented successfully.\n");
                } else {
                    printf("Book is not available for rent.\n");
                }
                return;
            }
        }
        printf("Book not found with ID %d.\n", bookId);
    } else {
        printf("No books available to rent.\n");
    }
}

void displayAvailableBooks(const struct Book books[], int bookCount) {
    if (bookCount > 0) {
        printf("Available Books:\n");
        printf("ID\tTitle\tAuthor\n");
        int i;
        for ( i = 0; i < bookCount; i++) {
            if (books[i].available) {
                printf("%d\t%s\t%s\n", books[i].id, books[i].title, books[i].author);
            }
        }
    } else {
        printf("No books available.\n");
    }
}
