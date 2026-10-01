#include <stdio.h>

void transpose(int sparse[][3], int value) {
    int temp;

    // Swap row and column of every non-zero element
    for (int i = 1; i <= value; i++) {
        temp = sparse[i][0];
        sparse[i][0] = sparse[i][1];
        sparse[i][1] = temp;
    }

    // Sort tuples based on row, then column
    for (int i = 1; i <= value; i++) {
        for (int j = i + 1; j <= value; j++) {
            if (sparse[i][0] > sparse[j][0] ||
                (sparse[i][0] == sparse[j][0] &&
                 sparse[i][1] > sparse[j][1])) {

                for (int k = 0; k < 3; k++) {
                    temp = sparse[i][k];
                    sparse[i][k] = sparse[j][k];
                    sparse[j][k] = temp;
                }
            }
        }
    }
}

void printTranspose(int sparse[][3], int value) {
    printf("\nTranspose of sparse matrix:\n");
    printf("R C Element\n");

    for (int i = 0; i <= value; i++) {
        printf("%d %d %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }
}

int main() {
    int rows, cols, nonZero;

    printf("Enter number of rows and columns of sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &nonZero);

    int sparse[nonZero + 1][3];

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;

    printf("Enter sparse matrix in 3-tuple format:\n");

    for (int i = 1; i <= nonZero; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }

    // Transpose the sparse matrix
    transpose(sparse, nonZero);

    // Swap rows and columns in the header
    int temp = sparse[0][0];
    sparse[0][0] = sparse[0][1];
    sparse[0][1] = temp;

    printTranspose(sparse, nonZero);

    return 0;
}
