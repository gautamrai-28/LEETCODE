class Solution {
public:
//    const int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;

        long long sumA = 0, sumB = 0;

        while(i<n && j<m) {
            if(nums1[i]<nums2[j]) {
                sumA+=nums1[i];
                i++;
            } 
            else if (nums1[i]>nums2[j]) {
                sumB+=nums2[j];
                j++;
            }
            else {
                ans = ans + max(sumA,sumB) + nums2[j];
                sumA = 0, sumB = 0;
                i++, j++;
            }
        }

        while(i<n) {
            sumA+=nums1[i];
            i++;
        }

        while(j<m) {
            sumB+=nums2[j];
            j++;
        }

        ans = ans + max(sumA,sumB);

        return ans%1000000007;
    }
};