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
#include "G:\备份\桌面文件\written_examination_code\my.cpp"

using namespace std;


//----------------------------------------------暴力
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//
//		int max=nums[0];
//		for (int i=0;i<nums.size();++i)
//		{
//			int sum = 0;
//			for (int j=i;j<nums.size();++j)
//			{
//				sum += nums[j];
//				if (sum>max)
//				{
//					max = sum;
//				}
//			}
//		}
//		return max;
//	}
//};

//-------------------------------------动态规划
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//
//		vector<int> temp;
//		temp.push_back(nums[0]);
//		int res = nums[0];
//		for (int i=1;i<nums.size();++i)
//		{
//			temp.push_back( max(temp[i-1]+nums[i],nums[i]));
//			res = max(res,temp[i]);
//		}
//
//		return res;
//	}
//};

//-----------------------------------------贪心法
class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int sum = 0;
		int res = nums[0];

		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			res = max(res,sum);
			if (sum<0)
			{
				sum = 0;
			}
		}

		return res;
	}
};




int main() {

	Solution s;

	vector<int> input = { -2,1,-3,4,-1,2,1,-5,4};
	
	cout << s.maxSubArray(input)<< endl;

	system("pause");
	return 0;
}