/*
Median of Two Sorted Arrays My Submissions Question
Total Accepted: 76162 Total Submissions: 430870 Difficulty: Hard
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).*/

using namespace std;

double find(vector<int>& a, int m, vector<int>& b, int n, int k)
{
	//always assume that m is equal or smaller than n
	if (m > n)
		return find(b, n, a, m, k);
	if (m == 0)
		return b[k - 1];
	if (k == 1)
		return min(a[0], b[0]);
	//divide k into two parts
	int pa = min(k / 2, m), pb = k - pa;
	if (a[pa - 1] < b[pb - 1]){
	    vector<int> anew(m-pa);
	    copy(a.begin()+ pa, a.end(), anew.begin());
		return find(anew, m - pa, b, n, k - pa);
	}
	else if (a[pa - 1] > b[pb - 1])
	{
	    vector<int> bnew(n-pb);
	    copy(b.begin()+ pb, b.end(), bnew.begin());
		return find(a, m, bnew, n - pb, k - pb);
	}
	else
		return a[pa - 1];
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if ( total & 0x1)
            return find(nums1, nums1.size(), nums2, nums2.size(), total / 2 + 1);
        else
            return (find(nums1, nums1.size(), nums2, nums2.size(), total/2) +
            find(nums1, nums1.size(), nums2, nums2.size(), total/2 +1))/2;
    }
};