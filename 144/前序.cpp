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

//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/die-dai-fa-by-jason-2/
class Solution {
public:
	//------------------------------µÝ¹é
	void recursive(TreeNode* root, vector<int> &res)
	{
		if (root == nullptr)
		{
			return;
		}

		res.push_back(root->val);
		recursive(root->left, res);
		recursive(root->right, res);
		return;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}

		recursive(root, res);

		return res;
	}
	//-------------------------------µü´ú
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}

		stack<TreeNode*> temp;
		while (root!=nullptr || temp.size())
		{
			while (root!=nullptr)
			{
				res.push_back(root->val);
				temp.push(root->right);
				root = root->left;
		    }
			root = temp.top();
			temp.pop();
		}

		return res;
	}
};

int main() {

	Solution s;

	

	system("pause");
	return 0;
}