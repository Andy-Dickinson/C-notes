#include "interface.h"
#include <stdlib.h>
#include <time.h>

// Determines whether it is legal or not to place a number in a specified cell
int legal(int col, int row, int val, int grid[9][9])
{
   // Check rows
   for (int i = 0; i < 9; i++)   // Loop through each column on selected row
      if (grid[i][row] == val)   // If a duplicate found
         return 0;   // Illegal

   // Check columns
   for (int i = 0; i < 9; i++)   // Loop through each row on selected column
      if (grid[col][i] == val)   // If a duplicate found
            return 0;   // Illegal

   // Check box
   int x = col, y = row;   // Tracks coordinates for top-left corner of the selected box
   while (1)   // Lower column count until reached the first column of the selected box
      if (x == 0 || x == 3 || x == 6)  // Reached target
         break;   // Break infinite loop
      else  // Not yet reached target
         x--;  // Decrement column

   while (1)   // Lower row count until reached the first row of the selected box
      if (y == 0 || y == 3 || y == 6)  // Reached target
         break;   // Break infinite loop
      else  // Not yet reached target
         y--;  // Decrement row

   int vals[9];   // List of values in box
   int count = 0; // Tracks index of array
   for (int i = 0; i < 3; i++)   // Box columns
      for (int j = 0; j < 3; j++)   // Box rows
      {
         vals[count] = grid[x + i][y + j];   // Add value to list
         count++; // Increment array index
      }

   // Check for repetition
   for (int i = 0; i < 9; i++)   // Loop through array
      if (vals[i] == val)  // If duplicate found
            return 0;   // Illegal

   return 1;   // No checks failed, legal placement
}

// Returns the number of solutions for the given puzzle
int solve(int i, int j, int grid[9][9], int count)
{
   if (i == 9) // If at the end of a row
   {
      i = 0;   // Set column counter back to 0
      if (++j == 9)  // Increment row count and if the bottom of the board has been reached
         return count + 1; // Return solutions
   }

   if (grid[i][j] != 0) // If value already in position
      return solve(i+1, j, grid, count);  // Move onto the next cell

   for (int val = 1; val <= 9 && count < 2; ++val) // Loop through possible values
      if (legal(i, j, val, grid))   // If placement is legal
      {
         grid[i][j] = val; // Place value
         count = solve(i+1, j, grid, count); // Move onto the next cell
      }

   grid[i][j] = 0;   // Clear cell
   return count;  // Return, 0 if no solutions, 1 if a unique solution or 2 if multiple solutions
}

// Returns 1 if the solution is valid, 0 if invalid
int validSolution(int grid[9][9])
{
   // Check no number repetition within columns
   for (int cols = 0; cols < 9; cols++)   // Loop through each column
      for (int i = 0; i < 8; i++)   // Loop through array 1
         for (int j = i + 1; j < 9; j++)  // Loop through array 2
            if (grid[cols][i] == grid[cols][j]) // If duplicate found
               return 0;   // Invalid solution

   // Check no number repetition within rows
   for (int rows = 0; rows < 9; rows++)   // Loop through each row
      for (int i = 0; i < 8; i++)   // Loop through array 1
         for (int j = i + 1; j < 9; j++)  // Loop through array 2
            if (grid[i][rows] == grid[j][rows]) // If duplicate found
               return 0;   // Invalid solution

   // Check no number repetition within boxes (box as in the sets of 9 3x3 numbers)
   for (int x = 0; x < 3; x++)   // Loop through each box on the x-axis
      for (int y = 0; y < 3; y++)   // Loop through each box on the y-axis
      {
         int box[9]; // Holds the numbers within the selected box
         int col = (x * 3) + 1;  // First column belonging to selected box
         int row = (y * 3) + 1;  // First row belonging to selected box
         int count = 0; // Counts which cell of box we are currently on

         // Loop through each box
         for (int i = 0; i < 3; i++)   // Box columns
            for (int j = 0; j < 3; j++)   // Box rows
            {
               box[count] = grid[col + i - 1][row + j - 1]; // Add cell to box
               count++; // Increment count
            }

         // Search for duplicate
         for (int i = 0; i < 8; i++)   // Loop through array 1
            for (int j = i + 1; j < 9; j++)  // Loop through array 2
               if (box[i] == box[j])   // If duplicate found
                  return 0;   // Invalid solution
      }

   return 1;   // Valid solution, no invalid, rows, columns or boxes
}

