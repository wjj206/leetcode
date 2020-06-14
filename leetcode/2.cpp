#include<iostream>
#include<list>
#include<vector>

 using namespace std;
   struct ListNode {
       int val;
       struct ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
   };

//-------------------------------------------------本地通过版本
//class Solution {
//public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = new ListNode(-1);
		if (l1 == NULL || l2 == NULL)
		{
			return result;
		}

		int temp = 0;
		ListNode* tempnode = result;
		while ((l1->val!= -1) && (l2->val!= -1))
		{
			tempnode->next = new ListNode(-1);
			tempnode = tempnode->next;
			if ((l1->val + l2->val + temp) >= 10)
			{
				tempnode->val = l1->val + l2->val + temp - 10;
				temp = 1;
			}
			else
			{
				tempnode->val = l1->val + l2->val + temp;
				temp = 0;
			}
			
			 if ((l2->next->val != -1) && (l1->next->val == -1))
			{
				l2 = l2->next;
				while (l2->val != -1)
				{
					tempnode->next = new ListNode(-1);
					tempnode = tempnode->next;
					if ((l2->val + temp) >= 10)
					{
						tempnode->val = l2->val + temp - 10;
						temp = 1;
					}
					else
					{
						tempnode->val = l2->val + temp;
						temp = 0;
					}
					l2 = l2->next;
				}
					
				break;
			}
			 if ((l1->next->val != -1) && (l2->next->val == -1))
			{
				l1 = l1->next;
				while (l1->val != -1)
				{
					tempnode->next = new ListNode(-1);
					tempnode = tempnode->next;
					if ((l1->val + temp) >= 10)
					{
						tempnode->val = l1->val + temp - 10;
						temp = 1;
					}
					else
					{
						tempnode->val = l1->val + temp;
						temp = 0;
					}
					l1 = l1->next;
				}
				break;
			}
			
				l1 = l1->next;
				l2 = l2->next;
			
		}
		if (temp == 1)
		{
			tempnode->next = new ListNode(-1);
			tempnode = tempnode->next;
			tempnode->val = 1;
		}

		return result->next;
	}
//};

//---------------------------------------leetcode通过版本
	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* result = new ListNode(-1);
			if (l1 == NULL || l2 == NULL)
			{
				return result;
			}

			int temp = 0;
			ListNode* tempnode = result;
			while ((l1 != NULL) && (l1->val != -1) && (l2 != NULL) && (l2->val != -1))
			{
				tempnode->next = new ListNode(-1);
				tempnode = tempnode->next;
				if ((l1->val + l2->val + temp) >= 10)
				{
					tempnode->val = l1->val + l2->val + temp - 10;
					temp = 1;
				}
				else
				{
					tempnode->val = l1->val + l2->val + temp;
					temp = 0;
				}

				if ((l2->next != NULL) && (l2->next->val != -1) && (l1->next == NULL))
				{
					l2 = l2->next;
					while (l2 != NULL && l2->val != -1)
					{
						tempnode->next = new ListNode(-1);
						tempnode = tempnode->next;
						if ((l2->val + temp) >= 10)
						{
							tempnode->val = l2->val + temp - 10;
							temp = 1;
						}
						else
						{
							tempnode->val = l2->val + temp;
							temp = 0;
						}
						l2 = l2->next;
					}
					break;
				}
				if ((l1->next != NULL) && (l1->next->val != -1) && (l2->next == NULL))
				{
					l1 = l1->next;
					while (l1 != NULL && l1->val != -1)
					{
						tempnode->next = new ListNode(-1);
						tempnode = tempnode->next;
						if ((l1->val + temp) >= 10)
						{
							tempnode->val = l1->val + temp - 10;
							temp = 1;
						}
						else
						{
							tempnode->val = l1->val + temp;
							temp = 0;
						}
						l1 = l1->next;
					}
					break;
				}

				l1 = l1->next;
				l2 = l2->next;

			}
			if (temp == 1)
			{
				tempnode->next = new ListNode(-1);
				tempnode = tempnode->next;
				tempnode->val = 1;
			}

			return result->next;
		}
	};
	//----------------------------------------大佬精简版
	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* result = new ListNode(-1);
			if (l1 == NULL || l2 == NULL)
			{
				return result;
			}

			int temp = 0;
			int sum = 0;
			ListNode* tempnode = result;
			while ((l1 != NULL) || (l2 != NULL))
			{
				tempnode->next = new ListNode(-1);
				tempnode = tempnode->next;
				if (l1!=NULL)
				{
					sum += l1->val;
					l1 = l1->next;
				}
				if (l2 != NULL)
				{
					sum += l2->val;
					l2 = l2->next;
				}
				if (sum+temp >= 10)
				{
					tempnode->val = sum + temp-10;
					temp = 1;
				}
				else
				{
					tempnode->val = sum + temp;
					temp = 0;
				}
				sum = 0;
			}
			if (temp == 1)
			{
				tempnode->next = new ListNode(-1);
				tempnode = tempnode->next;
				tempnode->val = 1;
			}

			return result->next;
		}
	};


	int main() {
		vector<int> a1(2,9);
		vector<int> a2(1, 1);
		
		ListNode* a = new ListNode(-1);
		ListNode* aa = new ListNode(-1);
		ListNode* l1 =a;
		ListNode* l2 =aa;
		for (vector<int>::iterator it=a1.begin();it!=a1.end();++it)
		{
			a->val = *it;
			a->next = new ListNode(-1);
			a = a->next;
		}
		for (vector<int>::iterator it = a2.begin(); it != a2.end(); ++it)
		{
			aa->val = *it;
			aa->next = new ListNode(-1);
			aa = aa->next;
		}
		ListNode* result = addTwoNumbers(l1,l2);

		while (result!=nullptr)
		{
			cout << (result->val);
			result = result->next;
		}
		cin.ignore(100, '\n');
		cin.get();
		return 0;
	}