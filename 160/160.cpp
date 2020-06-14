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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}

		stack<ListNode*> a, b;
		ListNode* head = headA;
		while (head!=nullptr)
		{
			a.push(head);
			head = head->next;
		}
	    head = headB;
		while (head != nullptr)
		{
			b.push(head);
			head = head->next;
		}

		ListNode* res=nullptr;
		while (!a.empty()  && !b.empty() && a.top()==b.top())
		{
			res = a.top();
			a.pop();
			b.pop();
		}

		return res;
	}
};

int main() {

	system("pause");
	return 0;
}