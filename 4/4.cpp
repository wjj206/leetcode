#include<vector>
#include<iostream>
using namespace std;
//--------------------------�Լ��Ľⷨ
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() && nums2.empty())
		{
			return NULL;
		}

		int s1 = nums1.size();
		int s2 = nums2.size();
		double result;
		int m = 0, n = 0;

		if ((s1 + s2) & 1)//����
		{
			int target = (s1 + s2 + 1) / 2;
			if (s1!=0 && s2!=0)
			{
				for (int i = 0; i < target; ++i)
				{
					if ((m < s1 && n < s2 && nums1[m] <= nums2[n]) || (n == s2))
					{
						result = nums1[m];
						++m;
					}
					else
					{
						result = nums2[n];
						++n;
					}
				}
			}
			else if (s1==0)
			{
				result = nums2[target-1];
			}
			else if (s2==0)
			{
				result = nums1[target - 1];
			}
		}
		else//ż��
		{
			int target1 = (s1 + s2 + 1) / 2;
			int target2 = target1 + 1;
			vector<int> target;
			if (s1 != 0 && s2 != 0)
			{
				while (target.size() < target2)
				{
					if ((m < s1 && n < s2 && nums1[m] <= nums2[n]) || (n == s2))
					{
						target.push_back(nums1[m]);
						++m;
					}
					else
					{
						target.push_back(nums2[n]);
						++n;
					}
				}
				result = (double)(target[target1 - 1] + target[target2 - 1]) / 2;
			}
			else if(s1==0)
			{
				result = (double)(nums2[target1 - 1] + nums2[target2 - 1]) / 2;
			}
			else if(s2==0)
			{
				result = (double)(nums1[target1 - 1] + nums1[target2 - 1]) / 2;
			}
		}

		return result;
	}
};
//---------------------------------���еĽⷨ
//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //��֤����1һ�����
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci Ϊ��i������ĸ�,����C1Ϊ2ʱ��ʾ��1������ֻ��2��Ԫ�ء�LMaxiΪ��i�����������Ԫ�ء�RMiniΪ��i�����������Ԫ�ء�
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //����Ŀǰ���������'#'��������1��2*n����

		while (lo <= hi)   //����
		{
			c1 = (lo + hi) / 2;  //c1�Ƕ��ֵĽ��
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};


int main() {

	Solution s;

	vector<int> nums1 = {1};
	vector<int> nums2 = {1};

	cout << s.findMedianSortedArrays(nums1,nums2);

	cin.ignore(100, '\n');
	cin.get();
	return 0;
}