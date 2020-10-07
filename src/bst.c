#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BinarySearchTree{
	int data;
	struct BinarySearchTree *left;
	struct BinarySearchTree *right;
}BinarySearchTree;

int bst_add(BinarySearchTree **tree, int val);
int bst_destroy(BinarySearchTree *tree);
int bst_print(BinarySearchTree *tree);
	
int main(void)
{
	BinarySearchTree *bst = NULL;

    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        int n = rand() % 1000;
	    bst_add(&bst, n);
    }

	printf("Printing the tree\n");
	bst_print(bst);
	printf("\n");

    printf("Destroying the tree\n");
    bst_destroy(bst);
	return 0;
}

int bst_destroy(BinarySearchTree *tree)
{
    if (tree == NULL)
        return 1;

    bst_destroy(tree->left);
    bst_destroy(tree->right);

    free(tree);

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
