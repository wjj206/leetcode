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
//------------部分通过
//class Solution {
//public:
//	int rob(vector<int>& nums) {
//
//		if (nums.empty())
//		{
//			return 0;
//		}
//		if (nums.size() == 1)
//		{
//			return nums[0];
//		}
//
//		int sum0 = nums[0];
//		for (int i = 2; i < nums.size() ; i = i + 2)
//		{
//			int m = 0;
//			m = nums[i];
//			if (i+1<nums.size())
//			{
//				if (nums[i+1]>nums[i])
//				{
//					m = nums[i + 1];
//					i++;
//				}
//			}
//			sum0 += m;
//		}
//		int sum1 = nums[1];
//		for (int i = 3; i < nums.size() ; i = i + 2)
//		{
//			int m = 0;
//			m = nums[i];
//			if (i + 1 < nums.size())
//			{
//				if (nums[i + 1] > nums[i])
//				{
//					m = nums[i + 1];
//					i++;
//				}
//			}
//			sum1 += m;
//		}
//
//		int sumji = 0;
//		int sumou = 0;
//		for (int i = 0; i < nums.size(); i = i + 2)
//		{
//			sumji += nums[i];
//		}
//		for (int j = 1;j < nums.size();j = j + 2)
//		{
//
//			sumou += nums[j];
//		}
//
//		return max(max(sum0, sum1),max(sumji,sumou));
//	}
//};


//-----------------动规
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		vector<int> res(nums.size()+1,0);
		res[0] = 0;
		res[1] = nums[0];

		for (int i=2;i<=nums.size();++i)
		{
			res[i] = max(res[i-1],res[i-2]+nums[i-1]);
		}

		return res.back();
	}
};
//-----------------------别人的解法
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int odd = 0;
		int even = 0;
		for (int i=0;i<nums.size();++i)
		{
			if (i%2==0)
			{
				even += nums[i];
				even = max(even,odd);
			}
			else
			{
				odd += nums[i];
				odd = max(even,odd);
			}
		}

		return max(odd,even);
	}
};



int main() {

	Solution s;
	vector<int> test = { 2,4,8,9,9,3 };
	cout << s.rob(test) << endl;

	system("pause");
	return 0;
}