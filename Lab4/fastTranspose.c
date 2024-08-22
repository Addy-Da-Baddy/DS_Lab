#include <stdio.h>
#define MAX 100
typedef struct Sparse{
    int row;
    int col;
    int val;
}Sparse;

void createSparse(Sparse s[],int r, int c, int arr[][MAX]){
    int cnt = 1;
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c;j++){
            if (arr[i][j]!=0){
                s[cnt].row = i;
                s[cnt].col = j;
                s[cnt].val = arr[i][j];
                cnt++;
            }
        }
    s[0].row = r;
    s[0].col = c;
    s[0].val = cnt - 1;
    }
}

void printSparse (Sparse s[]){
    printf ("First Entry is only info about Sparse Matrix \n");
    printf("<Row, Col, Val>\n");
    for (int i = 0; i<=s[0].val;i++){
        printf ("<%d, %d, %d>\n " , s[i].row , s[i].col , s[i].val);
    }
}

void fastTranspose (Sparse s[],Sparse trans[]){
    int cnt = 1;
    for (int i = 0; i<s[0].col; i++){
        for (int j = 0; j <= s[0].val; j++){
            if (s[j].col == i){
                trans[cnt].row = s[j].col;
                trans[cnt].col = s[j].row;
                trans[cnt].val = s[j].val;
                cnt++;
            }
        }
    }
}

int main() {
    int arr[MAX][MAX];
    int r, c;
    printf("Enter number of rows and number of columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    Sparse s[(MAX*MAX)/2];
    createSparse(s, r, c, arr);
    printf("Original Sparse Matrix:\n");
    printSparse(s);
    Sparse trans[(MAX*MAX)/2];
    trans[0].row = c;  // Rows and columns are swapped in the transpose
    trans[0].col = r;
    trans[0].val = s[0].val;
    fastTranspose(s,trans);

    printf("Transposed Sparse Matrix:\n");
    printSparse(trans);

    return 0;
}



