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

		queue<int> temp;
		temp.push(prices[0]);
		int sum = 0;
		for(int i=1;i<prices.size();++i)
		{
			if (prices[i]>=temp.back())
			{
				temp.push(prices[i]);
			}
			else
			{
				if (temp.size()>1)
				{
					sum += temp.back() - temp.front();
				}
				temp = queue<int>();
				temp.push(prices[i]);
			}

		}
		if (temp.size() > 1)
		{
			sum += temp.back() - temp.front();
		}
		return sum;
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