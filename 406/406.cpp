#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:

	static bool cmp(pair<int,int> a,pair<int,int> b)
	{
		if (a.first!=b.first)
		{
			return a.first > b.first;
		}
		return a.second < b.second;
	}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		if (people.empty())
		{
			return people;
		}
		int len = people.size();
	    pair<int, int> temp[99999];
		for (int i=0;i<len;++i)
		{
			int h = people[i][0];
			int num = people[i][1];
			pair<int, int> s = make_pair(h, num);
			temp[i] = s;
		}

		sort(temp,temp+len,cmp);

		vector<vector<int>> res;
		vector<int>  re;
		for (int i=0;i<len;++i)
		{
			int h = temp[i].first;
			int num = temp[i].second;

			re.push_back(h);
			re.push_back(num);
			res.insert(res.begin() + num, re);

			re.clear();
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>>  input = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };


	vector<vector<int>> res=s.reconstructQueue(input);

	for (int i=0;i<input.size();++i)
	{
		for (int j=0;j<2;++j)
		{
			cout << res[i][j]<<" ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}