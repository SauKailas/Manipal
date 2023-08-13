#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    char response;

    printf("Enter the name of the file to remove (or 'exit' to quit): ");
    scanf("%s", filename);

    while (strcmp(filename, "exit") != 0) {
        printf("Do you want to remove '%s'? (y/n): ", filename);
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y') {
            if (remove(filename) == 0) {
                printf("File '%s' removed successfully.\n", filename);
            } else {
                printf("Error removing '%s'.\n", filename);
            }
        } else {
            printf("File '%s' was not removed.\n", filename);
        }

        printf("\nEnter the name of the file to remove (or 'exit' to quit): ");
        scanf("%s", filename);
    }

    return 0;
}