#include<iostream>
using namespace std;

// Transpose of a matrix ( Naive solution )
void transpose(int* arr[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
}

// Transpose of a matrix ( Efficient Solution )
void trans(int* arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			swap(arr[i][j], arr[j][i]);
		}
	}
}

// Spiral traversal of a matrix
void spiral(int* arr[], int r, int c)
{
	int top = 0, bottom = r - 1, left = 0, right = c - 1;

	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++)
		{
			cout << arr[top][i] << " ";
		}

		top++;

		for (int i = top; i <= bottom; i++)
		{
			cout << arr[i][right] << " ";
		}

		right--;

		if (top <= bottom)
			for (int i = right; i >= left; i--)
			{
				cout << arr[bottom][i] << " ";
			}

		bottom--;

		if (left <= right)
			for (int i = bottom; i >= top; i--)
			{
				cout << arr[i][left] << " ";
			}

		left++;

	}
}
// Print the array
void printarr(int* arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

// Rotate an array anti-clockwise by 90
void ninety(int* arr[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
}

// Swap 2 integers
void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}


// Column reverse for rotaion of array efficient solution
void columnreverse(int* arr[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		int low = 0, high = n - 1;
		while (low < high)
		{
			swap(arr[low][i], arr[high][i]);
			low++;
			high--;
		}
	}
}


// Search element in row-wise and column-wise sorted array
void search(int* arr[], int elem, int r, int c)
{
	int i = 0, j = c - 1;
	while (i < r && j >= 0)
	{
		if (elem == arr[i][j])
		{
			cout << "Element found at : " << i << " " << j;
			return;
		}
		else if (elem > arr[i][j])
			i++;
		else
			j--;
	}
	cout << "Element not found";
}

int main()
{
	// Create matrix with pointer of arrays
	int* arr[4];
	for (int i = 0; i < 4; i++)
		arr[i] = new int[4];

	// Initialize values with a count
	int count = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			arr[i][j] = ++count;

	// Initialize array for search
	int* arr1[4];
	for (int i = 0; i < 4; i++)
		arr1[i] = new int[4];

	int counter = 4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr1[i][j] = counter * (j + 1);
		}
		counter += 5;
	}

	cout << "experiment " << arr[0][2];
	// Print original array for reference
	cout << " Array 1: " << endl;
	printarr(arr, size(arr));
	cout << "\n\n";

	// Print the search array 
	cout << "Array 2: " << endl;
	printarr(arr1, size(arr));
	cout << "\n\n";


	// Boundary of a matrix
	for (int i = 0; i < 4; i++)
		cout << arr[0][i] << " ";
	for (int i = 1; i < 4; i++)
		cout << arr[i][3] << " ";
	for (int i = 2; i >= 0; i--)
		cout << arr[3][i] << " ";
	for (int i = 2; i > 0; i--)
		cout << arr[i][0] << " ";

	cout << "\n\n";

	// Array rotation Anti-clockwise
	//trans(arr, size(arr));
	//columnreverse(arr, size(arr));
	//printarr(arr, size(arr));

	// Spiral printing of a matrix
	//spiral(arr, size(arr), size(arr));

	search(arr1, 76, size(arr), size(arr));
	return 0;
}
