#include <bits/stdc++.h>
#include "G:\备份\桌面文件\written_examination_code\my.cpp"
using namespace std;

 /*Definition for singly-linked list.*/
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head==nullptr)
		{
			return false;
		}
		ListNode* kuai = head;
		ListNode* man = head;

		while (kuai!=nullptr && kuai->next!=nullptr)
		{
			kuai = kuai->next->next;
			man = man->next;

			if (kuai==man)
			{
				return true;
			}
		}

		return false;
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;
	
	system("pause");
	return 0;
}