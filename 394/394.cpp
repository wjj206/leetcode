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
//�Լ�д��
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
//					seg = temp.top() + seg;//��¼[]�ڵ���ĸ��
//					temp.pop();
//				}
//				temp.pop();//����[
//				int mi = 0;
//				int num = 0;//��¼[ǰ������
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
//						temp.push(seg[m]);//�����ܺ����ĸ�Ż�ջ��
//					}
//				}
//			}
//
//		}
//		while (!temp.empty())
//		{
//			res += temp.top();//��ջ��Ԫ�ص���
//			temp.pop();
//		}
//		reverse(res.begin(), res.end());//��תһ��
//		return res;
//	}
//};

//���˵�
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
//			else if (s[i] == '[') //����[��ǰ������ѹ��numsջ�ڣ� ��ĸ�ַ���ѹ��strsջ��
//			{
//				nums.push(num);
//				num = 0;
//				strs.push(res);
//				res = "";
//			}
//			else //������]��ʱ��������֮����ġ�[��֮����ַ���ʹ�÷�����
//			{
//				int times = nums.top();
//				nums.pop();
//				for (int j = 0; j < times; ++j)
//					strs.top() += res;
//				res = strs.top(); //֮����������ĸ���ͻ�ֱ�Ӽӵ�res֮����Ϊ������ͬһ��������
//								  //���������ţ�res�ᱻѹ��strsջ����Ϊ��һ�������
//				strs.pop();
//			}
//		}
//		return res;
//	}
//};


//���˵ĵݹ�
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