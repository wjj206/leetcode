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
//-----------------------------------方法一
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		auto ite = unique(nums.begin(),nums.end());
//		return ite - nums.begin();
//	}
//};

//-----------------------------------方法二,超时
//int removeDuplicates(vector<int>& nums) {
//	int ret = nums.size();
//	if (ret < 2)
//		return ret;
//	for (int i = 1; i < ret;) {
//		if (nums[i] == nums[i - 1]) {
//			for (int j = i; j < ret - 1; ++j) {
//				swap(nums[j], nums[j + 1]);
//			}
//			--ret;
//		}
//		else {
//			++i;
//		}
//	}
//	return ret;
//}

//-----------------------------------方法三
int removeDuplicates(vector<int>& nums) {
	int s = nums.size();
	int ret = s;
	if (ret < 2) return ret;

	int x = 0;//升序还是降序
	if (nums[0] <= nums[ret - 1]) x = nums[0] - 1;
	else x = nums[0] + 1;

	for (int i = 1, pre = 0; i < s; ++i) {
		if (nums[i] == nums[pre]) {
			--ret;
			nums[i] = x;
		}
		else {
			pre = i;
		}
	}

	for (int i = 1, xp = -1; i < s; ++i) {
		if (nums[i] != x && xp > 0) {
			swap(nums[i], nums[xp++]);
		}
		else if (nums[i] == x && nums[i] != nums[i - 1]) {
			xp = i;
		}
	}
	return ret;
}
//-----------------------------------------方法四，双指针
//int removeDuplicates(vector<int>& nums) {
//	int s = nums.size();
//	if (s < 2)
//		return s;
//	int lft = 0, rgt = 0;
//	while (rgt++ < s - 1) {
//		if (nums[rgt] != nums[lft]) {
//			nums[++lft] = nums[rgt];
//		}
//	}
//	return lft + 1;
//}


int main() {



	vector<int> input = {1,2,3,3,3};

	cout << removeDuplicates(input)<<endl;

	for (int i = 0; i < input.size(); i++)
	{
		cout << i << "th : " << input[i] << endl;
	}
	system("pause");
	return 0;
}
