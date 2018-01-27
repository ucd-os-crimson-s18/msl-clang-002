#include <stdlib.h>
#include <string.h>
#include "RBTree.h"

// Insert into binary tree function
void insert(char *key, struct Node **leaf)
{
    int val;    // int value for comparison later

    if(*leaf == NULL)
    {
        *leaf = (struct Node*) malloc(sizeof(struct Node)); // allocate space for node

        (*leaf)->word = malloc(strlen(key) + 1);    // allocate space for the word

        strcpy ((*leaf)->word, key);    // copy given key into word

        (*leaf)->left = NULL;   // left subtree is empty

        (*leaf)->right = NULL;  // right subtree is empty

        (*leaf)->count += 1;    // increase word count
    }
    else
    {
        val = strcmp(key, (*leaf)->word); // compare key to word at current leaf

        if(val < 0) // if word is smaller
        {
            insert(key, &(*leaf)->left); // recursive function with left leaf node
        }
        else if(val > 0)  // if word is greater
        {
            insert(key, &(*leaf)->right); // recursive function with right leaf node
        }
        else
            (*leaf)->count +=1; // word already exists, increase word count
    }
}

void outputToFile(FILE* file, struct Node** leaf)
{
    if(*leaf == NULL) // while the tree isn't empty
        return; // if empty return

    outputToFile(file, &(*leaf)->left); //recursive function call for in-order traversal

    fprintf(file,  (*leaf)->word);  // print word to file

    fprintf(file, ": %d \n", (*leaf)->count);   // print word count to file

    outputToFile(file, &(*leaf)->right);    // traverse right side

}

void deleteTree(struct Node** leaf)
{
    if(*leaf != NULL) // while the tree isn't empty
    {
        deleteTree(&(*leaf)->left); // traverse left side

        deleteTree(&(*leaf)->right);    // traverse right side

        free((*leaf)->word);    // free value

        free((*leaf));  // free node
    }
}