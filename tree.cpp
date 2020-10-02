#include<iostream>
#include<vector>
#include <queue>
#include<stack>

int level = 0;
int preIndex = 0;
int in[] = { 20, 10, 40, 30, 50 };
int pre[] = {10, 20, 30, 40, 50};
int res = 0;
int res_burn = 0;
// Implementation of basic binary tree
struct Node {
	int key;
	Node* left;
	Node* right;

	Node(int x)
	{
		key = x;
		left = right = NULL;
	}

};
Node* prev = NULL;
void inorder(Node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		std::cout << root->key << " ";
		inorder(root->right);
	}
}

void preorder(Node* root)
{
	if (root != NULL)
	{
		std::cout << root->key << " ";
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
		std::cout << root->key << " ";
	}
}

int height(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return std::max(height(root->left), height(root->right)) + 1;
}

// Print nodes at k distance
void printk(Node* root, int k)
{
	if (root != NULL)
	{
		if (k == 0)
			std::cout << root->key << " ";

		printk(root->left, k - 1);
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

	std::queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (q.size() > 1)
	{
		Node* cur = q.front();
		q.pop();

		if (cur == NULL)
		{
			std::cout << "\n";
			q.push(NULL);
			continue;
		}

		std::cout << cur->key << " ";

		if (cur->left != NULL)
			q.push(cur->left);
		if (cur->right != NULL)
			q.push(cur->right);
	}
}

// Level order traversal with new line
void breadth_m2(Node* root)
{
	std::queue<Node*> q;
	if (root == NULL)
		return;

	q.push(root);
	while (q.size() > 0)
	{
		int count = q.size();
		for (int i = 0; i < count; i++)
		{
			Node* cur = q.front();
			std::cout << cur->key << " ";
			q.pop();

			if (cur->left != NULL)
				q.push(cur->left);
			if (cur->right != NULL)
				q.push(cur->right);
		}
		std::cout << "\n";
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

	std::queue<Node*> x;
	x.push(root);
	int count = 0;
	while (x.size() > 0)
	{
		Node* cur = x.front();
		count += 1;
		x.pop();
		if (cur->left != NULL)
			x.push(cur->left);
		if (cur->right != NULL)
			x.push(cur->right);
	}
	return count;
}

int getMax(Node* root)
{
	if (root == NULL)
		return INT_MIN;
	else
		return std::max(root->key, std::max(getMax(root->left), getMax(root->right)));
}

void left_view(Node* root, int curLevel = 1)
{
	if (root == NULL)
		return;
	if (curLevel > level)
	{
		std::cout << root->key << " ";
		level = curLevel;
	}

	left_view(root->left, curLevel + 1);
	left_view(root->right, curLevel + 1);
}

void left_view_iter(Node* root, int curLevel = 1)
{
	if (root == NULL)
		return;
	int level = 0;
	std::queue<Node*> q;
	q.push(root);
	while (q.size() > 0)
	{
		// Can be done by following method on line 125
		// Add condition if(i==0) to print the first element in the loop

		Node* cur = q.front();
		if (curLevel > level)
		{
			std::cout << cur->key << " ";
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
		return(std::max(lh, rh) + 1);
}

int max_width(Node* root)
{
	if (root == NULL) return 0;
	std::queue<Node*> q;
	q.push(root);
	int res = 0;
	while (q.size() > 0)
	{
		int count = q.size();
		res = std::max(res, count);
		for (int i = 0; i < count; i++)
		{
			Node* cur = q.front();
			q.pop();

			if (cur->left != NULL)
				q.push(cur->left);
			if (cur -> right != NULL)
				q.push(cur->right);
		}
	}
	return res;
}

Node* binary_to_dll(Node* root)
{
	if (root == NULL) return root;
	Node* head = binary_to_dll(root->left);

	if (prev == NULL) head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	binary_to_dll(root->right);
	return head;
}

void traverse_dll(Node* head)
{
	while (head != NULL)
	{
		std::cout << head->key << " ";
		head = head->right;
	}
}

Node* binary_construct(int in[], int pre[], int is, int ie)
{
	if (is > ie) return NULL;
	Node* root = new Node(pre[preIndex++]);

	int inIndex;

	for (int i = is; i <= ie; i++)
	{
		if (root->key == in[i])
		{
			inIndex = i;
			break;
		}
	}

	root->left = binary_construct(in, pre, is, inIndex - 1);
	root->right = binary_construct(in, pre, inIndex + 1, ie);

	return root;
}

void spiral(Node* root)
{
	if (root == NULL)
		return;

	std::queue<Node*> q;
	std::stack<int> s;
	bool reverse = false;

	q.push(root);
	while (q.empty() == false)
	{
		int count = q.size();
		for (int i = 0; i < count; i++)
		{
			Node* cur = q.front();
			q.pop();

			if (reverse) 
				s.push(cur->key);
			else
				std::cout << cur->key << " ";
			
			if (cur->left != NULL) q.push(cur->left);
			if (cur->right != NULL) q.push(cur->right);
		}

		if (reverse)
		{
			while (s.empty() == false)
			{
				std::cout << s.top() << " ";
				s.pop();
			}
		}
		reverse = !reverse;
		std::cout << "\n";
	}
}

void spiral_efficient(Node* root)
{
	if (root == NULL) return;

	std::stack<Node*> s1;
	std::stack<Node*> s2;
	bool count = true;
	s1.push(root);
	while (s1.empty() == false || s2.empty() == false)
	{
		if (count)
		{
			int x = s1.size();
			for (int i = 0; i < x; i++)
			{
				if (s1.top()->left != NULL)
					s2.push(s1.top()->left);
				if (s1.top()->right != NULL)
					s2.push(s1.top()->right);
				
				std::cout << s1.top()->key << " ";
				s1.pop();
			}
			std::cout << "\n";
			count = !count;
		}
		else
		{
			int x = s2.size();
			for (int i = 0; i < x; i++)
			{
				if (s2.top()->right != NULL)
					s1.push(s2.top()->right);
				if (s2.top()->left != NULL)
					s1.push(s2.top()->left);


				std::cout << s2.top()->key << " ";
				s2.pop();
			}
			std::cout << "\n";
			count = !count;
		}
	}
}

int diameter(Node* root)
{
	if (root == NULL) return 0;

	int d1 = 1 + height(root->left) + height(root->right);
	int d2 = diameter(root->left);
	int d3 = diameter(root->right);

	return std::max(d1, std::max(d2, d3));
}

int diameter_efficient(Node* root)
{
	if (root == NULL)
		return 0;
	
	int lh = diameter_efficient(root->left);
	int rh = diameter_efficient(root->right);

	res = std::max(res, 1 + lh + rh);
	return 1 + std::max(lh, rh);
}

bool findPath(Node* root, std::vector<Node*> &path, int x)
{
	if (root == NULL) return false;

	path.push_back(root);
	
	if (root->key == x) return true;
	
	if ((root->left && findPath(root->left, path, x)) || (root->right && findPath(root->right, path, x)))
		return true;
	path.pop_back();
	return false;
}

Node* lca(Node* root, int x , int y)
{
	std::vector<Node*> p1, p2;

	if (findPath(root, p1, x) == false || findPath(root, p2, y) == false)
		return NULL;
	
	for (int i = 0; i < p1.size() - 1 && i < p2.size() - 1; i++)
	{
		if (p1[i + 1] != p2[i + 1])
			return p1[i];
	}
}

Node* lca_e(Node* root, int n1, int n2)
{
	if (root == NULL)
		return NULL;

	if (root->key == n1 || root->key == n2)
		return root;

	Node* l = lca_e(root->left, n1, n2);
	Node* r = lca_e(root->right, n1, n2);

	if (l != NULL && r != NULL)
		return root;

	if (l != NULL)
		return l;
	else
		return r;
}

int burnTime(Node* root, int leaf, int& dist)
{
	if (root == NULL)
		return 0;
	if (root->key == leaf)
	{
		dist = 0;
		return 1;
	}
	
	int ldist = -1, rdist = -1;
	int lh = burnTime(root->left, leaf, ldist);
	int rh = burnTime(root->right, leaf, rdist);

	if (ldist != -1)
	{
		dist = ldist + 1;
		res = std::max(res, dist + rh);
	}
	else if (rdist != -1)
	{
		dist = rdist + 1;
		res = std::max(res, dist + lh);
	}
	return std::max(lh, rh) + 1;
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

	//			 10 
	//		    /   \
	//		  20     30
	//		 / \     /
	//		40 50   60
	//	   /
	//	  70
	root->left = n11;
	root->right = n12;
	n11->left = n21;
	n11->right = n22;
	n12->left = n23;
	n21->right = n31;

	std::cout << "Inorder traversal : ";
	inorder(root);
	std::cout << "\n";
	std::cout << "Preorder traversal : ";
	preorder(root);
	std::cout << "\n";
	std::cout << "Postorder traversal : ";
	postorder(root);
	std::cout << "\n";
	std::cout << "Height of binary tree : " << height(root);
	std::cout << "\n";
	std::cout << "Print node at k distance : ";
	printk(root, 3);
	std::cout << "\n";
	std::cout << "Level order traversal inefficient : ";
	breadth_slow(root);
	std::cout << "\n";
	std::cout << "Level order traversal efficient : \n";
	breadth(root);
	std::cout << "\n";
	std::cout << "Level order traversal efficient Method 2: \n";
	breadth_m2(root);
	std::cout << "Size of binary tree : ";
	std::cout << getSize(root);
	std::cout << "\nSize of binary tree Iterative : ";
	std::cout << getSize_iter(root);
	std::cout << "\nMax in binary tree : ";
	std::cout << getMax(root);
	std::cout << "\nLeft view of binary tree : ";
	left_view(root);
	std::cout << "\nLeft view of binary tree(Iterative) : ";
	left_view_iter(root);
	std::cout << "\nCheck binary tree is balanced or not : ";
	std::cout << balanced(root);
	std::cout << "\nCheck binary tree is balanced or not (Efficient) Returns height if true : ";
	std::cout << balanced_efficient(root);
	std::cout << "\nMax width of binary tree : ";
	std::cout << max_width(root);
	std::cout << "\nConvert binary tree to dll : ";
	// Binary to dll conversion is making modifications to root, so moved to end
	std::cout << "\nConstructing a binary tree from inorder and preorder arrays : ";
	Node* bin_tree_head = binary_construct(in, pre, 0, *(&pre + 1) - pre - 1);
	std::cout << "\nInorder new construct : ";
	inorder(bin_tree_head);
	std::cout << "\nPreorder new construct : ";
	preorder(bin_tree_head);
	std::cout << "\nSpiral traversal of binary tree : ";
	spiral(root);
	std::cout << "\nSpiral traversal of binary tree(Efficient) : ";
	spiral_efficient(root);
	std::cout << "\nDiameter of binary tree : ";
	std::cout << diameter(root);	
	std::cout << "\nDiameter of binary tree(Efficient) : ";
	diameter_efficient(root);
	std::cout << res;
	std::cout << "\nLowest common ancestor : ";
	std::cout << lca(root, 50, 70)->key;
	std::cout << "\nLowest common ancestor(Efficient) : ";
	std::cout << lca_e(root, 50, 70)->key;
	std::cout << "\nBurn a binary tree from a leaf node : ";
	int l = -1;
	std::cout << burnTime(root, 50, l);

	std::cout << "\n";
	Node* start = binary_to_dll(root);
	traverse_dll(start);

	return 0;
}
