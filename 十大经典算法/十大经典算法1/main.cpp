
#include "tenAlgorithm.h"

//test notes
int main()
{
	vector<int> v{ 1, 3, 10, 5, 2, 15, 9 };
	//BubbleSort(v);
	//SelectionSort(v);
	//InsertSort(v);
	//Shellsort(v);
	//mergeSort(v);
	//quickSort(v);
	HeapSort(v);
	for (int i : v)
		cout << i << endl;

	return 0;
}