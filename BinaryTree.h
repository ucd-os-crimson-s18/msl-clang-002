#ifndef MSL_CLANG_001_BINARYTREE_H
#define MSL_CLANG_001_BINARYTREE_H

#include <stdio.h>

struct Node{
    char *word; // dynamically allocated word
    int count;  // word count
    struct Node *left;  // left subtree
    struct Node *right; // right subtree
};

void insert(char *key, struct Node **leaf);
void outputToFile(FILE* file, struct Node** leaf);
void deleteTree(struct Node** leaf);

#endif //MSL_CLANG_001_BINARYTREE_H
