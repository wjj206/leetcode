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
 
  //------------------------------------递归
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head==nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* first;
		first = reverseList(head->next);
		head->next->next =head;
		head->next = nullptr;
		return first;
	}
};

//----------------------------------双指针1
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* pre = nullptr;
	    ListNode* cur = head;
		while (cur!=nullptr)
		{
			ListNode* temp = cur->next;
			cur->next = nullptr;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};
//----------------------------------双指针2
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* cur = head;
		while (cur != nullptr)
		{
			ListNode* temp = head->next->next;
			cur->next->next =cur;
			cur=head->next;
			head->next=temp;
		}
		return head;
	}
};

int main() {

	Solution s;


	system("pause");
	return 0;
}