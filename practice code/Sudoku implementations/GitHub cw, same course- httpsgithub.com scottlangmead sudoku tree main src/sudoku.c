#include "generation.h"

// Move data for undo/redos
struct move
{
	int prev;   // Undo
	int new;    // Redo
	int x;   // Column
	int y;   // Row
};

// Undo stack variables
struct move undoStack[81];
int undoTop = -1;

// Redo stack variables
struct move redoStack[81];
int redoTop = -1;

// Checks whether the undo stack is empty
int isUndoEmpty()
{
   if(undoTop == -1)
      return 1;   // Stack is empty
   else
      return 0;   // Stack isn't empty
}
// Checks whether the redo stack is empty
int isRedoEmpty()
{
   if(redoTop == -1)
      return 1;   // Stack is empty
   else
      return 0;   // Stack isn't empty
}

// Pops an element off the undo stack
struct move undoPop()
{
   struct move element; // The element being popped off the stack
   if(!isUndoEmpty())   // Stack isn't empty
   {
      element = undoStack[undoTop]; // Retrieve element from stack
      undoTop = undoTop - 1;  // Lower the top
      return element;   // Return data from stack
   }
   else
   {
      // Return empty element
      element.new = -1;
      element.prev = -1;
      element.x = -1;
      element.y = -1;
      return element;
   }
}
// Pops an element off the redo stack
struct move redoPop()
{
   struct move element; // The element being popped off the stack
   if(!isRedoEmpty())   // Stack isn't empty
   {
      element = redoStack[redoTop]; // Retrieve element from stack
      redoTop = redoTop - 1;  // Lower the top
      return element;   // Return data from stack
   }
   else
   {
      // Return empty element
      element.new = -1;
      element.prev = -1;
      element.x = -1;
      element.y = -1;
      return element;
   }
}

// Pushes an element onto the undo stack
void undoPush(struct move element)
{
   undoTop = undoTop + 1;  // Increase size of stack
   undoStack[undoTop] = element; // Add element to stack
}
// Pushes an element onto the redo stack
void redoPush(struct move element)
{
   redoTop = redoTop + 1;  // Increase size of stack
   redoStack[redoTop] = element; // Add element to stack
}

// Primary entrypoint for program
int main()
{
   setupMenu();   // Setup puzzle
   return 0;   // Operation successful
}

// Writes all data into text file
void backupPuzzle(int grid[9][9])
{
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

      fprintf(file, "\n\n");

      struct move element;

      while (!isUndoEmpty())
      {
         element = undoPop();

         fprintf(file, "%d%d%d%dU\n", element.new, element.prev, element.x, element.y);
      }


      while (!isRedoEmpty())
      {
         element = redoPop();


         fprintf(file, "%d%d%d%dR\n", element.new, element.prev, element.x, element.y);


      }


   }
   else  // File not opened successfully
   {
      // Error
      printf("File opening failed");
   }
   fclose(file); // Close file
}

// Create puzzles of varying difficulty
int createPuzzle(int difficulty)
{
   // New puzzle
   generatePuzzle(difficulty);   // Create
   loadPuzzle();  // Load

   return 0;   // Operation successful
}

// Load puzzle from text file
int loadPuzzle()
{
   int grid[9][9];   // Puzzle
   FILE *file = fopen("data.txt", "r");   // Read puzzle
   int c; int count = 0;   // Tracks file data

   struct move element;
   int elementCount = 0;

   while ((c = getc(file)) != EOF)  // Loop through each character in file
   {
      if (count < 81)   // Loop through board
      {
         if (c != '\n') //
         {
            // Tracks row and column values
            int x = count;
            int y = 0;

            while (x > 8)  // Loop until all rows have been incremented
            {
               // Increment row
               x = x - 9;
               y++;
            }
            grid[x][y] = (c - 48);  // Add value to grid
            count++; // Increment count
         }
      }
      else  // Not looping through board
      {
         if (c == '\n')
         {
            element.new    = -1;
            element.prev   = -1;
            element.x      = -1;
            element.y      = -1;
         }
         else
         {
            if (elementCount == 0)
            {
               element.new = c;
               elementCount++;
            }
            else if (elementCount == 1)
            {
               element.prev = c;
               elementCount++;
            }
            else if (elementCount == 2)
            {
               element.x = c;
               elementCount++;
            }
            else if (elementCount == 3)
            {
               element.y = c;
               elementCount++;
            }
            else if (elementCount == 4)
            {
               if (c == 'U')
                  undoPush(element);
               else if (c == 'R')
                  redoPush(element);
               elementCount = 0;
            }
         }
      }
   }
   fclose(file);  // Close file

   runPuzzle(grid);  // Start game

   return 0;   // Operation successful
}

