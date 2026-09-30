#include <stdio.h>

int nonZeroElements(int *mat, int rows, int cols, int *arr) {
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(mat + i * cols + j) != 0) {
                count++;

                *(arr + count * 3 + 0) = i;
                *(arr + count * 3 + 1) = j;
                *(arr + count * 3 + 2) = *(mat + i * cols + j);
            }
        }
    }

    // Header row: rows, columns, number of non-zero elements
    *(arr + 0) = rows;
    *(arr + 1) = cols;
    *(arr + 2) = count;

    return count;
}

int main() {
    int rows, cols;

    printf("Enter rows and columns of a sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    int sparse[rows][cols];
    int arr[100][3];

    printf("Enter elements of sparse matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }

    int nonZero = nonZeroElements(
        (int *)sparse,
        rows,
        cols,
        (int *)arr
    );

    printf("\nSparse Matrix in 3-Tuple Format\n");
    printf("Rows Columns Non-Zero\n");

    for (int i = 0; i <= nonZero; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
