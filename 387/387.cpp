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
	int firstUniqChar(string s) {

		if (s.empty())
		{
			return -1;
		}

		unordered_map<char,int> temp;

		for (auto x:s)
		{
			auto it = temp.find(x);
			if (it !=temp.end())
			{
				++(it->second);
			}
			else
			{
				temp.insert(pair<char, int>(x,1));
			}
		}

		for (int i=0;i<s.size();++i )
		{
			if (temp[s[i]]==1)
			{
				return  i;
			}
		}

		return -1;
	}
};

int main() {

	Solution s;

	string test = "leetcode";

	cout << s.firstUniqChar(test);

	system("pause");
	return 0;
}