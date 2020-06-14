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
	vector<int> dailyTemperatures(vector<int>& T) {
		if (T.size() <= 1)
		{
			return T;
		}
		
		stack<int> temp;
		int len = T.size();
		vector<int> res(len, 0);
		for (int i=0;i<len;++i)
		{
			while (!temp.empty() && T[temp.top()] < T[i])
			{
				res[temp.top()] = i-temp.top();
				temp.pop();
			}
			temp.push(i);
	
		}
		return res;
	}
};

int main() {

	Solution s;

	vector<int> input = { 73, 74, 75, 71, 69, 72, 76, 73 };

	vector<int> res = s.dailyTemperatures(input);

	for (int i = 0; i < res.size(); i++)
	{
		cout << i << "th : " << res[i] << endl;
	}

	system("pause");
	return 0;
}