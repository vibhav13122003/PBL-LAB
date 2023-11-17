#ifndef BOOK_H
#define BOOK_H

#include "library.h"

// Function prototypes for book-related functions
void addBook(struct Book books[], int *bookCount);
void deleteBook(struct Book books[], int *bookCount);
void rentBook(struct Book books[], int bookCount);
void displayAvailableBooks(const struct Book books[], int bookCount);
void searchBook(const struct Book books[], int bookCount);

#endif  // BOOK_H
