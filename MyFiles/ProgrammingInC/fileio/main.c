#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a file pointer
    FILE *ptr_file;
    // Create an int as we are using getc to read, which reads letters as ascii code
    int c;
    ptr_file = fopen("test.txt", "r");
    if(ptr_file == NULL)
    {
        // File does not exist, exit.
        puts("File not found.");
        return 1;
    }
    else
    {
        // File exists, so read it. Getc reads letters as ascii codes
        while((c = getc(ptr_file)) != EOF)
        {
            // Output to screen. putchar converts from ascii codes to readable letters
            putchar(c);
        }
        // Close the file
        fclose(ptr_file);
        return 0;
    }
}
