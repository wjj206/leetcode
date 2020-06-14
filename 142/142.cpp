#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode* kuai = head;
		ListNode* man = head;

		while (kuai != nullptr && kuai->next != nullptr)
		{
			kuai = kuai->next->next;
			man = man->next;

			if (kuai == man)
			{
				break;
			}
		}

		if (kuai==nullptr || kuai->next==nullptr)
		{
			return nullptr;
		}

		man = kuai->next;
		int num = 1;
		while (man!=kuai)
		{
			++num;
			man = man->next;
			
		}

		kuai = head;
		for (int i=0;i<num;++i)
		{
			kuai = kuai->next;
		}
		man = head;

		while(kuai!=man)
		{
			kuai = kuai->next;
			man = man->next;
		}
		return kuai;
	}
};

int main() {

	Solution s;

	vector<int> input;
	int  temp;


	system("pause");
	return 0;
}