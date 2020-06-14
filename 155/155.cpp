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
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		temp.push(x);
		if (min.empty())
		{
			min.push(x);
		}
		else
		{
			if (x<min.top())
			{
				min.push(x);
			}
			else
			{
				min.push(min.top());
			}
		}
	}

	void pop() {
		if (temp.empty())
		{
			return;
		}
		else
		{
			temp.pop();
			min.pop();
		}
	}

	int top() {
		if (temp.empty())
		{
			return NULL;
		}
		else
		{
			return temp.top();
		}
	}

	int getMin() {
		if (min.empty())
		{
			return NULL;
		}
		else
		{
			return min.top();
		}
	}

private:
	stack<int> temp;
	stack<int> min;


};


int main() {



	system("pause");
	return 0;
}