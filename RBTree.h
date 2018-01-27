#ifndef MSL_CLANG_001_RBTREE_H
#define MSL_CLANG_001_RBTREE_H

#include <stdio.h>

// creating boolean type
typedef enum {red, black} bool;

struct Node{
    char *word; // dynamically allocated word
    int count;  // word count
    bool color;
    struct Node *left;  // left subtree
    struct Node *right; // right subtree
};

void insert(char *key, struct Node **leaf);
void outputToFile(FILE* file, struct Node** leaf);
void deleteTree(struct Node** leaf);

#endif //MSL_CLANG_001_RBTREE_H