// Request number to be added into target cell from user
int requestNumber(char location[2])
{
   char input[3]; // Stores user input

   while (1)   // Infinite loop
   {
      // Take user input
      printf("\n Enter cell value for %s: ", location);
      scanf("%s", &input); // Wait for user input
      int number = input[0] - '0';  // Convert character to integer

      if (number >= 1 && number <= 9)  // If valid input
         return number; // Exit loop and return value
      else  // If invalid input, error message and continue the loop
         printf("\n Invalid input, please try again. (Value must be between 1 and 9)\n");
   }
}

// Start running the puzzle
int runPuzzle(int grid[9][9])
{
   int firstTime = 1;   // Tracks whether this is the user's first turn, 1-Yes, 0-No
   char input[6]; // Stores user input
   int x, y;   // Coordinates of cell to be changed
   int number; // Number to be entered into cell
   time_t start, end;   // Start and end time of puzzle

   start = clock();  // Start time

   while (1)   // Infinite loop
   {
      printBoard(grid); // Display board

      if (validSolution(grid))
         break;

      // Retrieve user input coordinates
      while (1)   // Infinite loop
      {
         if (firstTime) // Extra info if first turn
         {
            printf(
               // Print rules
               "\n\n Rules:"
               "\n You must fill in the entire sudoku grid, consisting of 9 3x3 boxes"
               "\n Each row, column and box must contain the numbers 1 to 9 without repetition"
               // Prompt user for coordinates
               "\n\n Enter coordinates for cell to be altered."
               "\n For example: 'I9' to fill in the bottom right corner."
               "\n undo - undoes last action"
               "\n redo - redoes last action"
               "\n Input: ");
            firstTime = 0; // No longer first turn
         }
         else
            printf(
               // Prompt user for coordinates
               "\n\n Enter coordinates for cell to be changed."
               "\n undo - undoes last action"
               "\n redo - redoes last action"
               "\n Input: ");

         scanf("%s", &input); // Wait for user input

         if (!strcmp(input, "undo"))   // If undo selected
         {
            struct move element = undoPop();

            if (element.x > 9)
               element.x = element.x - 48;
            if (element.y > 9)
               element.y = element.y - 48;
            if (element.new > 9)
               element.new = element.new - 48;
            if (element.prev > 9)
               element.prev = element.prev - 48;

            element.new = grid[element.x][element.y];

            grid[element.x][element.y] = 0;

            element.prev = 0;

            redoPush(element);

            break;
         }
         else if (!strcmp(input, "redo")) // If redo selected
         {
            struct move element = redoPop();


            if (element.x > 9)
               element.x = element.x - 48;
            if (element.y > 9)
               element.y = element.y - 48;
            if (element.new > 9)
               element.new = element.new - 48;
            if (element.prev > 9)
               element.prev = element.prev - 48;


            grid[element.x][element.y] = element.new;

            element.prev = element.new;
            element.new = 0;

            undoPush(element);

            break;
         }

         /*
         The scanf buffer clearing
         code is from:
         https://stackoverflow.com/a/7898516
         */

         x = (int)(input[0]); // Convert x letter into an ascii value

         if ((x < 65 || x > 73) && (x < 97 || x > 105))   // value outside of range
         {
            // Error
            printf("\n Invalid coordinate, please try again.\n Format: [LETTER][NUMBER], e.g. A1 or B7 or I4.");

            // Clear scanf buffer
               int c; while ((c = getchar()) != '\n' && c != EOF) { }
         }
         else  // Ascii value from A-I/a-i
         {
            if (x < 90) // If ascii value from A-I
               x = x - 64; // Convert into x axis value (1-9)
            else  // If ascii value from a-i
               x = x - 96; // Convert into x axis value (1-9)

            y = input[1] - '0';  // Convert y value into integer

            if (y < 1 || y > 9)  // If value outside of range
            {
               // Error
               printf("\n Invalid coordinate, please try again.\n Format: [LETTER][NUMBER], e.g. A1 or B7 or I4.");

               // Clear scanf buffer
               int c; while ((c = getchar()) != '\n' && c != EOF) { }
            }
            else  // Valid coordinate
            {
               // Clear scanf buffer
               int c; while ((c = getchar()) != '\n' && c != EOF) { }

               int number = requestNumber(input);

               // Update grid with user input
               grid[x-1][y-1] = number;

               struct move element = { .new = 0, .prev = 0, .x = (x - 1), .y = (y - 1) };
               undoPush(element);

               backupPuzzle(grid);

               break;   // Break out of loop for current turn
            }
         }
      }
   }

   end = clock(); // End time
   float t = (end - start);   // Time taken
   int secs = (int)(t / 1000);   // Seconds taken
   int mins = 0;  // Tracks number of minutes

   // Remove minutes from seconds variable where possible
   while (secs > 60)
   {
      secs = secs - 60; // Remove 60 seconds
      mins++;  // Increase the number of mintues by 1
   }

   printf("\n Puzzle completed in, %d minutes and %d seconds", mins, secs);

   // Wait before closing (temporary)
   int i; printf("\n\n\n Input to Close...\n"); scanf("%d",&i);

   return 0;   // Operation successful
}
