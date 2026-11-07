
#include <stdio.h>
#include <string.h>

void sortNames(char names[][50], int n) {
    char temp[50];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main(void) {
    int n;

    printf("Enter number of names: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of names.\n");
        return 1;
    }

    char names[n][50];

    printf("Enter names:\n");

    for (int i = 0; i < n; i++) {
        if (scanf("%49s", names[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    sortNames(names, n);

    printf("Names in alphabetical order:\n");

    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
