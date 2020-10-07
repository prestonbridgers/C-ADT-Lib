#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree{
	int data;
	struct BinarySearchTree *left;
	struct BinarySearchTree *right;
}BinarySearchTree;

int bst_add(BinarySearchTree **tree, int val);
int bst_print(BinarySearchTree *tree);
	
int main(void)
{
	BinarySearchTree *bst = NULL;

	printf("Adding a number to an empty list\n");
	bst_add(&bst, 9);
	bst_add(&bst, 10);
	bst_add(&bst, 3);
	bst_add(&bst, 17);
	bst_add(&bst, 8);
	bst_add(&bst, 15);

	printf("Printing the list\n");
	bst_print(bst);
	printf("\n");

	return 0;
}

int bst_add(BinarySearchTree **tree, int val)
{
    if (*tree == NULL)
    {
        BinarySearchTree *tmp = calloc(1, sizeof(*tmp));
        tmp->data = val;
        tmp->left = NULL;
        tmp->right = NULL;
        *tree = tmp;
        return 0;
    }

    if (val < (*tree)->data)
        bst_add(&(*tree)->left, val);
    else
        bst_add(&(*tree)->right, val);
}

int bst_print(BinarySearchTree *tree)
{
    if (tree == NULL)
        return 1;

	bst_print(tree->left);
	printf("%d ", tree->data);
	bst_print(tree->right);


    return 0;
}
