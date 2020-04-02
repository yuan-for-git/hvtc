#include<stdio.h>
#include<stdlib.h>

#define Elemtype char
typedef struct tree{
	Elemtype data;
	struct tree *lchild, *rchild;
}bitree;

void tree_create(bitree **tree){
	char c = getchar();
	
	if (c != '#'){
		*tree = (bitree *)malloc(sizeof(bitree));
		if(NULL==*tree){
			printf("malloc error");
			exit(-1);
		}
		(*tree)->data = c;
		(*tree)->lchild = NULL;
		(*tree)->rchild = NULL;
		tree_create(&((*tree)->lchild));
		tree_create(&((*tree)->rchild));
	}
	
}

void presearch(bitree *tree){
	if(tree == NULL){
		return;
	}
	printf("%c",tree->data);
	presearch(tree->lchild);
	presearch(tree->rchild);
}

void midsearch(bitree *tree){

	if(tree == NULL){
		return;
	}
	midsearch(tree->lchild);
	printf("%c",tree->data);
	midsearch(tree->rchild);
}

void postsearch(bitree *tree){
	if(tree == NULL){
		return;
	}
	
	postsearch(tree->lchild);
	postsearch(tree->rchild);
	printf("%c",tree->data);
}

void main(){
	bitree *tree =NULL;
	tree_create(&tree);
	
	presearch(tree);
	printf("\n");
	midsearch(tree);
	printf("\n");
	postsearch(tree);
	printf("\n");
}