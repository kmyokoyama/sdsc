#include <stdio.h>
#include <trees.h>

int main(int argc, char **argv) {
    BST_NODE *root;

    bst_initialize(&root);

    root = bst_insert(root, 2);
    root = bst_insert(root, 1);
    root = bst_insert(root, 3);
    root = bst_insert(root, 4);
    root = bst_insert(root, 5);

    printf("Number of nodes: %d\n", bst_count(root));
    printf("Depth: %d\n", bst_depth(root));
    printf("Height: %d\n", bst_height(root));
    printf("Minimum: %d\n", bst_minimum(root));
    printf("Maximum: %d\n", bst_maximum(root));

    bst_print(root);

    bst_destroy(root);

    return 0;
}
