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

//-------------------------------方法一
//class Solution {
//public:
//	Solution(){
//		sum += ++N;
//	}
//
//	static void reset()
//	{
//		sum = 0;
//		N = 0;
//	}
//	int sumNums(int n) {
//		reset();
//
//		Solution* temp = new Solution[n];
//		delete[] temp;
//
//		return sum;
//	}
//private:
//	static int sum;
//	static int N;
//};
//int Solution::sum = 0;
//int Solution::N= 0;

//-------------------------------方法二
class Solution {
public:
	int sumNums(int n) {
		int ans = 0, A = n, B = n + 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		return ans >> 1;
	}
};


int main() {

	Solution s;

	cout << s.sumNums(10)<<endl;

	system("pause");
	return 0;
}