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
	int check(const vector<int>& arr, int x) {
		int ret = 0;
		for (const int& num : arr) {
			ret += (num >= x ? x : num);
		}
		return ret;
	}

	int findBestValue(vector<int>& arr, int target) {
		sort(arr.begin(), arr.end());
		int n = arr.size();
		vector<int> prefix(n + 1);
		for (int i = 1; i <= n; ++i) {
			prefix[i] = prefix[i - 1] + arr[i - 1];
		}

		int l = 0, r = *max_element(arr.begin(), arr.end()), ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			auto iter = lower_bound(arr.begin(), arr.end(), mid);
			int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * mid;
			if (cur <= target) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		int choose_small = check(arr, ans);
		int choose_big = check(arr, ans + 1);
		return abs(choose_small - target) <= abs(choose_big - target) ? ans : ans + 1;
	}
};


int main() {

	Solution s;

	vector<int> input = { 2,3,5 };
	int i = 11;
	cout << s.findBestValue(input,i) << endl;
	

	system("pause");
	return 0;
}