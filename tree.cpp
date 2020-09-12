#include<iostream>

using namespace std;

// Implementation of basic binary tree
struct Node {
	int key;
	Node *left;
	Node *right;

	Node(int x)
	{
		key = x;
		left = right = NULL;
	}

};

void inorder(Node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

void preorder(Node* root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->key << " ";
	}
}

int main()
{
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);

	cout << "Inorder traversal : ";
	inorder(root);
	cout << "\n";
	cout << "Preorder traversal : ";
	preorder(root);
	cout << "\n";
	cout << "Postorder traversal : ";
	postorder(root);
	cout << "\n";

	return 0;
}