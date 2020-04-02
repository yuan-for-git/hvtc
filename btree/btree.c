#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct btree{
	int key;
	int color;
	struct btree* parent;
	struct btree* left;
	struct btree* right;
}RBtree;

typedef struct root{
	RBtree* node;
}RBroot;

void leftrotate(RBroot *root,RBtree* x){
	RBtree *y=x->right;
	x->left = y->left;
	if(y->left != NULL){
		y->left->parent=x;
	}
	if(x->parent == NULL){
		root->node = y;
		
	}
	y->parent = x->parent;
	if(x->parent->left == x){
		x->parent->left = y;
	}
	else if(x->parent->right == x){
		x->parent->right = y;
	}

	y->left = x;
	x->parent=y;

	
}

void rightrotate(RBroot *root,RBtree* x){
	RBtree *y=x->left;
	x->left = y->right;
	if(y->right != NULL){
		y->right->parent=x;
	}
	if(x->parent == NULL){
		root->node = y;
		
	}
	y->parent = x->parent;
	if(x->parent->left == x){
		x->parent->left = y;
	}
	else if(x->parent->right == x){
		x->parent->right = y;
	}

	y->right = x;
	x->parent=y;

	
}



void rbtree_insert_node(RBroot *root,RBtree *x)
{
	
}