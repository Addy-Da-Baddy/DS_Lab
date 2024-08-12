#include <stdio.h>
#define MAX 50

struct Sparse {
    int row;
    int col;
    int val;
};

typedef struct Sparse sparse;
sparse s[100];

void createSparse(int arr[][MAX], int r, int c) {
    s[0].row = r;
    s[0].col = c;
    int cnt = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {  // Store non-zero elements
                s[cnt].row = i;
                s[cnt].col = j;
                s[cnt].val = arr[i][j];
                cnt++;
            }
        }
    }
    s[0].val = cnt - 1;
}

void fastTranspose(sparse s[], sparse trans[]) {
    int cnt = 1;
    for (int i = 0; i < s[0].col; i++) {
        for (int j = 1; j <= s[0].val; j++) {
            if (i == s[j].col) {  // Transpose based on column index
                trans[cnt].row = s[j].col;
                trans[cnt].col = s[j].row;
                trans[cnt].val = s[j].val;
                cnt++;
            }
        }
    }
    trans[0].val = cnt - 1;  // Update the count of non-zero elements
}

void printSparse(sparse s[]) {
    printf("<row col val>\n");
    for (int i = 1; i <= s[0].val; i++) {
        printf("<%d %d %d>\n", s[i].row, s[i].col, s[i].val);
    }
}

int main() {
    int r, c;
    printf("Enter number of rows and number of columns: ");
    scanf("%d %d", &r, &c);

    int arr[r][MAX];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    createSparse(arr, r, c);
    printf("Original Sparse Matrix:\n");
    printSparse(s);

    sparse trans[100];
    trans[0].row = c;  // Rows and columns are swapped in the transpose
    trans[0].col = r;
    fastTranspose(s, trans);

    printf("Transposed Sparse Matrix:\n");
    printSparse(trans);

    return 0;
}
