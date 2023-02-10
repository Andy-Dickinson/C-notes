#include <stdio.h>

int main()
{
    // declare file pointer and open file in read/write mode
    FILE* fptr;
    fptr = fopen("test-file-c.txt", "w+");

    // write to file
    fprintf(fptr, "%s %s %d", "hello", "world!", 2023);
    fprintf(fptr, "\nyo");

    // sets file position to the beginning of the file
    rewind(fptr);

    // create string to store read text
    char my_text[100];

    // if file exits
    if (fptr != NULL)
    {
        // while something to read, read and print
        while (fgets(my_text, 100, fptr))
        {
            printf("%s", my_text);
        }
    } else {
        printf("Not able to open the file.");
    }

    // close file
    fclose(fptr);
    return 0;
}
