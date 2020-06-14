#include <bits/stdc++.h>
#include "G:\����\�����ļ�\written_examination_code\my.cpp"
using namespace std;

//vector<vector<int>>  temp(101, vector<int>(101));//���ڶ������ݽ��в��ԣ�����ȫ�ֱ������׳���ִ�д�������н����һ�������
class Solution {
public:
	vector<vector<long long>>  temp;
	Solution() : temp(101, vector<long long>(101)) {}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int x = obstacleGrid.size();
		int y = obstacleGrid[0].size();

		if (x <= 0 || y <= 0)
		{
			return NULL;
		}

		for (int i = 0; i < x ; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				if (i == 0 && j == 0 && obstacleGrid[i][j] == 0)
				{
					temp[i][j] = 1;
				}
				if (i == 0 && j == 0 && obstacleGrid[i][j] == 1)
				{
					temp[i][j] = 0;
					return 0;
				}

				if (i == 0 && j > 0 && obstacleGrid[i][j] == 0 )
				{
					temp[i][j] =  temp[i][j - 1];
				}

				if (i > 0 && j == 0 && obstacleGrid[i][j] == 0 )
				{
					temp[i][j] = temp[i-1][j];
				}

				if (i>0 && j>0 && obstacleGrid[i][j] == 0 )
				{
					temp[i][j] = temp[i][j-1] + temp[i - 1][j];
				}
			}
		}
		return temp[x-1][y-1];
	}
};

int main() {

	Solution s;

	vector<vector<int>> input = { {0,0} };
	cout << s.uniquePathsWithObstacles(input) << endl;

	system("pause");
	return 0;
}
