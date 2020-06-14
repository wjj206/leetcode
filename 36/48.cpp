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

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int lenx = matrix.size();
		int leny = matrix[0].size();

		for (int i=0;i<lenx;++i)//转置
		{
			for (int j=0;j<i;++j)
			{
				swap(matrix[i][j],matrix[j][i]);
			}
		}

		for (int i = 0; i < lenx;++i)//翻转
		{
			reverse(matrix[i].begin(),matrix[i].end());
		}
		return;
	}

};

int main() {

	Solution s;

	vector<int> input;
	int  temp;


	system("pause");
	return 0;
}



