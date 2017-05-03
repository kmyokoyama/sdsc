#include <stdio.h>
#include <sdsc.h>

#define TEST_PASSED (1)
#define TEST_FAILED (0)

int test_number_of_nodes(BST_NODE *root) {
    int size = bst_size(root);

    if (size == 9) {
        printf("Test passed.\n");
        return TEST_PASSED;
    }

    printf("Test failed.\n");

    return TEST_FAILED;
}

int test_depth(BST_NODE *root) {
    int depth = bst_depth(root);

    if (depth == 4) {
        printf("Test passed.\n");
        return TEST_PASSED;
    }

    printf("Test failed.\n");

    return TEST_FAILED;
}

int test_height(BST_NODE *root) {
    int height = bst_depth(root);

    if (height == 4) {
        printf("Test passed.\n");
        return TEST_PASSED;
    }

    printf("Test failed.\n");

    return TEST_FAILED;
}

int test_minimum(BST_NODE *root) {
    BST_NODE *node_minimum = bst_minimum(root);

    if (node_minimum->data == 'A') {
        printf("Test passed.\n");
        return TEST_PASSED;
    }

    printf("Test failed.\n");

    return TEST_FAILED;
}

int test_maximum(BST_NODE *root) {
    BST_NODE *node_maximum = bst_maximum(root);

    if (node_maximum->data == 'I') {
        printf("Test passed.\n");
        return TEST_PASSED;
    }

    printf("Test failed.\n");

    return TEST_FAILED;
}

int test_predecessor(BST_NODE *node) {
    BST_NODE *predecessor = bst_predecessor(node);

    if (predecessor->data == 'E') {
        printf("Test passed.\n");
        return TEST_PASSED;
    }
    
    printf("Test failed.\n");

    return TEST_FAILED;
}

int test_successor(BST_NODE *node) {
    BST_NODE *successor = bst_successor(node);

    if (successor->data == 'G') {
        printf("Test passed.\n");
        return TEST_PASSED;
    }
    
    printf("Test failed.\n");

    return TEST_FAILED;
}

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

    test_number_of_nodes(root);
    test_depth(root);
    test_height(root);
    test_minimum(root);
    test_maximum(root);
    test_predecessor(root);
    test_successor(root);

    /*
    printf("Pre-order walk:\n");
    bst_preorder_walk(root);

    printf("In-order walk:\n");
    bst_inorder_walk(root);

    printf("Post-order walk:\n");
    bst_postorder_walk(root);
    */

    bst_destroy(root);

    return 0;
}
