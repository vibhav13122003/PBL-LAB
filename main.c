//#include <stdio.h>
//#include <stdlib.h>
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//int main(int argc, char *argv[]) {
//	return 0;
//}
#include "library_system.h"

// Define the variables in one source file (main.c)
struct User admin = {1, "admin", "admin123"};
struct User users[100];
struct Book books[100];
int userCount = 0;
int bookCount = 0;

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminAuthentication();
                break;
            case 2:
                userAuthentication();
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
