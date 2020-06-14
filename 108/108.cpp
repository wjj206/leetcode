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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//-----------------------------------------不对
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return nullptr;
		}

		int mid = (nums.size() - 1) / 2;
		int left = mid - 1;
		int right = mid + 1;
		TreeNode* root = new TreeNode(nums[mid]);
		TreeNode* res = root;

		while (right != nums.size())
		{
			TreeNode* rightn = new TreeNode(nums[right]);
			root->right = rightn;
			root = rightn;
			++right;
		}
		root = res;
		while (left != -1)
		{
			TreeNode* leftn = new TreeNode(nums[left]);
			root->left = leftn;
			root = leftn;
			--left;
		}

		return res;
	}
};


//-------------------------------------------------通过
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return nullptr;
		}

		int mid = (nums.size() - 1) / 2;
		TreeNode* root = new TreeNode(nums[mid]);

		vector<int> lv(nums.begin(),nums.begin()+mid);
		vector<int> rv(nums.begin()+mid+1,nums.end());

		root->left = sortedArrayToBST(lv);
		root->right = sortedArrayToBST(rv);

		return root;
	}
};



int main() {

	Solution s;

	vector<int> input;
	int  temp;
	while ((cin.peek() != EOF) && (cin.peek() != '\n'))
	{
		cin >> temp;
		input.push_back(temp);
	}
	for (int i = 0; i < input.size(); i++)
	{
		cout << i << "th : " << input[i] << endl;
	}

	system("pause");
	return 0;
}