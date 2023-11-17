#include "user.h"
#include <stdio.h>
#include <string.h>

void deleteUser(struct User users[], int *userCount) {
    if (*userCount > 0) {
        int userId;
        printf("Enter the ID of the user to delete: ");
        scanf("%d", &userId);

        int index = -1;
        int i;
        for (i = 0; i < *userCount; i++) {
            if (users[i].id == userId) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            // Shift the array to remove the user
            for (i = index; i < *userCount - 1; i++) {
                users[i] = users[i + 1];
            }
            (*userCount)--;
            printf("User deleted successfully.\n");
        } else {
            printf("User not found with ID %d.\n", userId);
        }
    } else {
        printf("No users available to delete.\n");
    }
}

void searchUser(const struct User users[], int userCount) {
    if (userCount > 0) {
        char searchUsername[100];
        printf("Enter the username to search: ");
        scanf(" %[^\n]", searchUsername);

        int i;
        for (i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, searchUsername) == 0) {
                printf("User found with ID %d.\n", users[i].id);
                return;
            }
        }
        printf("User not found with username '%s'.\n", searchUsername);
    } else {
        printf("No users available to search.\n");
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

