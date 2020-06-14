//#include <bits/stdc++.h>
//#include <algorithm>
//#include <deque>
//#include <iostream>
//#include <limits>
//#include <list>
//#include <map>
//#include <unordered_map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <stack>
//#include <string>
//#include <vector>
//#include<unordered_set>
//#include "G:\备份\桌面文件\written_examination_code\my.cpp"
//
//using namespace std;
//
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
////-------------------------------------------
////https://leetcode-cn.com/problems/implement-strstr/solution/c5chong-jie-fa-ku-han-shu-bfkmpbmsunday-by-2227/
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		if (needle.empty())
//			return 0;
//
//		
//		return -1;
//	}
//};
//
//
//
//int main() {
//
//	Solution s;
//
//	string str1 = "hello";
//	string str2 = "ll";
//
//	cout << s.strStr(str1,str2)<<endl;
//	
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base(int data) :_ma(data)
//	{
//		cout << "Base()" << endl;
//	}
//	virtual ~Base()
//	{
//		cout << "~Base()" << endl;
//	}
//	virtual void Show(int i = 10)//虚函数
//	{
//		cout << "Base::Show(), i=" << i << endl;
//	}
//private:
//	int _ma;
//};
//
//class Derive : public Base
//{
//public:
//	Derive(int data1, int data2) :Base(data1), _mb(data2)
//	{
//		cout << "Derive()" << endl;
//	}
//	~Derive()
//	{
//		cout << "~Derive()" << endl;
//	};
//	virtual void Show(int i = 20)//虚函数
//	{
//		cout << "Derive::Show(), i=" << i << endl;
//	}
//private:
//	int _mb;
//};
//
//int main()
//{
//	Base *p = new Derive(10, 10);
//	p->Show();
//	delete p;
//
//
//	system("pause");
//	return 0;
//}
//
//template<typename T>
//T muplus(T A,T B)
//{
//	return A + B;
//}


#include <stdlib.h>
#include <stdio.h>
#include<malloc.h>

char* itoa(int n)
{
	char* retbuf = (char*)malloc(sizeof(char)*20);
	sprintf_s(retbuf, "%d", n);
	return retbuf;
}

int main(void) {
	char* a;
	a = itoa(65);

	printf("%s", &a);

	getchar();
	return 0;
}