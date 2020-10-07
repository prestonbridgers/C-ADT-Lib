Binary Search Tree
==================

The BST implementation is still a work in progress.

Headerfile
----------

The header file is called ``bst.h``.
The functions below are how you will interface with the code.

.. code-block:: c

	Queue*	bst_create();
	void	bst_destroy(BinarySearchTree **tree);
	void 	bst_add(BinarySearchTree **tree, int val);
	void	bst_print(BinarySearchTree *tree);

Code Example
------------

The following example demonstrates a typical use case including the use of a callback function:

.. code-block:: c

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
