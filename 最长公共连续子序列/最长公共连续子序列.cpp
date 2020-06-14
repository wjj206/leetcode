//https://blog.csdn.net/u010648580/article/details/78025923
//https://blog.csdn.net/lxt_lucia/article/details/81209962
//https://blog.csdn.net/hrn1216/article/details/51534607?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2


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

vector<vector<int>> maxlen(100, vector<int>(100));
vector<vector<int>> flag(100, vector<int>(100));
int longest = 0;
class  Solution
{
public:
	int lcs(string s1,string s2)//最长公共子序列个数
	{
		if (s1.empty() || s2.empty())
		{
			return NULL;
	    }

		for (int i=0;i<s1.size();++i)
		{
			for (int j=0;j<s2.size();++j)
			{
				if (i==0 ||j==0)
				{
					maxlen[i][j] = 0;
				}
			}
		}

		for (int i = 1; i <= s1.size(); ++i)
		{
			for (int j = 1; j <= s2.size(); ++j)
			{
				if (s1[i-1]==s2[j-1])
				{
					maxlen[i][j] = maxlen[i-1][j-1] + 1;
					flag[i][j] = 1;
				}
				else if(maxlen[i - 1][j] >= maxlen[i][j-1])
				{
					maxlen[i][j] = maxlen[i-1][j] ;
					flag[i][j] = 2;
				}
				else if (maxlen[i - 1][j] < maxlen[i][j - 1])
				{
					maxlen[i][j] = maxlen[i][j - 1];
					flag[i][j] = 3;
				}
			}
		}
		return maxlen[s1.size()][s2.size()];

	}

	vector<char> getlcs(string s1,string s2)//最长公共子序列输出
	{
		vector<char> res;
		int i = s1.size();
		int j = s2.size();

		while (i!=0 && j!=0)
		{
			if (flag[i][j]==1)
			{
				res.push_back(s1[i-1]);
				--i;
				--j;
			}
			else if (flag[i][j] == 2)
			{
				--i;
			}
			else if (flag[i][j] == 3)
			{
				--j;
			}
		}
		reverse(res.begin(),res.end());
		return res;
	}
	//-------------------------------------------------------------------------

	int conlcs(string s1, string s2)//最长公共连续子序列个数
	{
		if (s1.empty() || s2.empty())
		{
			return NULL;
		}

		for (int i = 0; i < s1.size(); ++i)
		{
			for (int j = 0; j < s2.size(); ++j)
			{
				if (i == 0 || j == 0)
				{
					maxlen[i][j] = 0;
				}
			}
		}

		for (int i = 1; i <= s1.size(); ++i)
		{
			for (int j = 1; j <= s2.size(); ++j)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
				}
				else 
				{
					maxlen[i][j] = 0;
				}

				if (maxlen[i][j]>longest)
				{
					longest = maxlen[i][j];
				}
			}
		}
		return longest;

	}

	string getconlcs(string s1, string s2)//最长公共连续子序列输出
	{
		string res;

		for (int i=1;i<=s1.size();++i)
		{
			for (int j=1;j<s2.size();++j)
			{
				if (maxlen[i][j]==longest)
				{
					res = s1.substr(i-longest,longest);
					return res;
				}
			}
		}
	}

};

int main() {

	Solution s;
	string s1 = "BDCABA";
	string s2 = "ABCBDAB";

   int reslcsnum = s.lcs(s1,s2);
   cout << "不连续公共个数:" << reslcsnum << endl;
   vector<char> res = s.getlcs(s1,s2);
	for (auto x:res)
	{
		cout << x;
	}
	cout << endl;

	int resconlcsnum = s.conlcs(s1,s2);
	cout << "连续公共个数:" << resconlcsnum << endl;
	cout << s.getconlcs(s1,s2)<<endl;

	system("pause");
	return 0;
}