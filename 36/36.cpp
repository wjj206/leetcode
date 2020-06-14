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

	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.empty())
		{
			return false;
		}

		vector<vector<int>> x(9,vector<int>(9,0));
		vector<vector<int>> y(9, vector<int>(9, 0));
		vector<vector<int>> matrix(9, vector<int>(9, 0));

		for (int i=0;i<board.size();++i)
		{
			for (int j=0;j<board[i].size();++j)
			{
				if (board[i][j]!='.')
				{
					if (++x[i][board[i][j]-'0'-1] >1  || 
						++y[j][board[i][j] - '0' - 1] >1 ||
						++matrix[3*(i/3)+j/3][board[i][j] - '0' - 1] >1)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;


	system("pause");
	return 0;
}