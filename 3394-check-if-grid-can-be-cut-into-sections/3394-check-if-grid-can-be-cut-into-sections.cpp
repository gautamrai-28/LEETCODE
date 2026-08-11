class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        int n = intervals.size();

        ans.push_back(intervals[0]);
        int i = 1;
        while(i<n) {
            if(intervals[i][0] < ans.back()[1]) {
                //ans.back()[0] = min(intervals[i][0], ans.back()[0]);//no need of this line as intervals are already sorted with respect of first value of current interval;
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }

        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        //x-axis coordinates
        vector<vector<int>>hor;

        //y-axis coordinates
        vector<vector<int>>vert;

        for(auto &coord : rectangles) {
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];

            hor.push_back({x1,x2});
            vert.push_back({y1,y2});
        }

        vector<vector<int>> result1 = merge(hor);
        if(result1.size()>=3) return true;

        vector<vector<int>> result2 = merge(vert);
        return result2.size() >= 3;
    }
};