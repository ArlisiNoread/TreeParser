//
// Este código fue enteramente hecho por
// Roberto Manuel Piña Sevilla
// Para el curso de Compiladores
//
// Aquella persona que lea esto y desee estudiar
// mi codigo... solo le diré
// “Hope not ever to see Heaven. I have come to lead you to the
// other shore; into eternal darkness; into fire and into ice...”
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "PersonalTools.h"

typedef struct Tree Tree;
typedef struct Node Node;
Node* constructorNode(char String[]);
bool isNodeLeaf(Node* node);
bool isNodeRoot(Node* node);
char* toStringTree(Tree tree);
char* toStringNode(Node* node);
void testTreeCode();

typedef struct Tree {
	struct Node* root;
}Tree;

typedef struct Node{
	char* value;
	struct Node* parent;
	struct Node* left;
	struct Node* mid;
	struct Node* right;
}Node ;

Tree* constructorTree(){
	Tree* tree = (Tree*)malloc(sizeof(Tree));

	return tree;
}

Node* constructorNode(char String[]){
	Node* ptr = (Node*)malloc(sizeof(sizeof(Node)));
	ptr->parent = NULL;
	ptr->left = NULL;
	ptr->mid = NULL;
	ptr->right = NULL;
	strcpy(ptr->value, String);

	return ptr;
}


bool isNodeLeaf(Node* node){
	if(node->left == NULL && node->mid == NULL && node->right == NULL){
		return true;
	}
	return false;
}

bool isNodeRoot(Node* node){
	if(node->parent == NULL){
		return true;
	}
	return false;
}

void addChildToNode(Node* node, Node* childNode, char string[]){
	if(strncmp("left", string, strlen(string))){
		node->left = childNode;
	}else if(strncmp("mid", string, strlen(string))){
		node->mid = childNode;
	}else if(strncmp("right", string, strlen(string))){
		node->right = childNode;
	}else{
		printf("addChildToNode Error");
	}
	childNode->parent = node;
}

char* toStringTree(Tree tree){
	char* ret = "Raiz{";
	char* temp = toStringNode(tree.root);
	ret = strncat(ret, temp, strlen(ret) + strlen(temp));
	ret = strncat(ret, "}", strlen(ret) + 1);
	return ret;
}

char* toStringNode(Node* node){
	char* ret = "";

	if(node == NULL){
		strncat(ret, "NULL", 5);
		return ret;
	}

	ret = concatString(ret, node->value);
	ret = concatString(ret, ":{");

	char* left = toStringNode(node->left);
	left = concatString("{", left);
	left = concatString(left,"},");

	char* mid = toStringNode(node->mid);
	left = concatString("{", mid);
	left = concatString(mid,"},");

	char* right = toStringNode(node->right);
	left = concatString("{", right);
	left = concatString(right,"}");

	ret = concatString(ret, left);
	ret = concatString(ret, mid);
	ret = concatString(ret, right);

	return ret;
}

void testTreeCode(char code[]){


}
