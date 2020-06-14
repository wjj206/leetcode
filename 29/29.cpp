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
28
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty())
		{
			return res;
		}

		int top = 0;
		int right = matrix[0].size() - 1;
		int bottom = matrix.size() - 1;
		int left = 0;
		while (true)
		{
			for (int i = left; i <= right; i++)
			{
				res.push_back(matrix[top][i]);
			}
			if (++top > bottom) { break; }

			for (int i = top; i <= bottom; i++)
			{
				res.push_back(matrix[i][right]);
			}
			if (--right < left) { break; }

			for (int i = right; i >= left; i--)
			{
				res.push_back(matrix[bottom][i]);
			}
			if (--bottom < top) { break; }

			for (int i = bottom; i >= top; i--)
			{
				res.push_back(matrix[i][left]);
			}
			if (++left > right) { break; }

		}

		return res;
	}
};

int main() {

	Solution s;

	vector<vector<int>> input = { {1,2,3},{4,5,6},{7,8,9} };
	vector<int> res;
	res = s.spiralOrder(input);
	
	for (int i = 0; i < res.size(); i++)
	{
		cout << i << "th : " << res[i] << endl;
	}

	system("pause");
	return 0;
}