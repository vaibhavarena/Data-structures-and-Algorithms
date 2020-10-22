#include<iostream>
#include<queue>
#include<set>
#include<stack>
#include "Source.h"

struct Node {
	int key;
	Node* left, * right;
	int nodes;
	Node(int x)
	{
		key = x;
		left = right = NULL;
		nodes = 0;
	}
};

void inorder(Node* root)
{
	std::vector<int> v;
	std::stack<Node*> s;

	while (root)
	{
		s.push(root);
		root = root->left;
	}
	
	while (!s.empty())
	{
		Node* cur = s.top();
		s.pop();

		v.push_back(cur->key);

		Node* right = cur->right;

		while (right)
		{
			s.push(right);
			right = right->left;
		}
	}

	for (auto i : v)
		std::cout << i << " ";
}


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


// Find successor node for an element to be deleted
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


//Find the floor of an element
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


// Find the ceiling of an element
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

// Find ceiling on left side of an array
void ceil_left(int arr[], int n)
{
	std::set<int> s;

	for (int i = 0; i < n; i++)
	{
		s.insert(arr[i]);
		auto x = s.upper_bound(arr[i]);
		if (x == s.end())
			std::cout << -1 << " ";
		else
			std::cout << *x << " ";
		s.insert(arr[i]);
	}
}


int countNodes(Node* root)
{
	if (root == NULL)
		return 0;
	else return 1 + (countNodes(root->left)) + (countNodes(root->right));
}



// Find kth smallest element
int lcount(Node* root, int k)
{
	if (root == NULL)
		return NULL;

}

int small(Node* root)
{
	if (root == NULL)
		return INT_MAX;
	else
		return std::min(root->key, std::min(small(root->left), small(root->right)));
}

int large(Node* root)
{
	if (root == NULL)
		return INT_MIN;
	else
		return std::max(root->key, std::max(large(root->left), large(root->right)));
}

bool checkBst(Node* root)
{
	if (root == NULL)
		return true;
	else if (root->key > large(root->left) && root->key < small(root->right))
		return true;
	else
		return false;
}

// Check for BST with min max approach
bool isbst(Node* root, int min, int max)
{
	if (root == NULL)
		return true;
	return ((root->key > min) && (root->key < max) && isbst(root->left, min, root->key) && isbst(root->right, root->key, max));
}


// Check for BST with inorder traversal approach
int prev = INT_MIN;
bool isBst(Node* root)
{
	if (root == NULL)
		return true;
	if (isBst(root->left) == false) return false;
	if (root->key <= prev) return false;
	prev = root->key;
	return isBst(root->right);
}

void fixBst(Node* root)
{

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
	
	
	std::cout << "Inorder traversal : ";
	inorder(root);

	std::cout << "\nLevel order traversal : \n";
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

	int arr[] = { 3,5,9,2,1,6 };
	std::cout << "\nCeil on left side of an array : ";
	ceil_left(arr, sizeof(arr) / sizeof(arr[0]));
	std::cout << "\nCheck for BST : ";
	std::cout << checkBst(root);
	std::cout << "\nCheck for BST(Efficient Min Max solution) : ";
	std::cout << isbst(root, INT_MIN, INT_MAX);
	std::cout << "\nCheck for BST(Efficient Inorder solution) : ";
	std::cout << isBst(root);
	

	return 0;
}