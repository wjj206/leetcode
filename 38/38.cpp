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

//-------------------------------------------递归
class Solution {
public:
	string countAndSay(int n) {
		if (n==1)
		{
			return "1";
		}
		string temp = countAndSay(n-1);
		string res = "";
		int count = 1;
		for (int i=0;i<temp.size();++i)
		{
			if (temp[i]==temp[i+1])
			{
				++count;
			}
			else
			{
				res = res + to_string(count) + temp[i];
				count = 1;
			}
		}
		return res;

	}
};

//-------------------------------------------迭代
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
		{
			return "1";
		}
		string s = "1";

		for (int i=0;i<n-1;++i)
		{
			int count = 1;
			string temp = "";
			for (int j=0;j<s.size();++j)
			{
				
				if (j+1<s.size()  &&  s[j] == s[j + 1])
				{
					++count;
				}
				else
				{
					temp = temp + to_string(count) + s[j];
					count = 1;
				}
			}
			s = temp;
		}
		return s;
	}
};



int main() {

	Solution s;

	cout << s.countAndSay(5) << endl;

	system("pause");
	return 0;
}