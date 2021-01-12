#ifndef H_INCLUDED_BST
#define H_INCLUDED_BST

typedef struct BST{
	int data;
	struct BST *left;
	struct BST *right;
}BST;

int bst_insert(BST **tree, int val);
int bst_min(BST *tree);
int bst_max(BST *tree);
int bst_pred(BST *tree, int pred, int key);
int bst_destroy(BST *tree);
int bst_print(BST *tree);

#endif
