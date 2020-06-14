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
	double new21Game(int N, int K, int W) {
		if (K == 0)
		{
			return 1;
		}

		vector<double> dp(K + W, 0);
		for (int i = K; i < K + W && i<=N; ++i)
		{
			dp[i] = 1.0;
		}

	
		dp[K - 1] = double(min(N - K + 1, W)) / double(W);
		for (int i = K - 2; i >= 0; --i)
		{
			dp[i] = dp[i + 1] + dp[i + 1]/W - dp[i + 1 + W]/W;
		}

		return dp[0];
	}
};

int main() {

	Solution s;

	int N=1, K=0, W =1;
	cout << s.new21Game(N,K,W) << endl;

	system("pause");
	return 0;
}