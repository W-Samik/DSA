#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* l_node;
    struct node* r_node;
} node;

node* root = NULL;

// Create a new node
node* createnode(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->l_node = NULL;
    new->r_node = NULL;
    return new;
}

// Insert function (returns updated root)
node* insert(node* n, int data) {
    if (n == NULL) {
        return createnode(data);
    }
    if (data < n->data) {
        n->l_node = insert(n->l_node, data);
    } else {
        n->r_node = insert(n->r_node, data);
    }
    return n;
}

// Inorder traversal
void inorder(node* n) {
    if (n != NULL) {
        inorder(n->l_node);
        printf("%d ", n->data);
        inorder(n->r_node);
    }
}
int main() {
    int values[] = {10, 5, 15, 3, 7};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}
