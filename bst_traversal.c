
#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Search Tree node
typedef struct Book {
    int acc;
    struct Book *left;
    struct Book *right;
} Book;

// TODO 1: Implement BST Insert
Book *insert(Book *root, int acc) {

    if (root == NULL) {
        Book *newNode = (Book *)malloc(sizeof(Book));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        newNode->acc = acc;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (acc < root->acc) {
        root->left = insert(root->left, acc);
    }
    else if (acc > root->acc) {
        root->right = insert(root->right, acc);
    }

    return root;
}

// TODO 2: Implement Tree Height
int height(const Book *x) {

    if (x == NULL)
        return -1;

    int hLeft = height(x->left);
    int hRight = height(x->right);

    return 1 + (hLeft > hRight ? hLeft : hRight);
}

// Inorder Traversal
void inorder(const Book *root) {

    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->acc);
    inorder(root->right);
}

// Main Function
int main() {

    Book *root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80, 65};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Binary Search Tree\n");

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nTree Height: %d\n", height(root));

    return 0;
}
