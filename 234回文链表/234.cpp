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
#include "G:\备份\桌面文件\written_examination_code\my.cpp"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//---------------------------------------------自写
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head==nullptr || head->next==nullptr)
		{
			return true;
		}

		vector<int> input;
		ListNode* temp = head;
		while (temp!=nullptr)
		{
			input.push_back(temp->val);
			temp = temp->next;
		}

		for (int i=0;i<input.size()/2;++i)
		{
			if (input[i]!=input[input.size()-1-i])
			{
				return false;
			}
		}
		return true;
	}
};

//-------------------------------------------大佬：双指针
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return 1;
		ListNode *fast = head, *slow = head;
		ListNode *p, *pre = NULL;
		while (fast && fast->next) {
			p = slow;
			slow = slow->next;    //快慢遍历
			fast = fast->next->next;

			p->next = pre;  //翻转
			pre = p;
		}
		if (fast)  //奇数个节点时跳过中间节点
			slow = slow->next;

		while (p) {       //前半部分和后半部分比较
			if (p->val != slow->val)
				return 0;
			p = p->next;
			slow = slow->next;
		}
		return 1;
	}
};


int main() {

	Solution s;

	

	system("pause");
	return 0;
}