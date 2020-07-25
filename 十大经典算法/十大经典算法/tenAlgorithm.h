#pragma once

#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int> &v)
{
	size_t size = v.size();
	bool flag = false;
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (v[i] > v[j]) {
				swap(v[i], v[j]);
				flag = true;
			}
		}
		if (!flag)break;
	}
}
