//#include <bits/stdc++.h>
#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<unordered_set>
#include "G:\����\�����ļ�\written_examination_code\my.cpp"

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> temp;
		for (auto x:nums)
		{
			temp.insert(x);
		}

		return temp.size() != nums.size();
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;
	while ((cin.peek() != EOF) && (cin.peek() != '\n'))
	{
		cin >> temp;
		input.push_back(temp);
	}
	for (int i = 0; i < input.size(); i++)
	{
		cout << i << "th : " << input[i] << endl;
	}

	system("pause");
	return 0;
}