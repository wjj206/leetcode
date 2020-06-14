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
#include "G:\����\�����ļ�\written_examination_code\my.cpp"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//---------------------------------------------��д
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

//-------------------------------------------���У�˫ָ��
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return 1;
		ListNode *fast = head, *slow = head;
		ListNode *p, *pre = NULL;
		while (fast && fast->next) {
			p = slow;
			slow = slow->next;    //��������
			fast = fast->next->next;

			p->next = pre;  //��ת
			pre = p;
		}
		if (fast)  //�������ڵ�ʱ�����м�ڵ�
			slow = slow->next;

		while (p) {       //ǰ�벿�ֺͺ�벿�ֱȽ�
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