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

class Solution {
public:

	//--------------------------第一种后序
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root==nullptr)
		{
			return res;
		}

		stack<TreeNode*> temp;
		while (temp.size() || root!=nullptr)
		{
			while (root!=nullptr)
			{
				res.push_back(root->val);
				temp.push(root->left);
				root = root->right;
			}
			root = temp.top();
			temp.pop();
		}
		reverse(res.begin(),res.end());
		return res;
	}
	//-------------------------------第二种后序
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}
		stack<TreeNode*> temp;
		unordered_map<TreeNode*, bool> sig;
		while (temp.size() || root)
		{
			while (root)
			{
				temp.push(root);
				root = root->left;
			}
			while(temp.size() && sig[temp.top()])
			{
				res.push_back(temp.top()->val);
				temp.pop();
			}
			if (temp.size())
			{
				root = temp.top()->right;
				sig[temp.top()] = true;
			}
		}

		return res;
	}
};

int main() {

	Solution s;


	system("pause");
	return 0;
}