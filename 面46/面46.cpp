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
	int translateNum(int num) {
		string src = to_string(num);
		int p = 0, q = 0, r = 1;
		for (int i = 0; i < src.size(); ++i) {
			p = q;
			q = r;
			r = 0;
			r += q;
			if (i == 0) {
				continue;
			}
			auto pre = src.substr(i - 1, 2);
			if (pre <= "25" && pre >= "10") {
				r += p;
			}
		}
		return r;
	}
};


int main() {

	Solution s;
	int input = 12258;
	cout << s.translateNum(input) << endl;

	system("pause");
	return 0;
}