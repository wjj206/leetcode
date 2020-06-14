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
	void reverseString(vector<char>& s) {
		char temp;
		int len = s.size();
		for (int i=0;i<(len/2);++i)
		{
			temp = s[i];
			s[i] = s[len-1-i];
			s[len - 1 - i] = temp;
		}
		//for (auto x:s)
		//{
		//	cout << x;
		//}
	}
};

int main() {

	vector<int> test = {3,2,1};

	cout << *(test.end() - 1);

	system("pause");
	return 0;
}