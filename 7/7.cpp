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
	int reverse(int x) {
		int zhengfu = 0;
		if (x<0)
		{
			zhengfu = 1;
		}

		int len = to_string(x).size();
		long  result=0;
		int xx;
		if (pow(-1, zhengfu)*x > INT_MAX)
		{
			return 0;
		}
		else
			xx = pow(-1, zhengfu)*x;
		int count = 0;
		while (count!=len-zhengfu)
		{
			++count;
			int yushu = xx % 10;
			result += yushu * pow(10,len-zhengfu-count);
			xx /= 10;
		}

		return pow(-1, zhengfu)*result > INT_MAX || pow(-1, zhengfu)*result < INT_MIN ? 0: pow(-1, zhengfu)*result;
		
	}
};

int main() {

	/*Solution s;

	cout << s.reverse(-123);*/

	cout << (-9) / 4 << " " << 9 / (-4) << " " << -(9 / 4) << endl;

	cout << (-9) %4 << " " << 9 % (-4) << " "<<9%4<<" " << -(9 % 4) << endl;

	system("pause");
	return 0;
}