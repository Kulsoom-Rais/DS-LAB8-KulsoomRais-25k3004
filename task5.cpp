#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* createTree()
{
    int value;

    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* newNode = new Node(value);

    cout << "Left child of " << value << endl;
    newNode->left = createTree();

    cout << "Right child of " << value << endl;
    newNode->right = createTree();

    return newNode;
}

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    cout << "Create Binary Tree\n";

    Node* root = createTree();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
