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
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows);
		if (numRows==0)
		{
			return res;
		}
		for (int i=0;i<numRows;++i)
		{
			for (int j=0;j<=i;++j)
			{
				res[i].push_back(1);
				if (j!=0 && j!=i)
				{
					res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
				}
			}
		}
		return res;
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;
	while ((cin.peek() != EOF) && (cin.peek() != '\n'))
	{
		cin >> temp;
		input.push_back(temp);
	}
	for (int i = 0; i < input.size(); i++)
	{
		cout << i << "th : " << input[i] << endl;
	}

	system("pause");
	return 0;
}