
#include <stdio.h>

void inputMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void displayMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10],
               int r, int c) {
    int i, j, sum[10][10];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Addition:\n");
    displayMatrix(sum, r, c);
}

void multiplyMatrix(int a[10][10], int b[10][10],
                    int r1, int c1, int c2) {
    int i, j, k, product[10][10] = {0};

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++)
                product[i][j] += a[i][k] * b[k][j];

    printf("Multiplication:\n");
    displayMatrix(product, r1, c2);
}

void transposeMatrix(int a[10][10], int r, int c) {
    int i, j, t[10][10];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("Transpose:\n");
    displayMatrix(t, c, r);
}

int main() {
    int a[10][10], b[10][10];
    int r1, c1, r2, c2, choice;

    do {
        printf("\n1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter rows and columns of matrices: ");
                scanf("%d%d", &r1, &c1);

                if (r1 < 1 || r1 > 10 ||
                    c1 < 1 || c1 > 10) {
                    printf("Invalid dimensions!\n");
                    break;
                }

                printf("Enter first matrix:\n");
                inputMatrix(a, r1, c1);

                printf("Enter second matrix:\n");
                inputMatrix(b, r1, c1);

                addMatrix(a, b, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns of first matrix: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of second matrix: ");
                scanf("%d%d", &r2, &c2);

                if (r1 < 1 || r1 > 10 ||
                    c1 < 1 || c1 > 10 ||
                    r2 < 1 || r2 > 10 ||
                    c2 < 1 || c2 > 10) {
                    printf("Invalid dimensions!\n");
                    break;
                }

                if (c1 != r2) {
                    printf("Multiplication not possible!\n");
                    break;
                }

                printf("Enter first matrix:\n");
                inputMatrix(a, r1, c1);

                printf("Enter second matrix:\n");
                inputMatrix(b, r2, c2);

                multiplyMatrix(a, b, r1, c1, c2);
                break;

            case 3:
                printf("Enter rows and columns: ");
                scanf("%d%d", &r1, &c1);

                if (r1 < 1 || r1 > 10 ||
                    c1 < 1 || c1 > 10) {
                    printf("Invalid dimensions!\n");
                    break;
                }

                printf("Enter matrix:\n");
                inputMatrix(a, r1, c1);
                transposeMatrix(a, r1, c1);
                break;

            case 4:
                printf("Exiting program!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
