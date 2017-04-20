#include <stdio.h>
#include <trees.h>

int main(int argc, char **argv) {
    BST_NODE *root;

    bst_initialize(&root);

    root = bst_insert(root, 'F');
    root = bst_insert(root, 'B');
    root = bst_insert(root, 'A');
    root = bst_insert(root, 'D');
    root = bst_insert(root, 'C');
    root = bst_insert(root, 'E');
    root = bst_insert(root, 'G');
    root = bst_insert(root, 'I');
    root = bst_insert(root, 'H');

    printf("Number of nodes: %d\n", bst_size(root));
    printf("Depth: %d\n", bst_depth(root));
    printf("Height: %d\n", bst_height(root));
    printf("Minimum: %c\n", bst_minimum(root)->data);
    printf("Maximum: %c\n", bst_maximum(root)->data);

    printf("Pre-order walk:\n");
    bst_preorder_walk(root);

    printf("In-order walk:\n");
    bst_inorder_walk(root);

    printf("Post-order walk:\n");
    bst_postorder_walk(root);

    bst_destroy(root);

    return 0;
}
