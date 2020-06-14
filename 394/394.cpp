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

using namespace std;
//自己写的
//class Solution {
//public:
//	string decodeString(string s) {
//		if (s.empty())
//		{
//			return "";
//		}
//
//		string res = "";
//		stack<char> temp;
//
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if (s[i] != ']')
//			{
//				temp.push(s[i]);
//			}
//			else
//			{
//				string seg = "";
//				while (temp.top() != '[')
//				{
//					seg = temp.top() + seg;//记录[]内的字母段
//					temp.pop();
//				}
//				temp.pop();//弹出[
//				int mi = 0;
//				int num = 0;//记录[前的数字
//				while (!temp.empty() && temp.top()>='0' && temp.top()<='9')
//				{
//					num += (temp.top() - '0')*pow(10, mi++);
//					temp.pop();
//				}
//
//				for (; num > 0; --num)
//				{
//					for (int m = 0; m < seg.size(); ++m)
//					{
//						temp.push(seg[m]);//将解密后的字母放回栈中
//					}
//				}
//			}
//
//		}
//		while (!temp.empty())
//		{
//			res += temp.top();//将栈内元素弹出
//			temp.pop();
//		}
//		reverse(res.begin(), res.end());//反转一下
//		return res;
//	}
//};

//别人的
//class Solution {
//public:
//	string decodeString(string s) {
//		string res = "";
//		stack <int> nums;
//		stack <string> strs;
//		int num = 0;
//		int len = s.size();
//		for (int i = 0; i < len; ++i)
//		{
//			if (s[i] >= '0' && s[i] <= '9')
//			{
//				num = num * 10 + s[i] - '0';
//			}
//			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
//			{
//				res = res + s[i];
//			}
//			else if (s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
//			{
//				nums.push(num);
//				num = 0;
//				strs.push(res);
//				res = "";
//			}
//			else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
//			{
//				int times = nums.top();
//				nums.pop();
//				for (int j = 0; j < times; ++j)
//					strs.top() += res;
//				res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
//								  //若是左括号，res会被压入strs栈，作为上一层的运算
//				strs.pop();
//			}
//		}
//		return res;
//	}
//};


//别人的递归
class Solution {
public:
	string recursive(string s,int &index)
	{
		if (index>=s.size() || s[index]==']')
		{
			return "";
		}

		int num=0;
		string res = "";
		while (index<s.size())
		{
			if (isdigit(s[index]))
			{
				num = num * 10 + s[index] - '0';
			}
			else if (s[index]=='[')
			{
				string temp;
				temp = recursive(s,++index);
				for (; num > 0; --num) res += temp;
				num = 0;
			}
			else if (s[index] == ']')
			{
				break;
			}
			else
			{
				res += s[index];
			}
			index++;
		}

		return res;

	}


	string decodeString(string s) {
		string res = "";
		if (s.empty())
		{
			return res;
		}
		int index = 0;
		res = recursive(s,index);
		return res;
	}
};


int main() {

	Solution s;

	string test= "d3[b2[a]]2[bc]e";
	cout << s.decodeString(test);


	system("pause");
	return 0;
}