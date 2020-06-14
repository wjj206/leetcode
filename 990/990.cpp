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


//--------------------------------90/181，未通过
//class Solution {
//public:
//	bool judge(int a, int b, vector<vector<int>> emap)
//	{
//		int hang = emap.size();
//		int lie = emap[0].size();
//		for (int i = 0; i < hang; ++i)
//		{
//			if (!(emap[i][a] == emap[i][b]  || (emap[i][a]==2 && emap[i][b] == 1) ||(emap[i][b]==2 && emap[i][a] == 1)))
//			{
//				return false;
//			}
//		}
//		for (int i = 0; i < lie; i++)
//		{
//			if (!(emap[a][i] == emap[b][i] || (emap[a][i]==2 && emap[b][i]==1)|| (emap[b][i]==2 && emap[a][i] == 1)))
//			{
//				return false;
//			}
//		}
//
//		return true;
//	}
//
//
//	bool equationsPossible(vector<string>& equations) {
//		int size = equations.size();
//		vector<vector<int>> temp(2 * size, vector<int>(2 * size, 2));
//
//		unordered_map<char, int> emap;
//		int s = 0;
//		for (auto equation : equations)
//		{
//			if (emap.find(equation[0]) == emap.end())
//			{
//				emap[equation[0]] = s++;
//			}
//			if (emap.find(equation[3]) == emap.end())
//			{
//				emap[equation[3]] = s++;
//			}
//
//			if (equation[1] == '=')
//			{
//				if (temp[emap[equation[0]]][emap[equation[3]]] == 2)
//				{
//					temp[emap[equation[0]]][emap[equation[3]]] = 1;
//					temp[emap[equation[3]]][emap[equation[0]]] = 1;
//				}
//				else {
//					if (temp[emap[equation[0]]][emap[equation[3]]] != 1)
//					{
//						return false;
//					}
//				}
//			}
//			else if (equation[1] == '!')
//			{
//				if (temp[emap[equation[0]]][emap[equation[3]]] == 2)
//				{
//					temp[emap[equation[0]]][emap[equation[3]]] = 0;
//					temp[emap[equation[3]]][emap[equation[0]]] = 0;
//				}
//				else {
//					if (temp[emap[equation[0]]][emap[equation[3]]] != 0)
//					{
//						return false;
//					}
//				}
//			}
//			else { return  false; }
//		}
//
//		for (int i = 0; i < emap.size(); ++i)
//		{
//			if (temp[i][i]==0)
//			{
//				return false;
//			}
//			else {
//				temp[i][i] = 1;
//			}
//		}
//
//		for (auto equation : equations)
//		{
//			if (equation[1] == '=')
//			{
//				if (!judge(emap[equation[0]], emap[equation[3]], temp))
//				{
//					return false;
//				}
//			}
//		}
//
//		return true;
//	}
//};

//------------------------------------------通过
class UnionFind {
private:
	vector<int> parent;

public:
	UnionFind(){
	parent.resize(26);
	iota(parent.begin(),parent.end(),0);
	}
	int find(int index)
	{
		if (index==parent[index])
		{
			return index;
		}
		parent[index] = find(parent[index]);
		return parent[index];
	}

	void UnionWrite(int index1,int index2)
	{
		parent[find(index1)] = find(index2);
		return;
	}
};

class Solution {
public:
	bool equationsPossible(vector<string>& equations) {
		UnionFind uf;
		for (auto equation:equations)
		{
			if (equation[1]=='=')
			{
				uf.UnionWrite(equation[0] - 'a', equation[3] - 'a');
			}
		}
		for (auto equation : equations)
		{
			if (equation[1] == '!')
			{
				if (uf.find(equation[0] - 'a')==uf.find(equation[3] - 'a'))
				{
					return false;
				}
			}
		}

		return true;
	}
};



int main() {

	Solution s;

	vector<string> input = { "a=b","b==c","a!=c" };
	cout << s.equationsPossible(input) << endl;


	system("pause");
	return 0;
}