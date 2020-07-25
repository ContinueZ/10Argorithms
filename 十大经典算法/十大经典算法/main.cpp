#include "tenAlgorithm.h"

int main()
{
	vector<int> v{ 1, 3, 7, 5, 2, 8, 9 };
	BubbleSort(v);
	for (int i : v)
		cout << i << endl;


	return 0;
}