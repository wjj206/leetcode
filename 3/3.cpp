#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
		{
			return 0;
		}

		int max = 1;
		int local_max = 1;
		int first = 0;
		int size = s.size();
		for (int i=1;i<size;++i)
		{
			local_max = 1;
			for (int j=first;j<i;++j)
			{
				if (s[i]==s[j])
				{
					if ((i-j )>max)
					{
						local_max = i-j;
					}
					first = j + 1;
					break;
				}
				else
				{
					++local_max;
				}

			}
			if (max < local_max)
			{
				max = local_max;
			}
		}
		return max;
	}
};


int main() {
	Solution s;
	string test = "abcdeabcabc";
	cout << s.lengthOfLongestSubstring(test);
	cin.ignore(100, '\n');
	cin.get();
	return 0;
}