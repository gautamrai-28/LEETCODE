class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int,int>lookup(n);
        stack<int>st;

        for(int i = n-1; i>=0; i--) {

            while(!st.empty() && nums2[i]>=st.top()) 
              st.pop();
            
            if(st.empty()) 
              lookup[nums2[i]] = -1;
            else
              lookup[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }

        vector<int>ans(m);

        for(int i = 0; i<m; i++) 
          ans[i] = lookup[nums1[i]];
        

        return ans;
    }
};