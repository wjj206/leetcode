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

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (nums2.empty())
		{
			return;
		}
		if (nums1.empty())
		{
			nums1 = nums2;
			return;
		}
		int j = 0;
		int len1 = nums1.size();

		nums1.erase( nums1.begin()+m, nums1.begin() + len1);
		
		for (int i=0;i<n;++i)
		{
			while (j<m && nums1[j]<nums2[i])
			{
				++j;
			}
			if (j>=m)
			{
				nums1.insert(nums1.begin()+j,nums2.begin()+i,nums2.begin()+n);
				return;
			}
			nums1.insert(nums1.begin()+j,nums2[i]);
			++m;
		}
		return;
	}
};

int main() {

	Solution s;


	system("pause");
	return 0;
}