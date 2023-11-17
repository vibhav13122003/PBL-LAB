#ifndef USER_H
#define USER_H

#include "library.h"

// Function prototypes for user-related functions
void addUser(struct User users[], int *userCount);
void deleteUser(struct User users[], int *userCount);
void searchUser(const struct User users[], int userCount);

#endif  // USER_H

