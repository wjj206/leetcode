#include <bits/stdc++.h>

using namespace std;

class  Solution
{
public:
	bool valid_char(char a)
	{
		if ((a>='0'&& a<='9') || (a>='a' && a<='z') || (a>='A' && a<='Z'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool is_same(char a,char b)
	{
		if (((a >= '0'&& a <= '9')&& (b >= '0'&& b <= '9'))|| ((a >= 'A' && a <= 'Z') && (b >= 'A' && b <= 'Z')))
		{
			return a == b;
		}
		return false;
	}
	bool isPalindrome(string s) {
		if (s.size()==0)
		{
			return true;
		}
		int backspace = 0;
		for(int i=0;i<s.size();++i)
		{
			if (s[i]==' ')
			{
				++backspace;
			}
		}
		if (s.size()==backspace)
		{
			return true;
		}
		string input;
		for (int i=0;i<s.size();++i)
		{
			if (valid_char( s[i]))
			{
				input += s[i];
			}
		}

		int len = input.size();
		if (len==1 || len == 0)
		{
			return true;
		}
		/*transform(input.begin(), input.end(), input.begin(), toupper);*///leetcode²»Í¨¹ı
		for (int i=0;i<len;++i)
		{
			if (input[i]>='a' && input[i]<='z')
			{
				input[i] = toupper(input[i]);
			}
		}
		if (len&1)
		{
			for (int i=0;i<len/2;++i)
			{
				if (!is_same( input[i],input[len-1-i]))
				{
					return false;
				}
			}
		}
		else
		{
			for (int i=0;i<=len/2;++i)
			{
				if (!is_same(input[i], input[len - 1 - i]))
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main() {

	Solution s;

	string sa = "0P";	
	cout << s.isPalindrome(sa);

	system("pause");
	return 0;
}

