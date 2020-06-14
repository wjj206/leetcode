#include <bits/stdc++.h>
#include "G:\备份\桌面文件\written_examination_code\my.cpp"
using namespace std;
//超过时间限制
class Solution {
public:
	int climbStairs(int n) {
		if (n<=0)
		{
			return NULL;
		}
		if(n==1)
		{
			return 1;
		}
		if (n==2)
		{
			return 2;
		}
		int count = climbStairs(n - 1) + climbStairs(n - 2);
		return count;
	}
};
//------------------------------
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0)
		{
			return NULL;
		}
		if (n == 1)
		{
			return 1;
		}
		if (n == 2)
		{
			return 2;
		}
		int v1 = 1;
		int v2 = 2;
		int count = 0;
		for (int i = 3; i <= n; ++i)
		{
			count = v1 + v2;
			v1 = v2;
			v2 = count;
		}
		return count;
	}
};

int main() {

	Solution s;

	cout << s.climbStairs(5);
	system("pause");
	return 0;
}