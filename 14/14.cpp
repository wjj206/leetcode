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
#include "G:\����\�����ļ�\written_examination_code\my.cpp"

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result = "";

		if (strs.empty())
		{
			return result;
		}

		/*sort(strs.begin(),strs.end());*/  //ò����Ϊvector��string���ȶ�̬�仯���������������

		for (int i=0;i<strs[0].size();++i)
		{
			char temp = strs[0][i];
			for (int j=1;j<strs.size();++j)
			{
				if (strs[j][i]!=strs[0][i])
				{
					return result;
				}
			}
			result.push_back(strs[0][i]);
		}
		return result;
	}
};

int main() {

	Solution s;

	vector<string> strs = {"abc","ab"};
	cout<<s.longestCommonPrefix(strs);
	
	system("pause");
	return 0;
}