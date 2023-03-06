#include <stdio.h>

int main() {

    int grid[9][9];

    for(int cols = 0; cols < 9; cols++) // Loop through each column
          for(int rows = 0; rows < 9; rows++) // Loop through each row
          {
             /*
             Algorithm to generate a basic solution like the one
             shown here: https://stackoverflow.com/a/4066090
             */
             int value = (rows * 3) + (cols + 1);
             if (rows > 5)
                value++;
             if (rows > 2)
                value++;
             while (value > 9)
                value = value - 9;
             printf("%d\n", value);
             grid[cols][rows] = value;  // Apply value
          }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("|%d|", grid[j][i]);
        }
        printf("\n");
    }
}
