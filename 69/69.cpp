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
//----------------------------------库函数
class Solution {
public:
	int mySqrt(int x) {
		return sqrt(x);
	}
};

//--------------------------------二分搜索
class Solution {
public:
	int mySqrt(int x) {
		//注：在中间过程计算平方的时候可能出现溢出，所以用long long。
		long long i = 0;
		long long j = x / 2 + 1;//对于一个非负数n，它的平方根不会大于（n/2+1）
		while (i <= j)
		{
			long long mid = (i + j) / 2;
			long long res = mid * mid;
			if (res == x) return mid;
			else if (res < x) i = mid + 1;
			else j = mid - 1;
		}
		return j;
	}
};

//------------------------------------------牛顿迭代法
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		double last = 0;
		double res = 1;
		while (res != last)
		{
			last = res;
			res = (res + x / res) / 2;
		}
		return int(res);
	}
};



int main() {

	Solution s;


	int  temp=8;
	cout << s.mySqrt(8) << endl;

	system("pause");
	return 0;
}