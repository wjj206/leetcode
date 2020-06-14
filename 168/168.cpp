#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//	string convertToTitle(int n) {
//		string temp = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//		string result;
//		int num = 0;
//		if (n<=26)
//		{
//			result = temp[n];
//		}
//		while(n>26)
//		{
//			num = (n) % 26;
//			if (num != 0)
//			{
//				result += temp[num];
//				n = n / 26;
//			}
//			if (num==0)
//			{
//				result += temp[26];
//				n = (n / 26) - 1;
//			}
//
//			if (n <= 26)
//			{
//				result += temp[n];
//				reverse(result.begin(), result.end());
//			}
//		}
//		return result;
//	}
//};

class Solution {
public:
	string convertToTitle(int n) {
		string res;
		int temp = 0;
		while (n != 0)
		{
			temp = n % 26;
			if (temp == 0)
			{
				res = 'Z' + res;
				n--;
			}
			else
				res = (char)(temp + 'A' - 1) + res;
			n = n / 26;
		}
		return res;
	}
};


int main() {

	Solution s;
	
	cout << s.convertToTitle(51);

	system("pause");
	return 0;
}