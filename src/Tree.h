#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#ifndef TREE_H_
#define TREE_H_

typedef struct Tree Tree;
typedef struct Node Node;

Node* constructorNode(char String[]);
bool isNodeLeaf(Node* node);
bool isNodeRoot(Node* node);
void testTreeCode();

#endif /* TREE_H_ */
