class Solution {
public:
    int helper(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int l = 0, r = 0, count = 0;

        while(r<nums.size()) {
            mpp[nums[r]]++;

            while(mpp.size()>k) {
                mpp[nums[l]]--;

                if(mpp[nums[l]] == 0) 
                  mpp.erase(nums[l]);
                
                l++;
            }
            count+= (r-l+1);

            r++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans  = 0;

        ans = helper(nums,k) - helper(nums, k-1);

        return ans;
    }
};