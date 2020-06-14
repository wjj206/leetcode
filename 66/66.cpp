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
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		digits[len - 1] += 1;
	
			int i = len - 1;
			while (digits[i] == 10)
			{
				if (i==0)
				{
					digits[i] = 0;
					digits.insert(digits.begin(),1);

				}
				else
				{
					digits[i] = 0;
					digits[i - 1] += 1;
					i--;
				}
			}
	
		vector<int> res(digits);
		return res;
	}
};

int main() {

	Solution s;

	vector<int> input = {9,9};
	vector<int> res;
	res = s.plusOne(input);
	for (auto x:res)
	{
		cout << x << " ";
	}

	system("pause");
	return 0;
}