// Generates a valid sudoku puzzle
int generatePuzzle(int difficulty)
{
   clrscr();

   int grid[9][9];   // 2D array for tracking board values

   // Create empty sudoku grid
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

         grid[cols][rows] = value;  // Apply value
      }

   int loops = 0; // Stops the grid generation after a set number of loops, to prevent freezing in the case of a generation error
   while (1)   // Infinite loop
   {
      printf("Solution generation attempt %d\n", (loops + 1));  // In case operation is taking too long, inform user

      /*
      Algorithm to randomly juggle the rows and columns from the
      grid generated above. This won't necessarily result in the absolute
      best puzzles, but will generate valid sudoku solutions where no
      column, row or box share a repeat of the numbers 1-9.
      */
      srand(time(0));   // Seed random generator with current time

      for (int i = 0; i < 1000; i++)   // Loop 1000 times
      {
         if (rand() & 1)   // 50, 50 chance
         {
            // Randomly select columns to be swapped

            int box = rand() % 3;   // Select random box (the squares made up of 9 numbers)
            int cols[3];   // Columns within selected box

            for (int i = 0; i < 3; i++)   // Allocate each column of the selected box, into an array
               cols[i] = ((box * 3) + 1 + i);   // Add column to box

            int unusedCol = rand() % 3;   // Select which column out of the 3 inside the box will not be swapped

            int col1 = 0, col2 = 0; // The two columns to be switched
            int firstLoop = 1;   // Tracks whether it's the first time a column to be swapped is being allocated

            for (int i = 0; i < 3; i++)   // Loop through each column
               if (unusedCol != i)  // Ignore the column if it's the one to be skipped
                  if (firstLoop) // If it's the first time a column is being allocated to either col1 or col2
                  {
                     col1 = cols[i];   // Allocate column 1
                     firstLoop = 0; // No longer first loop
                  }
                  else
                     col2 = cols[i];   // Allocate column 2

            // Swap columns

            // Lowering the column count to align with array indexes
            col1--; col2--;

            for (int rows = 0; rows < 9; rows++) // Loop through each row in col1
            {
               int value = grid[col1][rows]; // Hold the value being moved from column 1 to column 2
               grid[col1][rows] = grid[col2][rows];   // Move each value from the 2nd column into the first
               grid[col2][rows] = value;  // Add the stored value from columns 1 into column 2
            }
         }
         else  // 50, 50 chance
         {
            // Randomly select rows to be swapped

            int box = rand() % 3;   // Select random box (the squares made up of 9 numbers)
            int rows[3];   // Rows within selected box

            for (int i = 0; i < 3; i++)   // Allocate each row of the selected box, into an array
               rows[i] = ((box * 3) + 1 + i);   // Add row to box

            int unusedRow = rand() % 3;   // Select which row out of the 3 inside the box will not be swapped

            int row1 = 0, row2 = 0; // The two rows to be switched
            int firstLoop = 1;   // Tracks whether it's the first time a row to be swapped is being allocated

            for (int i = 0; i < 3; i++)   // Loop through each row
               if (unusedRow != i)  // Ignore the row if it's the one to be skipped
                  if (firstLoop) // If it's the first time a row is being allocated to either row1 or row2
                  {
                     row1 = rows[i];   // Allocate row 1
                     firstLoop = 0; // No longer first loop
                  }
                  else
                     row2 = rows[i];   // Allocate row 2

            // Swap rows

            // Lowering the row count to align with array indexes
            row1--; row2--;

            for (int cols = 0; cols < 9; cols++) // Loop through each column in row1
            {
               int value = grid[cols][row1]; // Hold the value being moved from column 1 to column 2
               grid[cols][row1] = grid[cols][row2];   // Move each value from the 2nd column into the first
               grid[cols][row2] = value;  // Add the stored value from columns 1 into column 2
            }
         }
      }

      if (validSolution(grid))   // If solution is valid
      {
         printf("Solution generation successful\n");   // Completion message
         break;   // Break the infinite loop
      }

      if (loops > 8) // If generation has attempted 10 times
      {
         printf("\n!!! Solution Generation Failed !!!"); // Error message
         return 1;   // Operation unsuccessful, end
      }
      else  // Else increment the loop
         loops++;
   }

   // How many numbers to be removed based of difficulty
   // Easy     remove 36   (45 left)
   // Medium   remove 45   (36 left)
   // Hard     remove 54   (27 left)
   printf("Generating puzzle, this may take some time depending on the difficulty...");

   // Store initial solution incase of failure
   int solution[9][9];  // Solution grid
   for (int i = 0; i < 9; i++)   // Loop through columns
      for (int j = 0; j < 9; j++)   // Loop through rows
         solution[i][j] = grid[i][j];  // Add cell value

   int count = 0; // Counts the number of removals from the initial solution
   int attempts = 0; // Tracks the number of times the algorithm has tried to find a solution

   while (count < (27 + (9 * difficulty)))   // Loop until puzzle has removed enough clues
   {
      // Randomly select a cell from the puzzle
      int col = rand() % 9;
      int row = rand() % 9;

      if (grid[col][row] != 0)   // If not an empty cell
      {
         //printf("\nTesting %d,%d (%d)", (col + 1), (row + 1), grid[col][row]);

         // Remove number from puzzle
         int val = grid[col][row];  // Store value in case puzzle is invalid
         grid[col][row] = 0;  // Clear cell

         int i = 0, j = 0; // Tracks columns and rows
         if (solve(i, j, grid, 0) == 1)   // If puzzle is still valid
         {
            //printf(" ---REMOVING");
            count++; // Increment the count
            attempts = 0;  // Reset the number of attempts
         }
         else  // If puzzle is invalid
         {
            grid[col][row] = val;   // Return the puzzle back to it's previous form
            attempts++;
         }
      }

      if (attempts > 100)  // If algorithm is stuggling to find a valid puzzle
      {
         // Reset puzzle generation
         count = 0;  // Reset counter
         attempts = 0;  // Reset attempts

         // Replenish original grid
         for (int i = 0; i < 9; i++)   // Loop through columns
            for (int j = 0; j < 9; j++)   // Loop through rows
               if (grid[i][j] != solution[i][j])   // If value is not already correct
                  grid[i][j] = solution[i][j];  // Change cell back to its original value
      }
   }

   // Open file
   char *filename = "data.txt";
   FILE *file = fopen(filename, "w");

   if (file != NULL) // File opened successfully
   {
      for (int col = 0; col < 9; col++)
      {
         for (int row = 0; row < 9; row++)
            fprintf(file, "%i" ,grid[col][row]);
         fprintf(file, "\n");
      }
   }
   else  // File not opened successfully
   {
      // Error
      printf("File opening failed");
      return 1;
   }
   fclose(file); // Close file

   return 0;   // Operation successful
}
