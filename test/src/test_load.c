#include <stdio.h>
#include <stdlib.h>
#include <sdsc.h>

int main(int argc, char **argv) {
    BST_NODE *root;

    root = load_bst("../../data/ints");

    printf("Preorder walk\n");
    bst_preorder_walk(root);

    printf("Inorder walk\n");
    bst_inorder_walk(root);

    printf("Postorder walk\n");
    bst_postorder_walk(root);

    return 0;
}
