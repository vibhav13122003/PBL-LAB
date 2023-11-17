#include "book.h"
#include <stdio.h>
#include <string.h>
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
void searchBook(const struct Book books[], int bookCount) {
    // Dummy implementation
    printf("Search Book function\n");
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

