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
	void digui(vector<vector<int>>& res,vector<int> has,int index,vector<int> temp)
	{
		if (index==has.size())
		{
			res.push_back(temp);
			return;
		}
		//vector<int> ori(has);
		for (int i=index;i<has.size();++i)
		{
			temp.push_back(has[i]);
			swap(has[index],has[i]);
			digui(res, has, index+1, temp);
			temp.pop_back();
			/*has.clear();
			has = ori;*/
			swap(has[i],has[index]);
		}
		return;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.empty())
		{
			return res;
		}

		vector<int> temp;
		digui(res,nums, 0, temp);
		return res;
	}
};

int main() {

	Solution s;

	vector<int> input = {1,2,3};
	vector<vector<int>> res;
	res = s.permute(input);
	for (auto x:res)
	{
		for (auto y:x)
		{
			cout << y << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}