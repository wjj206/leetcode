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
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
		{
			return NULL;
		}
		int len = prices.size();
		vector<int> inversemax(len,0);

		inversemax[len - 1] = prices[len-1];

		for (int i=len-2;i>0;--i)
		{
			inversemax[i] = prices[i] > inversemax[i+1] ?prices[i]: inversemax[i+1];
		}

		int max = INT_MIN;
		for(int i=0;i<len-1;++i)
		{
			max = inversemax[i + 1] - prices[i] > max ? inversemax[i + 1] - prices[i] : max;
		}

		return max < 0 ? 0:max;
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;
	while ((cin.peek() != EOF) && (cin.peek() != '\n'))
	{
		cin >> temp;
		input.push_back(temp);
	}
	for (int i = 0; i < input.size(); i++)
	{
		cout << i << "th : " << input[i] << endl;
	}

	system("pause");
	return 0;
}