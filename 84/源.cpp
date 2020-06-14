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

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty())
		{
			return 0;
		}

		int res = 0;
		vector<int> temp;
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		for (int i = 0; i < heights.size(); ++i)
		{
			while (!temp.empty() && heights[temp.back()] > heights[i])
			{
				int mem = temp.back();
				temp.pop_back();
				int left = temp.back() + 1;
				int right = i - 1;
				res = max(res, (right - left + 1)*heights[mem]);
			}
			temp.push_back(i);
		}
		return res;
	}
};

int main() {

	Solution s;

	vector<int> input = {2,1,5,6,2,3};
	cout << s.largestRectangleArea(input) << endl;

	system("pause");
	return 0;
}