#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Search Tree (BST) node
struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;

// Function to create a new node in the BST
NODE* createTree(NODE *node, int data) {
    if (node == NULL) {
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < node->data) {
        node->left = createTree(node->left, data);
    } else if (data > node->data) {
        node->right = createTree(node->right, data);
    }
    return node;
}

// Function to search for an element in the BST
NODE* search(NODE *node, int data) {
    if (node == NULL) {
        printf("\nElement not found");
    } else if (data < node->data) {
        node->left = search(node->left, data);
    } else if (data > node->data) {
        node->right = search(node->right, data);
    } else {
        printf("\nElement found: %d", node->data);
    }
    return node;
}

// Function for inorder traversal (Left, Root, Right)
void inorder(NODE *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

// Function for preorder traversal (Root, Left, Right)
void preorder(NODE *node) {
    if (node != NULL) {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Function for postorder traversal (Left, Right, Root)
void postorder(NODE *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}

// Main function
int main() {
    int data, choice, i, n;
    NODE *root = NULL;

    while (1) {
        printf("\n1. Insert into Binary Search Tree");
        printf("\n2. Search in Binary Search Tree");
        printf("\n4. Inorder Traversal");
        printf("\n5. Preorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the number of elements to insert: ");
                scanf("%d", &n);
                printf("\nEnter the elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = createTree(root, data);
                }
                break;
            case 2:
                printf("\nEnter the element to search: ");
                scanf("%d", &data);
                root = search(root, data);
                break;
           
            case 3:
                printf("\nInorder Traversal: \n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPreorder Traversal: \n");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nPostorder Traversal: \n");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}
