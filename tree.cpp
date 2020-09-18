#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>

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

int height(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return max(height(root->left), height(root->right)) + 1;
}

// Print nodes at k distance
void printk(Node* root, int k)
{
	if (root != NULL)
	{
		if (k == 0)
			cout << root->key << " ";

		printk(root->left, k-1);
		printk(root->right, k - 1);
	}

}


void breadth_slow(Node* root)
{
	int h = height(root);

	for (int i = 0; i < h; i++)
		printk(root, i);
}

// Level order traversal Efficient
void breadth(Node* root)
{
	if (root == NULL)
		return;
	
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (q.size() > 1)
	{
		Node* cur = q.front();
		q.pop();
		
		if (cur == NULL)
		{
			cout << "\n";
			q.push(NULL);
			continue;
		}

		cout << cur->key << " ";

		if (cur -> left != NULL)
			q.push(cur->left);
		if (cur -> right != NULL)
			q.push(cur->right);
	}
}

// Level order traversal with new line
void breadth_m2(Node* root)
{
	queue<Node*> q;
	if (root == NULL)
		return;

	q.push(root);
	while (q.size() > 0)
	{
		int count = q.size();
		for (int i = 0; i < count; i++)
		{
			Node* cur = q.front();
			cout << cur->key << " ";
			q.pop();

			if(cur->left != NULL)
				q.push(cur->left);
			if (cur->right != NULL)
				q.push(cur->right);
		}
		cout << "\n";
	}
}

int getSize(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + getSize(root->left) + getSize(root->right);
}

int getSize_iter(Node* root)
{
	if (root == NULL)
		return 0;

	queue<Node*> x;
	x.push(root);
	int count = 0;
	while (x.size() > 0)
	{
		Node* cur = x.front();
		count += 1;
		x.pop();
		if(cur->left != NULL)
			x.push(cur->left);
		if(cur->right != NULL)
			x.push(cur->right);
	}
	return count;
}

int getMax(Node* root)
{
	if (root == NULL)
		return INT_MIN;
	else
		return max(root->key, max(getMax(root->left), getMax(root->right)));
}

int main()
{
	Node* root = new Node(10);
	Node* n11 = new Node(20);
	Node* n12 = new Node(30);
	Node* n21 = new Node(40);
	Node* n22 = new Node(50);
	Node* n23 = new Node(60);
	Node* n31 = new Node(70);

	root->right = n12;
	root->left = n11;
	n11->right = n22;
	n11->left = n21;
	n12->left = n23;
	n21->right = n31;

	cout << "Inorder traversal : ";
	inorder(root);
	cout << "\n";
	cout << "Preorder traversal : ";
	preorder(root);
	cout << "\n";
	cout << "Postorder traversal : ";
	postorder(root);
	cout << "\n";
	cout << "Height of binary tree : " << height(root);
	cout << "\n";
	cout << "Print node at k distance : ";
	printk(root, 3);
	cout << "\n";
	cout << "Level order traversal inefficient : ";
	breadth_slow(root);
	cout << "\n";
	cout << "Level order traversal efficient : \n";
	breadth(root);
	cout << "\n";
	cout << "Level order traversal efficient Method 2: \n";
	breadth_m2(root);
	cout << "Size of binary tree : ";
	cout << getSize(root);
	cout << "\nSize of binary tree Iterative : ";
	cout << getSize_iter(root);
	cout << "\nMax in binary tree : ";
	cout << getMax(root);
	return 0;
}

