class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r = 0, l = 0;
        int maxLen = 0;
        int countOfZero = 0;

        while(r<nums.size()) {

            if(nums[r]!=1) 
              countOfZero++;

            while(countOfZero > k) {
                if(nums[l] == 0)
                   countOfZero--;
                
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};