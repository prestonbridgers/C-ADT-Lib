#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int bst_destroy(BST *tree)
{
    if (tree == NULL)
        return 1;

    bst_destroy(tree->left);
    bst_destroy(tree->right);

    free(tree);

    return 0;
}

int bst_insert(BST **tree, int val)
{
    if (*tree == NULL)
    {
        BST *tmp = calloc(1, sizeof(*tmp));
        tmp->data = val;
        tmp->left = NULL;
        tmp->right = NULL;
        *tree = tmp;
        return 1;
    }

    if (val < (*tree)->data)
        bst_insert(&(*tree)->left, val);
    else
        bst_insert(&(*tree)->right, val);
    return 0;
}

int bst_min(BST *tree)
{
    if (tree->left == NULL)
        return tree->data;
    return bst_min(tree->left);
}

int bst_max(BST *tree)
{
    if (tree->right == NULL)
        return tree->data;
    return bst_max(tree->right);
}

int bst_print(BST *tree)
{
    if (tree == NULL)
        return 1;

    bst_print(tree->left);
    printf("%d ", tree->data);
    bst_print(tree->right);

    return 0;
}
