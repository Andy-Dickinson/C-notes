#include <stdio.h>


int main(void) {

    int num_box_rows = 3;
    int num_box_cols = 2;
    int row = 4;
    int col = 4;
    int result = row / num_box_rows * num_box_rows + col / num_box_cols;

    printf("row(%d) / num (%d) * num(%d) + col(%d) / num(%d) = (%d)\n", row, num_box_rows, num_box_rows, col, num_box_cols, result);

    int single_figure = 1;
    int double_figure = 15;
    printf("size of single figure = %zu\n", sizeof(single_figure));
    printf("size of double figure = %zu\n", sizeof(double_figure));


    int m = 6;
    int n = 6;
    double **arr2d;
    arr2d = malloc(m * sizeof *arr2d);
    arr2d[0] = malloc(m*n * sizeof *arr2d[0]);
    for (int i = 1; i < m; i ++) {
        arr2d[i] = &(arr2d[0][i*n]);
    }

    printf("arr2d val = %p\n", arr2d);
    printf("arr2d[0] add = %p\n", &(arr2d[0]));

    free(arr2d[0]); // Must be deallocated first to avoid memory leaks.
    free(arr2d);
}
