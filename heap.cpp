#include <cstddef>

class Minheap
{
private:
	int *arr;
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

	int insert(int x)
	{
		if (size == capacity)
		{
			capacity = capacity + 10;
			int* y = new int[capacity];
			y = arr;
			delete(arr);
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

		if (lt < size && arr[lt] < arr[i])
			smallest = lt;
		if (rt < size && arr[rt] < arr[i])
			smallest = rt;

		if (smallest != i)
		{
			swap(arr[smallest], arr[i]);
			minHeapify(smallest);
		}
	}
};

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


	return 0;
}