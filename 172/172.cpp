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

class Solution {
public:
	int trailingZeroes(int n) {
		int count = 0;
		while (n)
		{
				count +=n / 5;
				n/= 5;	
		}
		return count;
	}
};

int main() {
	Solution s;

	cout << s.trailingZeroes(13);

	system("pause");
	return 0;
}