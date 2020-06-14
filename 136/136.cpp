#include <bits/stdc++.h>

using namespace std;

//---------------------------------------------
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int>  temp;
		for (auto x:nums)
		{
			if (temp.count(x))
			{
				temp.erase(x);
			}
			else
			{
				temp.insert(x);
			}
		}
		return *(temp.begin());
	}
};

//----------------------------------------------
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		for (int i=0,j=1;j<nums.size()-1;i=i+2,j=j+2)
		{
			if (nums[i]!=nums[j])
			{
				return nums[i];
			}
		}

		return *(nums.rbegin());
	}
};

//---------------------------------------------------
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = nums[0];
		for (int i=1;i<nums.size();++i)
		{
			result = result ^ nums[i];
		}
		return result;
	}
};



int main() {

	Solution s;

	vector<int> input;
	int  temp;


	system("pause");
	return 0;
}