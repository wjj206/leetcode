#include<string>
#include<stack>
#include<iostream>
#include<vector>
using namespace std;
//-----------------------------------暴力法
//101 / 103 个通过测试用例
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		if (s.empty() || s.size()==1)
//		{
//			return s;
//		}
//		
//		string temp=s;
//		reverse(temp.begin(),temp.end());
//		int maxlen = 0;
//		int singnal = 0;
//
//		for (int i=0;i<s.size();++i)
//		{
//			string tool = "";
//			for (int j=i;j<s.size();++j)
//			{
//				tool += s[j];
//				if (maxlen<tool.size() && s[i]==s[j]  && temp.find(tool) != -1)
//				{
//					maxlen = tool.size();
//					singnal = i;
//				}
//			}
//			if (maxlen>=(s.size()-i))
//			{
//				break;
//			}
//		
//		}
//
//		return s.substr(singnal,maxlen);
//	}
//};

//---------------------------------暴力法修改版,通过
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		if (s.empty() || s.size() == 1)
//		{
//			return s;
//		}
//
//		string temp = s;
//		reverse(temp.begin(), temp.end());
//		int maxlen = 0;
//		int singnal = 0;
//
//		for (int i = 0; i < s.size(); ++i)
//		{
//			string tool = "";
//			for (int j = i; j < s.size(); ++j)
//			{
//				tool += s[j];
//				if(maxlen >=tool.size())
//				{
//					continue;
//				}
//				if ( temp.find(tool) != -1)
//				{
//					if (s[i] == s[j])
//					{
//						maxlen = tool.size();
//						singnal = i;
//					}
//				}
//				else
//				{
//					break;
//				}
//			}
//			if (maxlen >= (s.size() - i))
//			{
//				break;
//			}
//
//		}
//
//		return s.substr(singnal, maxlen);
//	}
//};
//-----------------------------------动态规划
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty() || s.size() == 1)
		{
			return s;
		}

		int len = s.size();
		vector<vector<int>> temp(len,vector<int>(len,0));
		int start = 0, max = 1;

		for(int i=0; i<len; ++i)
		{
			temp[i][i] = 1;
			if (i<(len-1) && s[i]==s[i+1])
			{
				temp[i][i+1] = 1;
				start = i;
				max = 2;
			}
		}
		for (int i=3;i<=len;++i)
		{
			for (int j=0;j+i-1<len;++j)
			{
				int end = j + i - 1;
				if(s[j]==s[end] && temp[j+1][end-1]==1)
				{
					temp[j][end] = 1;
					if (i>max)
					{
						start = j;
						max = i;
					}
				}

			}
		}

		return s.substr(start,max);
	}
};

int main() {

	string test("babad");
	Solution s;

	cout << s.longestPalindrome(test);

	cin.ignore(100, '\n');
	cin.get();
	return 0;
}