#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool conti(char a,char b)
	{
		if (a=='z')
		{
			return b == 'a';
		}
		return b - a == 1;
	}
	int findSubstringInWraproundString(string p) {
		int len = p.size();
		int k = 0;
		vector<int> result(26,0);
		for (int i=0;i<len;++i)
		{
			if (i==0 || conti(p[i-1],p[i]))
			{
				++k;
			}
			else
			{
				k = 1;
			}
			result[p[i] - 'a'] = max(result[p[i] - 'a'],k);
		}
		return accumulate(result.begin(), result.end(), 0);
	}
};

int main() {

	Solution s;
	string p = "zab";

	cout << s.findSubstringInWraproundString(p);

	system("pause");
	return 0;
}