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
	//-----------------------------------------递归写法
	void recursive(TreeNode* root, vector<int> &res)
	{
		if (root==nullptr)
		{
			return;
		}
		recursive(root->left, res);
		res.push_back(root->val);
		recursive(root->right,res);
		return;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root==nullptr)
		{
			return res;
		}
        
		recursive(root,res);

		return res;
	}

	//--------------------------------------中序迭代写法
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}

		stack<TreeNode*> temp;

		while (temp.size() || root)
		{
			while (root)
			{
				temp.push(root);
				root = root->left;
			}
			root = temp.top();
			temp.pop();
			res.push_back(root->val);
			root = root->right;

		}
		

		return res;
	}
	//------------------------------中序迭代,这个方法真的秀，leetcode已收藏
	//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/wan-quan-mo-fang-di-gui-bu-bian-yi-xing-miao-sha-q/
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> temp;

		if (root != nullptr)
		{
			temp.push(root);
		}

		while(!temp.empty())
		{
			root = temp.top();
			temp.pop();
			if (root!=nullptr)
			{
				if (root->right) 
				{
					temp.push(root->right);
				}
				temp.push(root);
				temp.push(nullptr);
				if (root->left)
				{
					temp.push(root->left);
				}
			}
			else
			{
				res.push_back(temp.top()->val);
				temp.pop();
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