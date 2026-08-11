class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        int n = intervals.size();

        ans.push_back(intervals[0]);
        int i = 1;
        while(i<n) {
            if(intervals[i][0] <= ans.back()[1]) {
                //ans.back()[0] = min(intervals[i][0], ans.back()[0]);//no need of this line as intervals are already sorted with respect of first value;
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }

        return ans;
    }
};