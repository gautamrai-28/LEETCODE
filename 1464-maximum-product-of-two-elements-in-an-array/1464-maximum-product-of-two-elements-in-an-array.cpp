class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int i = nums[n-1];
        int j = nums[n-2];

        return (i-1)*(j-1);
    }
};