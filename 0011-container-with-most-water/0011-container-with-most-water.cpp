class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
       int left = 0, right = n-1;
       int maxWater = 0; //ans;

       while(left<right) {
        int h = min(height[left],height[right]);
        int width = right -left;
        int currWater  = h * width;

        maxWater = max(maxWater,currWater);

        if(height[left]<height[right]) left++;
        else right--;
       }

       return maxWater;
    }
};