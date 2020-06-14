#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> res;
		if (target<3)
		{
			return res;
		}

		int left = 1;
		int right = 2;
		while (right<target && left<right)
		{
			if ((left+right)*(right-left+1)/2<target)
			{
				++right;
			}
			else if ((left + right)*(right - left + 1) / 2 > target)
			{
				++left;
			}
			else 
			{
				vector<int> temp;
				for (int i=left;i<=right;++i)
				{
					temp.push_back(i);
				}
				res.push_back(temp);
				++left;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> test;
	int target;
	cin >> target;
	test = s.findContinuousSequence(target);
	
	for (int i=0;i<test.size();++i)
	{
		for (int j=0;j<test[i].size();++j)
		{
			cout << test[i][j]<<" ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}