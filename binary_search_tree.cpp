#include<iostream>
#include<queue>
#include<set>
#include "Source.h"

struct Node {
	int key;
	Node* left, * right;

	Node(int x)
	{
		key = x;
		left = right = NULL;
	}
};

void traverse(Node* root)
{
	if (root == NULL)
		return;
	std::cout << "\n";
	std::queue<Node*> q;
	q.push(root);
	while (q.size() > 0)
	{
		int s = q.size();
		for (int i = 0; i < s; i++)
		{
			Node* cur = q.front();
			std::cout << q.front()->key << " ";
			q.pop();
			
			if (cur->left != NULL)
				q.push(cur->left);
			if (cur->right != NULL)
				q.push(cur->right);	
		}
		std::cout << "\n";
	}
}

bool search(Node* root, int x)
{
	if (root == NULL)
		return false;
	else if (root->key == x)
		return true;
	else if (root->key > x)
		return search(root->left, x);
	else
		return search(root->right, x);
}

bool searchIter(Node* root, int x)
{
	while (root != NULL)
	{ 
		if (root->key == x)
			return true;
		else if (root->key > x)
			root = root->left;
		else
			root = root->right;
	}		
	return false;
}

Node* insert(Node* root, int x)
{
	if (root == NULL)
	{
		root = new Node(x);
		return root;
	}
	else if (x > root->key)
		root->right = insert(root->right, x);
	else if (x < root->key)
		root->left = insert(root->left, x);
	return root;
}

Node* insertIter(Node* root, int x)
{
	Node* temp = new Node(x);
	Node* parent = NULL, * cur = root;
	while (cur != NULL)
	{
		parent = cur;
		if (cur->key > x)
			cur = cur->left;
		else if (cur->key < x)
			cur = cur->right;
		else
			return root;
	}
	if (parent == NULL)
		return temp;
	if (parent->key > x)
		parent->left = temp;
	else
		parent->right = temp;
	return root;
}

Node* getSuccessor(Node* root)
{
	root = root->right;
	while (root != NULL && root->left != NULL)
			root = root->left;
	return root;
}

Node* delNode(Node* root, int x)
{
	if (root == NULL)
		return root;
	if (root->key > x)
		root->left = delNode(root->left, x);
	else if (root->key < x)
		root->right = delNode(root->right, x);
	else
	{
		if (root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			Node* cur = getSuccessor(root);
			root->key = cur->key;
			root->right = delNode(root->right, cur->key);
		}
	}
	return root;
}

Node* floor(Node* root, int x)
{
	Node* res = NULL;
	while (root != NULL)
	{
		if (root->key == x)
			return root;
		else if (root->key > x)
		{ 
			res = root;
			root = root->left;
		}
			
		else
			root = root->right;
	}
	return res;
}

Node* ceil(Node* root, int x)
{
	Node* res = NULL;
	while (root != NULL)
	{
		if (root->key == x)
			return root;
		else if (root->key > x)
			root = root->left;
		else {
			res = root;
			root = root->right;
		}
	}
	return res;
}



int main()
{
	Node* root = new Node(50);
	insert(root, 20);
	insert(root, 30);
	insert(root, 40);
	insert(root, 10);
	insert(root, 60);
	insertIter(root, 70);
	insertIter(root, 80);
	insertIter(root, 35);
	insertIter(root, 45);
	insertIter(root, 65);
	insertIter(root, 55);

	//				50
	//			  /	   \
	//			 /	    \
	//			/	     \
	//		  20		  60
	//		/   \		/	\
	//	   10	30	   55		70
	//			 \		   /   \
	//			 40		  65	80
	//			/  \	 	
	//		   35   45   

	std::cout << "Level order traversal : \n";
	traverse(root);
	std::cout << "\nSearching for node -> ";
	std::cout << "\nWhen node is present : " << search(root, 40) << "\nWhen node is not present : " << searchIter(root, 100);
	std::cout << "\n\nDelete a node -> : ";
	delNode(root, 40);
	delNode(root, 100);
	traverse(root);
	std::cout << "\nFloor in a BST : ";
	std::cout << floor(root, 56)->key;
	std::cout << "\nCeil in a BST : ";
	std::cout << ceil(root, 56)->key;
	return 0;
}