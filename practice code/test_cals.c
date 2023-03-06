#include <stdio.h>


int main(void) {

    int num_box_rows = 3;
    int num_box_cols = 2;
    int row = 4;
    int col = 4;
    int result = row / num_box_rows * num_box_rows + col / num_box_cols;

    printf("row(%d) / num (%d) * num(%d) + col(%d) / num(%d) = (%d)\n", row, num_box_rows, num_box_rows, col, num_box_cols, result);

}
