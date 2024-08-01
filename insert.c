#include <stdio.h>
#include <string.h>

int main() {
    char strng[100];
    char subs[50];
    int pos;

    // Prompt user for the main string
    printf("Enter the main string: ");
    fgets(strng, sizeof(strng), stdin);
    // Remove the newline character added by fgets
    strng[strcspn(strng, "\n")] = '\0';

    // Prompt user for the substring
    printf("Enter the substring: ");
    fgets(subs, sizeof(subs), stdin);
    // Remove the newline character added by fgets
    subs[strcspn(subs, "\n")] = '\0';

    // Prompt user for the position
    printf("Enter the position to insert the substring: ");
    scanf("%d", &pos);

    int strlen = 0, sublen = 0;

    // Calculate the length of strng
    for (int i = 0; strng[i] != '\0'; i++) {
        strlen++;
    }

    // Calculate the length of subs
    for (int i = 0; subs[i] != '\0'; i++) {
        sublen++;
    }

    // Ensure the position is within valid bounds
    if (pos < 1 || pos > strlen + 1) {
        printf("Invalid position!\n");
        return 1;
    }

    // Adjust position to zero-based index
    int index = pos - 1;

    // Shift the original string to the right
    for (int i = strlen - 1; i >= index; i--) {
        strng[i + sublen] = strng[i];
    }

    // Insert the substring
    for (int j = 0; j < sublen; j++) {
        strng[j + index] = subs[j];
    }

    // Null-terminate the new string
    strng[strlen + sublen] = '\0';

    // Print the result
    printf("Resulting string: %s\n", strng);

    return 0;
}
