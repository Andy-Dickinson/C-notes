#include <stdio.h>
#include <string.h>

// Clears console/terminal
void clrscr() { system("@cls||clear"); }

// Prints sudoku board to command line
int printBoard(int grid[9][9])
{
   clrscr();   // Clear screen

   // Board template for printing (N is for iterating sudoku row, isn't displayed)
   char board[] = "     A B C   D E F   G H I  \n"
                  "   +-------+-------+-------+\n"
                  " 1 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  " 2 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  " 3 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  "   +-------+-------+-------+\n"
                  " 4 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  " 5 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  " 6 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  "   +-------+-------+-------+\n"
                  " 7 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  " 8 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  " 9 | 0 0 0 | 0 0 0 | 0 0 0 |\nN"
                  "   +-------+-------+-------+";

   int j = 0, k = 0; // Tracks grid column (j) and row (k)

   // Loop through each character on board template
   for (int i = 0; i <= (strlen(board) - 1); i++)
   {
      if (board[i] == 48)  // If "0" is reached (Puzzle number)
      {
         if (grid[j][k] != 0) // Revealed number in grid location
            printf("%d", grid[j][k]);  // Add number to board

         else  // Puzzle number not revealed yet
            printf("-");   // Add empty slot to board

         j++;  // Iterate to next column
      }
      else  // Template character (not a puzzle digit)
      {
         if (board[i] == 78)  // If "N" is found
         {
            k++;     // Iterate row count
            j = 0;   // Reset column count
         }
         else  // If a regular character
            printf("%c", board[i]); // Print to console
      }
   }
   return 0;   // Operation successful
}

// Check to continue a previous puzzle or not
int checkContinue()
{
   FILE *file = fopen("data.txt", "r");   // Read any ongoing puzzle attempts

   if (file != NULL) // If file exists
   {
      //
      //
      // CHECK VALIDITY OF PUZZLE
      //
      //

      fclose(file);

      // Prompt user whether to continue puzzle
      while (1)   // Infinite loop
      {
         printf(
            // Ask user if previous game should be continued
            " +--------------------------+\n"
            " |          Sudoku          |\n"
            " +--------------------------+\n"
            " |     Continue puzzle?     |\n"
            " |     ( Yes/Y   No/N )     |\n"
            " +--------------------------+\n\n"
            " Input: ");

         // Take user input
         char input[3];
         scanf("%s", &input); // Wait for input

         // User wants to continue
         if (!strcmp(input, "Y") || !strcmp(input, "Yes"))
         {
            clrscr();   // Clear screen
            return 0;   // Continue
         }

         // User doesn't want to continue
         else if (!strcmp(input, "N") || !strcmp(input, "No"))
         {
            clrscr();   // Clear screen
            return 1;   // Don't continue
         }

         clrscr();   // Clear screen
         printf("Invalid input, please try again.\n");   // Error message
      }
   }
   return 1;   // Can't continue
}

// Prompt user for difficulty rating
int difficultyMenu()
{
   printf(
      // Print difficulty menu
      " +--------------------------+\n"
      " |          Sudoku          |\n"
      " +--------------------------+\n"
      " | Difficulty Options       |\n"
      " | [1] Easy                 |\n"
      " | [2] Medium               |\n"
      " | [3] Hard                 |\n"
      " +--------------------------+\n\n"
      // Prompt user for a difficulty rating
      " Enter Puzzle Difficulty: ");

   char difficulty[3];  // Difficulty of the sudoku puzzle (user input)

   // Prompt user for difficulty rating
   while (1)   // Infinite loop
   {
      scanf("%s", &difficulty);  // Wait for input

      /*
      Although using a string to recieve an integer may seem like an inefficient method
      it makes the program far more robust and works fine since there are only 3 valid integer results
      (especially considering the complexity of validating inputs from scanf)
      */
      if (!strcmp(difficulty, "1")) {  // Difficulty 1
         createPuzzle(1);  // Create puzzle
         return 0;   // Operation successful
      } else if (!strcmp(difficulty, "2")) { // Difficulty 2
         createPuzzle(2);  // Create puzzle
         return 0;   // Operation successful
      } else if (!strcmp(difficulty, "3")) { // Difficulty 3
         createPuzzle(3);  // Create puzzle
         return 0;   // Operation successful
      }

      printf(
         // Error, re-prompt user for a difficulty rating
         "\n\n Invalid difficulty rating, please try again.\n"
         " Enter Puzzle Difficulty (1, 2 or 3): ");
   }
}

// Menu to setup puzzle
int setupMenu()
{
   if (checkContinue() == 0)  // If puzzle to be continued
      loadPuzzle();  // Load previous puzzle attempt
   else  // Otherwise start a new game
      difficultyMenu(); // Select a difficulty rating

   return 0;   // Operation successful
}
