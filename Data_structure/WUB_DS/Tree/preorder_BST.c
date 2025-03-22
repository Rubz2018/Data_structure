#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the Binary Search Tree
struct node
{
    int key;
    struct node *left, *right;
};

// Create a new node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;                // Assign the value to the node
    temp->left = temp->right = NULL; // Initialize child pointers as NULL
    return temp;
}

// Preorder Traversal
void preorder(struct node *root)
{
    if (root != NULL)
    {
        // Visit the root node
        printf("%d -> ", root->key);

        // Traverse the left subtree
        preorder(root->left);

        // Traverse the right subtree
        preorder(root->right);
    }
}

// Insert a node into the BST
struct node *insert(struct node *node, int key)
{
    if (node == NULL) // If the tree is empty, create a new node
        return newNode(key);

    // Traverse to the appropriate position
    if (key < node->key)
        node->left = insert(node->left, key); // Insert into the left subtree
    else
        node->right = insert(node->right, key); // Insert into the right subtree

    return node;
}

// Find the minimum value node (used for deletion)
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    // Find the leftmost (smallest) node
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Delete a node from the BST
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL) // Base case: if the tree is empty
        return root;

    // Traverse to find the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // If the node has one or no children
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node *temp = minValueNode(root->right); // Find the inorder successor

        root->key = temp->key;                            // Replace key with the successor's key
        root->right = deleteNode(root->right, temp->key); // Delete the successor
    }
    return root;
}

// Driver code
int main()
{
    struct node *root = NULL;

    // Insert nodes into the BST
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    // Display preorder traversal
    printf("Preorder traversal: ");
    preorder(root);

    // Delete a node
    printf("\nAfter deleting 7:\n");
    root = deleteNode(root, 7);

    // Display preorder traversal after deletion
    printf("Preorder traversal: ");
    preorder(root);

    return 0;
}
