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
Tree* constructorTree();
Node* constructorNode(char String[]);
bool isNodeLeaf(Node* node);
bool isNodeRoot(Node* node);
char* toStringTree(Tree* tree);
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
	tree->root = NULL;

	return tree;
}

Node* constructorNode(char String[]){
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->parent = NULL;
	ptr->left = NULL;
	ptr->mid = NULL;
	ptr->right = NULL;
	ptr->value = NULL;

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

char* toStringTree(Tree* tree){
	char ret[10000] = "{\"Raiz\":";
	char* temp = toStringNode(tree->root);
	strncat(ret, temp, (unsigned) strlen(temp));
	strncat(ret, "}\n", 3);
	return strdup(ret);
}

char* toStringNode(Node* node){
	char ret[10000] = "{";

	if(node == NULL){
		//strncat(ret, "\"NULL\"", 7);
		return strdup("\"NULL\"");
	}
	strncat(ret, "\"",2);
	strncat(ret, node->value,(unsigned) strlen(node->value));
	strncat(ret, "\"",2);
	strncat(ret, ":{", 3);

	char left[10000] = "\"hijo-izq\":";
	char* lptl = toStringNode(node->left);
	strncat(left, lptl, strlen(lptl));
	strncat(left,",", 2);

	char mid[10000] = "\"hijo-mid\":";
	char* lptm = toStringNode(node->mid);
	strncat(mid, lptm, strlen(lptm));
	strncat(mid,",", 2);

	char right[10000] = "\"hijo-der\":";
	char* lptr = toStringNode(node->right);
	strncat(right, lptr, strlen(lptr));
	//strncat(right,"}", 2);

	strncat(ret, left, (unsigned) strlen(left));
	strncat(ret, mid, (unsigned) strlen(mid));
	strncat(ret, right, (unsigned) strlen(right));
	strncat(ret, "}", 3);

	strncat(ret, "}", 2);
	return strdup(ret);
}

void addValueNode(Node* node, char cadena[]){
	if(node->value != NULL){
		free(node->value);
	}
	node->value = (char*) malloc(((unsigned)strlen(cadena)*sizeof(char)) +1);
	node->value[0] = '\0';
	strncat(node->value, cadena, (unsigned) strlen(cadena));

	return;
}

void testTreeCode(char code[]){
	Tree* tree = constructorTree();

	tree->root = constructorNode("");
	addValueNode(tree->root, "Valor1");

	tree->root->left = constructorNode("");
	addValueNode(tree->root->left, "Valor2");


	printf("%s", toStringTree(tree));
}
