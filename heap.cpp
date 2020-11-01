#include <cstddef>
#include <climits>
#include <iostream>
#include<queue>

class Minheap
{
private:
	int* arr;
	int capacity, size;

public:
	Minheap(int c)
	{
		arr = new int[c];
		size = 0;
		capacity = c;
	}

	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }
	int parent(int i) { return i - 1 / 2; }

	void swap(int& a, int& b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}

	void insert(int x)
	{
		if (size == capacity)
		{
			capacity = capacity + 10;
			int* y = new int[capacity];
			y = arr;
			delete(arr);
			int* arr = new int[capacity];
			arr = y;
			delete(y);
		}

		size++;
		arr[size - 1] = x;

		for (int i = size - 1; i != 0 && arr[parent(i)] > x;)
		{
			swap(arr[parent(i)], x);
			i = parent(i);
		}
	}

	void minHeapify(int i)
	{
		int smallest = i;
		int lt = left(i);
		int rt = right(i);

		if (lt < size && arr[lt] < arr[smallest])
			smallest = lt;
		if (rt < size && arr[rt] < arr[smallest])
			smallest = rt;

		if (smallest != i)
		{
			swap(arr[smallest], arr[i]);
			minHeapify(smallest);
		}
	}

	void maxHeapify(int arr[], int i, int n)
	{
		int lt = left(i);
		int rt = right(i);

		int largest = i;
		
		if (lt < size && arr[lt] > arr[largest])
			largest = lt;
		if (rt < size && arr[rt] > arr[largest])
			largest = rt;
		
		if (largest != i)
		{
			swap(arr[largest], arr[i]);
			maxHeapify(arr, size, largest);
		}
	}

	int extractMin()
	{
		if (size == 0)
			return INT_MIN;

		if (size == 1)
		{
			size--;
			return arr[0];
		}

		swap(arr[0], arr[size - 1]);
		size--;

		minHeapify(0);

		return arr[size];
	}

	int extractMax()
	{
		if (size == 0)
			return INT_MAX;

		if (size == 1)
		{
			int cur = arr[0];
			size--;
			return cur;
		}

		swap(arr[0], arr[size - 1]);
		size--;

		maxHeapify(arr, arr[size - 1], 0);

		return arr[size];
	}

	void decreaseKey(int i, int x)
	{
		arr[i] = x;

		while (i > 0 && arr[i] < arr[parent(i)])
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	int deleteElem(int i)
	{
		size--;
		decreaseKey(i, arr[size]);
	}

	int deleteElemII(int i)
	{
		decreaseKey(i, INT_MIN);
		extractMin();
	}

	void buildHeap(int arr[], int n)
	{
		for (int i = (n - 2) / 2; i >= 0; i--)
			minHeapify(i);
	}

	void buildHeapMax(int arr[], int n)
	{
		for(int i = (n - 2) / 2; i >= 0; i--)
			maxHeapify(arr, i, n);
	}

	void heapSort(int arr[], int n)
	{
		for (int i = n; i >= 0; i--)
		{
			buildHeap(arr, n);
			swap(arr[0], arr[i]);
			maxHeapify(arr, i, 0);
		}
	}

	void ksorted(int arr[], int k)
	{
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

		for (int i = 0; i < k; i++)
			pq.push(arr[i]);

		int index = 0;

		for (int i = k+1; i < k; i++)
		{
			arr[index++] = pq.top();
			pq.pop();
		}

		while (!pq.empty())
		{
			arr[index++] = pq.top();
			pq.pop();
		}
	}
};

// ---------------------------
// Functions outside of class
// ---------------------------


std::vector<int> purchaseMax(int arr[], int n, int sum)
{
	std::vector<int> a;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	for (int i = 0; i<n;i++)
		pq.push(arr[i]);

	while (sum > 0)
	{
		int i = pq.top();
		if (i < sum)
			a.push_back(i);
		pq.pop();
		sum -= i;
	}

	return a;
}

void klargest(int arr[], int n, int k)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq(arr, arr + n);


	for (int i = k; i < n; i++)
	{
		if (pq.top() < arr[i])
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}

	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}
}


void kclosest(int arr[], int n, int y, int k)
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
		pq.push({ std::abs(y - arr[i]), i });

	for (int i = 0; i < k; i++)
	{
		v.push_back(pq.top().second);
		pq.pop();
	}

	for (auto x : v)
		std::cout << arr[x] << " ";
}

struct Triplet {
	int val, apos, vpos;

	Triplet(int v, int ap, int vp)
	{
		val = v;
		apos = ap;
		vpos = vp;
	}
};

struct myCmp
{
	bool operator()(Triplet& t1, Triplet& t2)
	{
		return t1.val > t2.val;
	}
};

void mergeArr(std::vector<std::vector<int>>& arr)
{
	std::vector<int> res;
	std::priority_queue<Triplet, std::vector<Triplet>, myCmp> pq;

	for (int i = 0; i < arr.size(); i++)
	{
		Triplet t(arr[i][0], i, 0);
		pq.push(t);
	}

	while (!pq.empty())
	{
		Triplet cur = pq.top();
		res.push_back(cur.val);
		pq.pop();

		if (cur.vpos + 1 < arr[cur.apos].size())
		{
			Triplet t(arr[cur.apos][cur.vpos + 1], cur.apos, cur.vpos + 1);
			pq.push(t);
		}
	}
	for (auto x : res)
		std::cout << x << " ";
}

int main()
{
	Minheap *arr = new Minheap(10);

	arr->insert(10);
	arr->insert(20);
	arr->insert(30);
	arr->insert(40);
	arr->insert(50);
	arr->insert(60);
	arr->insert(70);

	std::cout << "The minimum element removed from heap : " << arr->extractMin();

	int x[] = { 3,7,19,32,1,63,28,11,5 };
	std::vector<int> bx = purchaseMax(x, sizeof(x) / sizeof(x[0]), 50);
	std::cout << "\nPurchase max items from a given sum : ";
	for (auto ax : bx)
		std::cout << ax << " ";

	std::cout << "\nFind k largest elements : \n";
	klargest(x, sizeof(x) / sizeof(x[0]), 3);

	std::cout << "\nFinding k closest elements : \n";
	kclosest(x, (sizeof(x) / sizeof(x[0])), 19, 3);

	std::cout << "\nMerging k sorted arrays : \n";
	std::vector < std:: vector<int>> a;
	std::vector<int> p = { 1,2,3,4,5 };
	std::vector<int> q = { 6,7,8,9,10 };
	std::vector<int> r = { 11,12,13,14,15 };

	a.push_back(p);
	a.push_back(q);
	a.push_back(r);
	
	mergeArr(a);

	return 0;
}
