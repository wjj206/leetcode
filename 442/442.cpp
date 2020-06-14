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
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		if (nums.empty()) return res;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			int index = (nums[i] - 1)%len;
			nums[index] += len;
		}
		for (int i = 0; i < len; i++)
		{

			if (nums[i] > 2 * len)
				res.push_back(i + 1);
		}
		return res;
	}
};
int main() {

	Solution s;

	vector<int> input = {4,3,2,7,8,2,3,1};
	vector<int> res = s.findDuplicates(input);

	for (auto x:res)
	{
		cout << x << endl;
	}

	system("pause");
	return 0;
}