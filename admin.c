#include "library_system.h"

// struct User admin = {1, "admin", "admin123"};
// struct User users[100];
// struct Book books[100];
// int userCount = 0;
// int bookCount = 0;
// Function definitions
void adminAuthentication() {
    char username[50];
    char password[50];

    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(username, admin.username) == 0 && strcmp(password, admin.password) == 0) {
        printf("Admin login successful!\n");
        // Call admin functions here
        int adminChoice;
        while (1) {
            printf("\nAdmin Menu\n");
            printf("1. Add User\n");
            printf("2. Delete User\n");
            printf("3. Add Book\n");
            printf("4. Delete Book\n");
            printf("5. Search Book\n");
            printf("6. Search Author\n");
            printf("7. Display Books\n");
            printf("8. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &adminChoice);

            switch (adminChoice) {
                case 1:
                    addUser();
                    break;
                case 2:
                    deleteUser();
                    break;
                case 3:
                    addBook();
                    break;
                case 4:
                    deleteBook();
                    break;
                case 5:
                    searchBook();
                    break;
                case 6:
                    searchAuthor();
                    break;
                case 7:
                    displayBooks();
                    break;
                case 8:
                    printf("Admin logout successful!\n");
                    return;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    } else {
        printf("Invalid admin credentials. Access denied.\n");
    }
}

void addUser() {
    printf("Enter new user username: ");
    scanf("%s", users[userCount].username);
    printf("Enter new user password: ");
    scanf("%s", users[userCount].password);

    users[userCount].userID = userCount + 2; // Assuming admin has ID 1
    userCount++;

    printf("User added successfully!\n");
}

void deleteUser() {
    int userID;
    printf("Enter user ID to delete: ");
    scanf("%d", &userID);

    if (userID == 1) {
        printf("Cannot delete admin user.\n");
        return;
    }

    int found = 0;
    int i;
    for ( i = 0; i < userCount; i++) {
        if (users[i].userID == userID) {
            found = 1;
            int j;
            for ( j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("User not found.\n");
    }
}

// Similarly, implement the remaining functions (addBook, deleteBook, searchBook, searchAuthor, displayBooks)
void addBook() {
    printf("Enter book title: ");
    scanf("%s", books[bookCount].title);
    printf("Enter book author: ");
    scanf("%s", books[bookCount].author);

    books[bookCount].bookID = bookCount + 1;
    bookCount++;

    printf("Book added successfully!\n");
}

void deleteBook() {
    int bookID;
    printf("Enter book ID to delete: ");
    scanf("%d", &bookID);

    int found = 0;
    int i;
    for ( i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            found = 1;
            int j;
            for (j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void searchBook() {
    char searchTitle[100];
    printf("Enter book title to search: ");
    scanf("%s", searchTitle);

    int found = 0;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            found = 1;
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void searchAuthor() {
    char searchAuthor[100];
    printf("Enter author to search: ");
    scanf("%s", searchAuthor);

    int found = 0;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].author, searchAuthor) == 0) {
            found = 1;
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            // You can display additional book details if needed
            printf("\n");
        }
    }

    if (!found) {
        printf("No books found by the given author.\n");
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nList of Books\n");
    printf("--------------\n");
    int i;
    for (i = 0; i < bookCount; i++) {
        printf("Book ID: %d\n", books[i].bookID);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("\n");
    }
}