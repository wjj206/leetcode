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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size()<3) { return res; }

		int i = 0;
		sort(nums.begin(), nums.end());
		set<vector<int>> rres;
		while (nums[i] <= 0 && i<nums.size()-2)
		{
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k)
			{
				if (nums[j] + nums[k] < -nums[i]) { ++j; }
				else if (nums[j] + nums[k] > -nums[i]) { --k; }
				else
				{
					vector<int> temp = { nums[i],nums[j],nums[k] };
					rres.insert(temp);
					++j;
					--k;
				}
			}
			++i;
		}
		for (auto r : rres)
		{
			res.push_back(r);
		}
		return res;
	}
};
	int main() {

		Solution s;

		vector<int> input = {0};
		vector<vector<int>> res = s.threeSum(input);

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}