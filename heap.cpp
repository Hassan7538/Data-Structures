#include<iostream>
using namespace std;

class minheap
{
	int* h;
	int currSize, maxSize;

	void bubble_up(int i) 
	{
		if (i > 1)
		{
			int parent = i / 2;
			if (h[i] < h[parent])
			{
				swap(h[i], h[parent]);
				bubble_up(parent);
			}
		}
	}

	void bubble_down(int i) 
	{
		int left = 2 * i;
		int right = 2 * i + 1;
		int smallest = i;

		if (left <= currSize && h[left] < h[smallest]) 
			smallest = left;

		if (right <= currSize && h[right] < h[smallest]) 
			smallest = right;

		if (smallest != i) 
		{
			swap(h[i], h[smallest]);
			bubble_down(smallest);
		}
	}

public:

	minheap(int n)
	{
		// create array of maxSize + 1 as the 0 index will be empty and
		//root will start from index 1
		n++;
		maxSize = n;
		h = new int[maxSize];
		currSize = 0;
	}

	~minheap()
	{
		delete[] h;  // deleting entire array
		h = nullptr;
	}

	bool isempty()
	{
		if (currSize == 0) // curr size = 0 that is no element is in array
			return true;
		return false;
	}

	void insertASingleValueInHeap(const int& x) 
	{
		if (currSize < (maxSize - 1)) 
		{
			// first increase the currSize then insert value so that we have
			// the record of the current number of values in heap
			h[++currSize] = x; 
			bubble_up(currSize);
			// we buble up it because we want to insert the value such that
			// it is inserted in a sorted manner from currSize / the index at
			// which val is going to be inserted. The traversal will occur from
			// currSize to the index 1 at which the heap is begining
		}
	}

	void buildMinHeap() 
	{
		for (int i = currSize / 2; i >= 1; i--) 
			bubble_down(i);
		// we buble down it because we want to check from last value that if
		// greater value came we can bring it at first to retain the min heap
	}

	int minval()
	{
		if (isempty())
		{
			cout << " Your Heap is empty " << endl << endl;
			return 0;
		}
		return h[1];
	}

	void heapSortDescending(int arr[], int n)
	{
		// Insert each element of the array into the heap
		for (int i = 0; i < n; i++)
		{
			insertASingleValueInHeap(arr[i]);
		}

		// Extract minimum elements from the heap and insert them at the end of the array
		for (int i = n - 1; i >= 0; i--)
		{
			arr[i] = minval();
			h[1] = h[currSize--]; // Replace the root with the last element
			bubble_down(1);       // Maintain the heap property
		}
	}

	bool isHeap(int arr[], int i, int n)
	{
		// If a leaf node
		if (i > n / 2 - 1)
			return true;

		int left = 2 * i + 1;
		int right = 2 * i + 2;

		// Check if the current node is less than or equal to its children
		if (left < n && arr[i] <= arr[left] && right < n && arr[i] <= arr[right] &&
			isHeap(arr, left, n) && isHeap(arr, right, n))
			return true;

		return false;
	}

	void check()
	{
		bool isValidHeap = isHeap(h, 0, currSize);
		cout << "Is the heap valid? " << (isValidHeap ? "Yes" : "No") << endl;
	}

	void PrintSmallerThan(int i, int x)
	{
		if (i > currSize)
			return;

		// If the current element is smaller than x, print it
		if (h[i] < x)
			cout << h[i] << " ";

		// Recursively check the left and right subtrees
		PrintSmallerThan(2 * i, x);
		PrintSmallerThan(2 * i + 1, x);
	}

	void PrintSmallerThan(int x)
	{
		PrintSmallerThan(1, x);
	}
};

void heapSort(int* arr, int SIZE)
{
	minheap mh(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		mh.insertASingleValueInHeap(arr[i]);
	}
	mh.buildMinHeap();
	mh.display();
}

void main()
{
	int s;
	cout << "Enter the size of the heap : ", cin >> s;
	minheap heap(s);

	for (int num, i = 0; i < s; i++)
	{
		cout << "Enter " << i + 1 << " element : ", cin >> num;
		heap.insertASingleValueInHeap(num);
	}

	if (heap.isempty())
		cout << "\nThe heap is empty." << endl << endl;

	else 
		cout << "\nThe heap is not empty." << endl << endl;

	cout << "Min value: ";
	int a = heap.minval();
	if (a)
		cout << a << endl << endl;
	else
		cout << "null --- heap is empty " << endl << endl;

	heap.buildMinHeap();
	cout << "Min value after buildMinHeap: " << heap.minval() << endl << endl;
}