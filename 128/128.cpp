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

//----------------------------
//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums) {
//		if (nums.empty())
//		{
//			return 0;
//		}
//
//		unordered_set<int> temp;
//		for (int num:nums)
//		{
//			temp.insert(num);
//		}
//
//		int res = 1;
//		for (int num:nums)
//		{
//			if (num!=INT_MIN && temp.find(num-1)==temp.end())
//			{
//				int tt = num;
//				int cl = 1;
//
//				while(tt != INT_MAX && temp.find(tt + 1) != temp.end())
//		        {
//					tt++;
//					cl++;
//				}
//
//				res = max(cl,res);
//			}
//		}
//
//		return res;
//	}
//};

//-------------------
//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums) {
//		unordered_set<int> st;
//		for (int n : nums) st.insert(n);
//		int ans = 0;
//		for (int i : st) {
//			// 假如一个数在哈希表中存在比他小的，那么它不是可以作为开头的数字
//			if (i != INT_MIN && st.count(i - 1)) {
//				continue;
//			}
//			int cnt = 1;
//			while (i != INT_MAX && st.count(i + 1)) {
//				cnt++;
//				i++;
//			}
//			ans = max(ans, cnt);
//		}
//		return ans;
//	}
//};
//---------------------------------
class Solution {
public:
	unordered_map<int, int> a, b;
	int find(int x) {
		return a.count(x) ? a[x] = find(a[x]) : x;
	}
	int longestConsecutive(vector<int>& nums) {
		for (auto i : nums)
			a[i] = i + 1;
		int ans = 0;
		for (auto i : nums) {
			int y = find(i + 1);
			ans = max(ans, y - i);
		}
		return ans;
	}
};


int main() {

	Solution s;

	vector<int> input = { 100, 4, 200, 1, 3, 2 };
	cout << s.longestConsecutive(input) << endl;

	system("pause");
	return 0;
}