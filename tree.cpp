#include<iostream>
#include<vector>
#include <queue>

using namespace std;
int level = 0;

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

void left_view(Node* root, int curLevel=1)
{
	if (root == NULL)
		return;
	if (curLevel > level)
	{
		cout << root->key << " ";
		level = curLevel;
	}

	left_view(root->left, curLevel + 1);
	left_view(root->right, curLevel + 1);
}

void left_view_iter(Node* root, int curLevel=1)
{
	if (root == NULL)
		return;
	int level = 0;
	queue<Node*> q;
	q.push(root);
	while (q.size() > 0)
	{
		// Can be done by following method on line 125
		// Add condition if(i==0) to print the first element in the loop

		Node* cur = q.front();
		if (curLevel > level)
		{
			cout << cur->key << " ";
			level = curLevel;
			curLevel += 1;
			q = {};
		}
		if (cur->left != NULL)
			q.push(cur->left);
		if (cur->right != NULL)
			q.push(cur->right);
	}
}

bool child_sum(Node* root)
{
	if (root == NULL || ((root->left == NULL) && (root->right == NULL)))
		return true;

	int sum = 0;
	if (root->left != NULL)
		sum += root->left->key;
	if (root->right != NULL)
		sum += root->right->key;
	return (root->key == sum && child_sum(root->left) && child_sum(root->right));
}

bool balanced(Node* root)
{
	if (root == NULL)
		return true;
	int lh = height(root->left);
	int rh = height(root->right);
	return (abs(lh - rh) <= 1 && balanced(root->left) && balanced(root->right));
}

int balanced_efficient(Node* root)
{
	if (root == NULL)
		return 0;

	int lh = balanced_efficient(root->left);
	if (lh == -1) return -1;
	int rh = balanced_efficient(root->right);
	if (rh == -1) return -1;

	if (abs(lh - rh) > 1)
		return -1;
	else
		return(max(lh, rh) + 1);
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
	cout << "\nLeft view of binary tree : ";
	left_view(root);
	cout << "\nLeft view of binary tree(Iterative) : ";
	left_view_iter(root);
	cout << "\nCheck binary tree is balanced or not : ";
	cout << balanced(root);
	cout << "\nCheck binary tree is balanced or not (Efficient) Returns height if true : ";
	cout << balanced_efficient(root);
	return 0;
}
