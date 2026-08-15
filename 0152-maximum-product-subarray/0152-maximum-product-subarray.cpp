class Solution {
public:
    long long maxProduct1(vector<int>&nums , int n) {
        long long currProduct = 1;
        long long maxProduct = INT_MIN;

        for(int i = 0; i<n; i++) {
            currProduct *= nums[i];
            maxProduct = max(maxProduct, currProduct);

            if(currProduct==0) 
              currProduct = 1;
        }
        return maxProduct;
        
    }
    long long maxProduct2(vector<int>&nums , int n) {
        long long currProduct = 1;
        long long maxProduct = INT_MIN;

        for(int i = n-1; i>=0; i--) {
            currProduct *= nums[i];
            maxProduct = max(maxProduct, currProduct);

            if(currProduct==0) 
              currProduct = 1;
        }
        return maxProduct;
        
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        return max(maxProduct1(nums,n), maxProduct2(nums,n));
    }
};