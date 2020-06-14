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
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 0);
		res[0] = 1;

		for (int i = 1; i < nums.size(); ++i)
		{
			res[i] = res[i - 1] * nums[i - 1];
		}

		int temp = 1;
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			temp *= nums[i + 1];
			res[i] = res[i] * temp;
			
		}

		return res;
	}
};

int main() {

	Solution s;

	vector<int> input = {1,2,3,4};
	vector<int> res;
	res = s.productExceptSelf(input);
	for (int i = 0; i < res.size(); i++)
	{
		cout << i << "th : " << res[i] << endl;
	}

	system("pause");
	return 0;
}