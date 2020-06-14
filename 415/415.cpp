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

class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.empty())
		{
			return num2;
		}
		if (num2.empty())
		{
			return num1;
		}

		int len1 = num1.size();
		int len2 = num2.size();

		int len = len1 > len2 ? len1 : len2;
		string res="";
		int temp = 0;
		int sum = 0;
		for (int i=len1-1,j=len2-1;i>=0 || j>=0;--i,--j)
		{
			if (i>=0 && j>=0)
			{
				 sum = temp + num1[i]-'0' + num2[j]-'0';
			}
			else if (i >= 0 && j < 0)
			{
				sum = temp + num1[i] - '0';
            }
			else if (i< 0 && j >= 0)
			{
				sum = temp + num2[j] - '0';
			}
			temp = sum / 10;
			sum = sum % 10;
			res+=sum+'0';
		}
		if (temp!=0)
		{
			res += temp+'0';
		}

		reverse(res.begin(),res.end());
		return res;
	}
};

int main() {

	Solution s;

	string num1 = "0";
	string num2 = "0";

	cout << s.addStrings(num1,num2)<<endl;

	system("pause");
	return 0;
}