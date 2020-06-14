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
	bool is_left(char x)
	{
		vector<char> left = { '(','[','{' };
		for (auto y:left)
		{
			if (y==x)
			{
				return true;
			}
		}
		return false;
	}

	bool is_right(char x)
	{
		vector<char> right = { ')',']','}' };
		for (auto y : right)
		{
			if (y == x)
			{
				return true;
			}
		}
		return false;
	}

	bool isValid(string s) {
		if (s.empty())
		{
			return true;
		}
		vector<char> left = {'(','[','{'};
		vector<char> right = {')',']','}'};

		unordered_map<char, char> guanxi = { {'(',')'},{'[',']'},{'{','}'} };
		stack<char> temp;

		if (!is_left(s[0]))
		{
			return false;
		}

		for (auto x:s)
		{
			if (is_left(x))
			{
				temp.push(x);
			}
			if (temp.empty())
			{
				return false;
			}
			if( is_right(x))
			{
				if (x == guanxi[temp.top()])
				{
					temp.pop();
				}
				else
				{
					return false;
				}
			}
		}

		return temp.empty();
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;
	

	system("pause");
	return 0;
}