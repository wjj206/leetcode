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

//--------------------------------------bfs
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty())
		{
			return res;
		}

		unordered_map<char, string> sta = { {'2',"abc"},{'3',"def"},
		{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
		{'8',"tuv"},{'9',"wxyz"} };
		queue<string> tepstr;
		string first = sta[digits[0]];

		for (auto x:first)
		{
			string help;
			help.push_back(x);
			tepstr.push(help);
		}

		for (int i=1;i<digits.size();++i)
		{
			first = sta[digits[i]];
			int size = tepstr.size();
			for (int i=0;i<size;++i)
			{
				for (auto x : first)
				{
					tepstr.push(tepstr.front() + x);
				}
				tepstr.pop();
			}
		}
		while (!tepstr.empty())
		{
			res.push_back(tepstr.front());
			tepstr.pop();
		}
		return res;
	}
};


//----------------------------dfs
class Solution {
public:
	void digui(vector<string>&res, string &digits, int index, unordered_map<char, string>& sta,string str)
	{
		if (index==digits.size())
		{
			res.push_back(str);
			return;
		}
		string temp = sta[digits[index]];

		for (auto x:temp)
		{
			digui(res, digits, index + 1, sta, str + x);
		}

		return;
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty())
		{
			return res;
		}

		unordered_map<char, string> sta = { {'2',"abc"},{'3',"def"},
		{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
		{'8',"tuv"},{'9',"wxyz"} };
		
		digui(res,digits,0,sta,"");

		return res;
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;
	

	system("pause");
	return 0;
}