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
	int romanToInt(string s) {
		if (s.empty())
		{
			return NULL;
		}
		unordered_map<string, int> help = { {"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000} ,
		{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900} };
		int res = 0;
		for (int i=0;i<s.size();++i)
		{
			int flag = 0;
			if ((s[i] == 'I') && (i+1<s.size()))
			{
				if (s[i+1]=='V' || s[i + 1] == 'X')
				{
					
					res += help[s.substr(i,2)];
					++i;
					flag = 1;
					
				}
			}
			 if ((s[i] == 'X' ) && (i + 1 < s.size()))
			{
				if (s[i + 1] == 'L' || s[i + 1] == 'C')
				{
					res += help[s.substr(i, 2)];
					++i;
					flag = 1;
				}
			}
		 if ((s[i] == 'C') && (i + 1 < s.size()))
			{
				if (s[i + 1] == 'D' || s[i + 1] == 'M')
				{
					res += help[s.substr(i, 2)];
					++i;
					flag = 1;
				}
			}
			if(flag == 0)
			{
				res += help[s.substr(i, 1)];
			}
		
		}
		return res;

	}
};

int main() {

	Solution s;

	string test = "MCMXCIV";
	cout << s.romanToInt(test);

	system("pause");
	return 0;
}