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


//-----------------------------双指针
class Solution {
public:
	int maxArea(vector<int>& height) {

		int len = height.size();
		if (len<2)
		{
			return NULL;
		}

		int max=0;
		int zuo= 0;
		int you =len-1;
		int s = 0;

		while(zuo!=you)
		{
			if (height[zuo]<height[you])
			{
				s = height[zuo] *(you - zuo);
				++zuo;
			}
			else
			{
				s = height[you] *(you-zuo);
				--you;
			}
			if (s>max)
			{
				max = s;
			}
		}
		return max;
	}
};

//-----------------------------纯暴力，超出时间限制48/50
//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//
//		if (height.size() < 2)
//		{
//			return NULL;
//		}
//
//		int max;
//		for (int i = 0; i < height.size(); ++i)
//		{
//			int temp = 0;
//			int lower = 0;
//			for (int j = i + 1; j < height.size(); ++j)
//			{
//				lower = height[i] <= height[j] ? height[i] : height[j];
//				temp = (j - i)*lower;
//				if (temp > max)
//				{
//					max = temp;
//				}
//			}
//		}
//		return max;
//	}
//};


int main() {

	Solution s;

	vector<int> input = { 1,8,6,2,5,4,8,3,7 };
	cout << s.maxArea(input);
	
	system("pause");
	return 0;
}