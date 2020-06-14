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




class  Solution
{
public:

	//----------------------冒泡排序
	vector<int> maopao(vector<int> input)
	{
		if (input.empty())
		{
			return input;
		}

		for (int i = 0; i < input.size(); ++i)
		{
			for (int j = input.size() - 1; j > i; --j)
			{
				if (input[j] < input[j - 1])
				{
					swap(input[j], input[j - 1]);
				}
			}
		}

		return input;
	}

	//-----------------------简单选择排序
	vector<int> easy_choose(vector<int> input)
	{
		if (input.empty())
		{
			return input;
		}

		for (int i = 0; i < input.size(); ++i)
		{
			int min = i;
			for (int j = i + 1; j < input.size(); ++j)
			{
				if (input[min] > input[j])
				{
					min = j;
				}
			}
			if (min != i)
			{
				swap(input[i], input[min]);
			}
		}

		return input;
	}

	//-----------------------直接插入排序
	vector<int> direct_insert(vector<int> input)
	{
		if (input.empty())
		{
			return input;
		}

		for (int i = 1; i < input.size(); i++)
		{
			//if (input[i]<input[i-1])//写法1
			//{
			//	int temp = input[i];
			//	int j;
			//	for (j=i-1;input[j]>temp;--j)
			//	{
			//		input[j+1] = input[j];
			//	}
			//	input[j + 1] = temp;
			//}

			if (input[i] < input[i - 1])//写法2
			{
				int temp = input[i];
				for (int j = i - 1; input[j] > temp; --j)
				{
					swap(input[j], input[j + 1]);
				}

			}
		}
		return input;
	}

	//--------------------------------希尔排序
	vector<int> shell(vector<int> input)
	{
		if (input.empty())
		{
			return input;
		}
		int inc = input.size();
		while (inc > 1)
		{
			inc = inc / 3 + 1;
			for (int i = inc; i < input.size(); ++i)
			{
				if (input[i - inc] > input[i])
				{
					int temp = input[i];
					for (int j = i - inc; j >= 0 && input[j] > temp; j = j - inc)
					{
						swap(input[j], input[j + inc]);
					}
				}
			}
		}

		return input;
	}

	//-----------------------------------堆排序

	void adjust_heap(vector<int> &input, int begin, int end)
	{
		int temp = input[begin];
		for (int i = 2 * (begin + 1) - 1; i <= end; i = i * 2)
		{
			if (i < end && input[i] < input[i + 1])
			{
				++i;
			}
			if (input[i] <= temp)
			{
				break;
			}
			input[begin] = input[i];
			begin = i;
		}
		input[begin] = temp;
	}

	vector<int> heap(vector<int> input)
	{
		//假定传入的被排序数组不为空

		int len = input.size();

		for (int i = len / 2 - 1; i >= 0; --i)
		{
			adjust_heap(input, i, len - 1);
		}

		for (int i = len - 1; i > 0; --i)
		{
			swap(input[0], input[i]);
			adjust_heap(input, 0, i - 1);
		}
		return input;
	}

	//--------------------------------归并排序
	vector<int> merge(vector<int> &input, int begin, int end, int mid)
	{
		vector<int> temp(end - begin + 1, 0);
		int k = 0;
		int i = begin, j = mid + 1;
		while (i <= mid && j <= end)
		{
			if (input[i] < input[j])
			{
				temp[k++] = input[i++];
			}
			else
			{
				temp[k++] = input[j++];
			}
		}

		while (i <= mid)
		{
			temp[k++] = input[i++];
		}
		while (j <= end)
		{
			temp[k++] = input[j++];
		}
		for (int i = 0; i < temp.size(); ++i)
		{
			input[begin++] = temp[i];
		}

		return input;

	}

	vector<int> mergesort(vector<int> &input, int begin, int end)
	{
		if (begin == end)
		{
			return input;
		}

		int mid = (begin + end) / 2;
		mergesort(input, begin, mid);
		mergesort(input, mid + 1, end);
		merge(input, begin, end, mid);

		return input;
	}

	//---------------------------------基数排序
	//https://blog.csdn.net/zhen921/article/details/80354096?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-9.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-9.nonecase
	int max(vector<int> input)//查找最大位数
	{
		if (input.empty())
		{
			return 0;
		}
		int max = 1;
		int len = input.size();
		for (int i = 0; i < len; ++i)
		{
			int temp = 1;
			while (input[i] / 10)
			{
				temp++;
				input[i] = input[i] / 10;
			}
			if (temp > max)
			{
				max = temp;
			}
		}
		return max;
	}

	vector<int> ji_shu_sort(vector<int> input)//排序
	{
		int maxlen = max(input);
		int num = 1;
		int len = input.size();
		for (int i=0;i<maxlen;++i)//进行maxlen次排序
		{
			vector<int> count(len, 0);
			vector<vector<int>> temp(len, vector<int>(len, 0));
			for (int j=0;j< len;++j)
			{
				int tempval = input[j] / num;
				int yushu = tempval % 10;
				++count[yushu];
				temp[yushu][count[yushu] - 1] = input[j];
			}

			input.clear();

			for (int m = 0; m < len; ++m)
			{
				if (count[m] != 0)
				{
					for (int n=0;n<count[m];++n)
					{
						input.push_back(temp[m][n]);
					}
				}
			}


			num = num * 10;

		}
		return input;
	}


    //--------------------------------快速排序
	vector<int> quicksort(vector<int> &input,int begin ,int end)
	{
		
		if (begin>=end)
		{
			return input;
		}
		int temp = input[begin];
		int i = begin, j = end;
		while(i<j)
		{
			while (i < j && input[j] >= temp)
			{
				--j;
			}
			while (i<j && input[i]<=temp)
			{
				++i;
			}
			if (i<j)
			{
				swap(input[i],input[j]);
			}

	    }
		swap(input[begin],input[j]);
		quicksort(input,begin,j-1);
		quicksort(input,j+1,end);

		return input;
	}
};


int main() {

	Solution s;

	vector<int> input;
	int  temp;
	while ((cin.peek() != EOF) && (cin.peek() != '\n'))
	{
		cin >> temp;
		input.push_back(temp);
	}

	vector<int> res = s.ji_shu_sort(input);

	for (int i = 0; i < res.size(); i++)
	{
		cout << i << "th : " << res[i] << endl;
	}

	system("pause");
	return 0;
}