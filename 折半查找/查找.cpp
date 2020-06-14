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
class  Solution
{
public:

	int binary_lf(vector<int> input,int res)
	{
		sort(input.begin(),input.end());

		int low = 0;
		int high = input.size() - 1;
		while (low<=high)
		{
			int mid = (high+low) / 2;
			if (input[mid]>res)
			{
				high = mid - 1;
			}
			else if (input[mid] < res)
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}

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
	int res;
	cin >> res;

	cout << s.binary_lf(input,res) << endl;

	system("pause");
	return 0;
}