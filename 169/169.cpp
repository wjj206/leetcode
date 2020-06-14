//#include <bits/stdc++.h>
#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
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
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		return nums[nums.size() / 2];
	}
};

int main() {

	Solution s;

	vector<int> input;
	
	system("pause");
	return 0;
}