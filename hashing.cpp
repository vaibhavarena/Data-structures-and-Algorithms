#include<iostream>
#include<list>
using namespace std;

// A very simple Hash table implementation
struct myHash
{
	int BUCKET;
	list<int>* table;

	myHash(int key = 100)
	{
		BUCKET = key;
		table = new list<int>[BUCKET];
	}

	int hash(int key)
	{
		return key % BUCKET;
	}

	void insert(int key)
	{
		int i = hash(key);
		table[i].push_back(key);
	}

	bool search(int key)
	{
		int i = hash(key);
		for (auto x : table[i])
			if (x == key)
				return true;
		return false;
	}

	int remove(int key)
	{
		int i = hash(key);
		table[i].remove(key);
		return key;
	}
};


// Implementation of Open Addressing 
struct myHashOpen
{
	int* BUCKET;
	int cap, size;

	myHashOpen(int c = 100)
	{
		cap = c;
		size = 0;
		BUCKET = new int[cap];

		for (int i = 0; i < cap; i++)
		{
			BUCKET[i] = -1;
		}
	}

	int hash(int key)
	{
		return key % cap;
	}


	bool search(int key)
	{
		int i = hash(key);
		int h = i;
		while (BUCKET[i] != -1)
		{
			if (BUCKET[i] == key)
				return true;
			i = (i + 1) % cap;
			if (i == h)
				return false;
		}
	}

	bool insert(int key)
	{
		if (size == cap)
			return false;

		int i = hash(key);
		while (BUCKET[i] != -1 && BUCKET[i] != -2 && BUCKET[i] != key)
			i = (i + 1) % cap;
		if (BUCKET[i] == key)
			return false;

		else {
			size = size + 1;
			BUCKET[i] = key;
			return true;
		}
	}

	bool erase(int key)
	{
		int i = hash(key);
		int h = i;
		while (BUCKET[i] != -1)
		{
			if (BUCKET[i] == key)
			{
				BUCKET[i] = -2;
				size -= 1;
				return true;
			}
			i = (i + 1) % h;
			if (i == h)
				return false;
		}
		return false;
	}
};


int main()
{
	myHash a;

	a.insert(21);
	a.insert(31);
	a.insert(41);

	cout << a.search(31) << endl;
	cout << a.remove(21) << endl;
	cout << a.search(21);

	return 0;
}































//#include<iostream>
//using namespace std;
//
//struct link
//{
//	int data;
//	link* next;
//
//	link(int x)
//	{
//		data = x;
//		next = NULL;
//	}
//};
//
//struct Node
//{
//	int data;
//	Node* next;
//	bool visited;
//
//	Node(int x)
//	{
//		data = x;
//		next = NULL;
//		visited = false;
//	}
//};
//
//void traverse(link* head)
//{
//	link* cur = head;
//	while (cur != NULL)
//	{
//		cout << cur->data << " ";
//		cur = cur->next;
//	}
//}
//
//link* reverse(link* head)
//{
//	link* cur = head;
//	link* prev = NULL;
//	while (cur != NULL)
//	{
//		link* next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	return prev;
//}
//
//link* rev_iter1(link* head)
//{
//	if(head == NULL || head->next == NULL)
//		return head;
//	link* rest_head = rev_iter1(head->next);
//	link* rest_tail = head->next;
//	rest_tail->next = head;
//	head->next = NULL;
//	return rest_head;
//}
//
//link* rev_iter2(link* cur, link* prev)
//{
//	if (cur == NULL)
//		return prev;
//	link* next = cur->next;
//	cur->next = prev;
//	return rev_iter2(next, cur);
//}
//
//bool detect_loop(Node* head)
//{
//	Node* cur = head;
//	while (cur->next != NULL)
//	{
//		if (cur->visited == true)
//			return false;
//		cur->visited = true;
//		cur = cur->next;
//	}
//	return true;
//}
//
//bool loop_is_there(Node* head)
//{
//	Node* cur = head;
//	Node* new_head = cur;
//	int count = 0;
//	while (cur->next != NULL)
//	{
//		while (new_head != cur)
//		{
//			if (cur->next = new_head)
//				count = 1;
//			new_head = new_head->next;
//		}
//		if (count == 1)
//			return true;
//		cur = cur->next;
//	}
//}
//
//bool dummy_detect(Node* head)
//{
//	Node* x = new Node(-1);
//	Node* cur = head;
//	while (cur->next != NULL)
//	{
//		Node* nex = cur->next;
//		if (cur->next == x)
//			return true;
//
//		cur->next = x;
//		cur = nex;
//	}
//	return false;
//}
//
//int main()
//{
//	link l(19);
//	link* head = &l;
//	link m(20);
//	link n(21);
//
//	l.next = &m;
//	m.next = &n;
//	//head = rev_iter2(head, NULL);
//	//head = rev_iter1(head);
//	//traverse(head);
//	//cout << "\n";
//
//	Node a(1);
//	Node b(2);
//	Node c(4);
//	Node d(4);
//	
//	a.next = &b;
//	b.next = &c;
//	c.next = &d;
//	d.next = &a;
//	
//	if (dummy_detect(&a))
//	{
//		cout << "Loop has been detected";
//	}
//	else
//		cout << "No loop";
//
//	return 0;
//}
