class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int leftMax = 0, rightMax = 0;
        int total = 0;

        int l = 0, r =n-1;

        while(l<=r) {
            leftMax =  max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax<rightMax) {
                total+= (leftMax - height[l]);
                l++;
            } else {
                total += (rightMax - height[r]);
                r--;
            }
        }

        return total;
    }
};