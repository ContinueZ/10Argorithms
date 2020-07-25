#pragma once

#include<iostream>
#include<vector>
using namespace std;

/****************************1.冒泡排序（稳定O(n2)）***************************/
void BubbleSort(vector<int> &v)
{
	size_t size = v.size();
	bool flag = false;
	//两种写法都可
	for (int i = size - 1; i > 0; --i) {
		for (int j = 0; j < i ; ++j) {
			if (v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
				flag = true;
			}
		}
		if (!flag)break;
	}
	//for (int i = 0; i < size - 1; ++i) {
	//	for (int j = 0; j< size - i - 2; ++j) {
	//		if (v[j] > v[j + 1]) {
	//			swap(v[j], v[j + 1]);
	//			flag = true;
	//		}
	//	}
	//	if (!flag)break;
	//}
}

/****************************2.选择排序（不稳定（n2））***************************/
void SelectionSort(vector<int> &v)
{
	size_t size = v.size();
	
	for (int i = 0; i < size-1; ++i) {
		int min = v[i];
		int mIndex = i;
		for (int j = i+1; j < size; ++j) {
			if (min > v[j]) {
				min = v[j];
				mIndex = j;
			}
		}
		if (v[i] > min)swap(v[mIndex], v[i]);
	}
}

/****************************3.插入排序(稳定（n2）)***************************/
void InsertSort(vector<int> &v)
{
	size_t size = v.size();

	for (int i = 1; i < size; ++i) {
		int j = i - 1;
		int temp = v[i];
		while (j >= 0 && temp < v[j]) {
			v[j + 1] = v[j];
			--j;
		}
		v[j + 1] = temp;
	}
}

/****************************4.希尔排序（不稳定（nlong2n））***************************/
void Shellsort(vector<int> &v)
{
	size_t size = v.size();
	for (int gap = size / 2; gap >= 1; gap = gap / 2) {
		for (int i = gap; i < size; ++i) {
			int itemToInsert = v[i];
			int j = i - gap;

			while (j >= 0 && itemToInsert < v[j]) {
				v[j + gap] = v[j];
				j -= gap;

			}
			v[j + gap] = itemToInsert;
		}
	}
}

/****************************5.归并排序(稳定（nlogn）)***************************/
void merge(vector<int>& array, vector<int>& copyArray, int left, int right)
{
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k = 0;
	while (i <= mid || j <= right) {
		if (i > mid) {
			copyArray[k] = array[j];
			++j;
		}
		else if (j > right) {
			copyArray[k] = array[i];
			++i;
		}
		else if (array[i] < array[j]) {
			copyArray[k] = array[i];
			++i;
		}
		else {
			copyArray[k] = array[j];
			++j;
		}
		++k;
	}
	for (size_t i = left; i <= right; ++i) {
		array[i] = copyArray[i - left];
	}

}

void mergeSortHelp(vector<int>& array, vector<int>& copyArray, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSortHelp(array, copyArray, left, mid);
		mergeSortHelp(array, copyArray, mid + 1, right);
		merge(array, copyArray, left, right);
	}
}

void mergeSort(vector<int>& array)
{
	vector<int> copyArray(array);
	mergeSortHelp(array, copyArray, 0, array.size() - 1);
}

/****************************6.快速排序(不稳定（nlogn）N<=20时不如插入排序)***************************/
int medianPovit(vector<int>& array, int left, int mid, int right)
{
	if (array[left] > array[mid])
		swap(array[left], array[mid]);
	if (array[left] > array[right])
		swap(array[left], array[right]);
	if (array[mid] > array[right])
		swap(array[mid], array[right]);

	return array[mid];
}
int partition(vector<int>& array, int left, int right)
{
	int mid = (left + right) / 2;
	int povit = medianPovit(array, left, mid, right);
	
	array[mid] = array[right - 1];
	array[right - 1] = povit;
	int i = left + 1, j = right - 1;
	while (i < j) {
		if (array[i] < povit)
			++i;
		else if (array[j] >= povit)
			--j;
		else swap(array[i], array[j]);
	}

	//交换基准值和i位置元素
	swap(array[i], array[right - 1]);

	return i;
	
}


void quickSortHelp(vector<int>& array, int left, int right)
{
	if (left < right) {
		int pivotLoction = partition(array, left, right);
		quickSortHelp(array, left, pivotLoction - 1);
		quickSortHelp(array, pivotLoction + 1, right);
	}
}

void quickSort(vector<int>& array)
{
	quickSortHelp(array, 0, array.size() - 1);
}

/****************************7.堆排序(不稳定（nlogn）)***************************/
void adjust(vector<int>& arr, int n, int index) {

	int maxInd = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left<n&&arr[left]>arr[maxInd])maxInd = left;
	if (right<n&&arr[right]>arr[maxInd])maxInd = right;
	if (maxInd != index) {
		swap(arr[index], arr[maxInd]);
		adjust(arr, n, maxInd);//继续调整向下调整
	}
}
void HeapSort(vector<int>& arr) {
	
	int n = arr.size();
	int index = n / 2 - 1;  //第一个非叶子节点index

	//遍历每个非叶子节点,构建大顶堆
	for (int i = index; i >= 0; --i) {
		adjust(arr, n, i);
	}
	//排序
	for (int i = n - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		adjust(arr, i, 0);
	}
}

