#include <bits/stdc++.h>
#include "G:\备份\桌面文件\written_examination_code\my.cpp"
using namespace std;
//----------------------------------纯递归,超过时间限制
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		if (m<0 || n<0)
//		{
//			return NULL;
//		}
//		if (m==1 || n==1)
//		{
//			return 1;
//		}
//		if (m==2)
//		{
//			return n;
//		}
//		if (n==2)
//		{
//			return m;
//		}
//
//		return uniquePaths(m-1,n) + uniquePaths(m,n-1);
//	}
//};

//--------------------------------------------改进递归,添加二维数组，通过
//class Solution {
//public:
//	vector<vector<int>>  temp;	
//	Solution() : temp(101, vector<int>(101)) {}
//
//	int uniquePaths(int m, int n) {
//		if (m <= 0 || n <= 0)
//		{
//			return NULL;
//		}
//		if (m == 1 || n == 1)
//		{
//			return 1;
//		}
//		if (m == 2)
//		{
//			return n;
//		}
//		if (n == 2)
//		{
//			return m;
//		}
//		if (temp[m][n]!=0)
//		{
//			return temp[m][n];
//		}
//		else
//		{
//			temp[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
//			return temp[m][n];
//		}
//
//	}
//};
//------------------------------------动态规划


vector<vector<int>>  temp(101, vector<int>(101));
class Solution {
public:
	//vector<vector<int>>  temp;
	//Solution() : temp(101, vector<int>(101)) {}

	int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0)
		{
			return NULL;
		}
		if (m == 1 || n == 1)
		{
			return 1;
		}

		for (int i=1;i<m+1;++i)
		{
			for (int j=1;j<n+1;++j)
			{
				if (i==1 || j==1)
				{
					temp[i][j] = 1;
				}
				else
				{
					temp[i][j] = temp[i - 1][j] + temp[i][j-1];
				}
			}
		}
		return temp[m][n];
	}
};
int main() {

	Solution s;

	cout << s.uniquePaths(7,3);
	system("pause");
	return 0;
}