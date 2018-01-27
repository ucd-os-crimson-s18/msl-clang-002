// Operating Systems: CSCI 3453
// Program Assignment 1: C
// Jeff McMillan, Eric Holguin
#include "test_suite.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BinaryTree.h"

int main(int argc, char **argv)
{

    struct Node *root = NULL;   // set root to null

    char x[50]; // create an array of characters of max size 50

    // Open file from argument line
    FILE* inputFile = fopen(argv[1], "r"); // "r" for read

    if(inputFile == NULL) // if file does not exist
    {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read in chunks / use a buffer
    while(fscanf(inputFile, "%50s", x) == 1)
    {
        insert(x, &root);   // Call to insert function
    }

    // Close input file
    fclose(inputFile);

    FILE* outputFile = fopen("myoutput01.txt", "w"); // open output file, "w" for write

    if(outputFile == NULL) // if file does not exist
    {
        printf("Error opening file\n");
        exit(1);
    }

    outputToFile(outputFile, &root);    // Call to outputToFile function

    // Close output file
    fclose(outputFile);

    // Call to delete tree function
    deleteTree(&root);

    root = NULL;

    return 0;
}


 
