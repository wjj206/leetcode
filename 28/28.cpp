#include <bits/stdc++.h>
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

////--------------------------------自写
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//
//		if (needle.empty())
//		{
//			return 0;
//		}
//		if (haystack.empty())
//		{
//			return -1;
//		}
//
//		int flag = -1;
//		if (haystack.size()>=needle.size())
//		{
//		for (int i = 0; i < (haystack.size() - needle.size() + 1); ++i)
//		{
//			flag = i;
//			for (int j = 0, k = i; j < needle.size(); ++j, ++k)
//			{
//				if (haystack[k] != needle[j])
//				{
//					flag = -1;
//					break;
//				}
//			}
//			if (flag != -1)
//			{
//				break;
//			}
//		}
//	    }
//		return flag;
//	}
//};
//
////----------------------------------------------库函数
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		if (needle.empty())
//			return 0;
//		int pos = haystack.find(needle);
//		return pos;
//	}
//};
////-----------------------------------------------bf.暴力算法
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		if (needle.empty())
//			return 0;
//
//		int i = 0, j = 0;
//		while (haystack[i] != '\0'&&needle[j] != '\0')
//		{
//			if (haystack[i] == needle[j])
//			{
//				i++;
//				j++;
//			}
//			else
//			{
//				i = i - j + 1;
//				j = 0;
//			}
//		}
//		if (needle[j] == '\0')
//			return i - j;
//
//		return -1;
//	}
//};
//
////-------------------------------------------sunday+kmp+bm
////https://leetcode-cn.com/problems/implement-strstr/solution/c5chong-jie-fa-ku-han-shu-bfkmpbmsunday-by-2227/
//https://blog.csdn.net/v_JULY_v/article/details/7041827?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;

		int i = 0, j = 0;
		int lenh = haystack.size();
		int lenn = needle.size();
		int help = lenn;

		while (i<lenh)
		{
			if (haystack[i]!=needle[j])
			{
				for (j=lenn-1;j>=0;--j)
				{
					if (haystack[help]==needle[j])
					{
						break;
					}
				}
				i = help - j;
				j = 0;
				help = i + lenn;
				if (help>lenh)
				{
					return -1;
				}
			}
			else
			{
				if (j==lenn-1)
				{
					return i - j;
				}
				i++;
				j++;
			}

		}
		return -1;
	}
};


int main()
{
	Solution s;
	string s1 = "mississippi";
	string s2 = "issi";
	cout << s.strStr(s1,s2)<<endl;

	system("pause");
	return 0;
}