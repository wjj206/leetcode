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
	int titleToNumber(string s) {

		if (s.empty())
		{
			return 0;
		}

		int res = 0;
		int num = 0;
		int len = s.size();
		for (int i=len-1;i>=0;--i)
		{
			res += (s[i] -'A'+1) *pow(26, num++);
		}

		return res;
	}
};
int main() {


	Solution s;
	string input = "AB";
	cout << s.titleToNumber(input);
	system("pause");
	return 0;
}