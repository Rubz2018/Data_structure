#include <stdio.h>
#include <stdlib.h>

struct node
{
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
  temp->key = item;                                               // Assign the value to the node
  temp->left = temp->right = NULL;                                // Initialize the left and right child pointers to NULL
  return temp;                                                    // Return the created node
}

// Inorder Traversal
void inorder(struct node *root)
{
  if (root != NULL)
  {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key)
{
  if (node == NULL) // If the tree is empty, create a new node
    return newNode(key);

  if (key < node->key) // If the key is smaller, insert into the left subtree
    node->left = insert(node->left, key);
  else // If the key is greater, insert into the right subtree
    node->right = insert(node->right, key);

  return node; // Return the updated node
}

// Find the inorder successor
struct node *minValueNode(struct node *node)
{
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
  // Return if the tree is empty
  if (root == NULL)
    return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else
  {
    // If the node is with only one child or no child
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
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main()
{
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
  printf("Inorder traversal: ");
  inorder(root);
  printf("\nAfter deleting:\n");
  root = deleteNode(root, 7);
  printf("Inorder traversal: ");
  inorder(root);
}
