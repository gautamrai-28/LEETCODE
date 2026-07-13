class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s = "123456789";
        int l = 0;

        while(l<s.size()) {
            int r = l+1;

            while(r<s.size()) {
                int temp = stoi(s.substr(l, r-l+1));

                if(temp >= low && temp <= high) 
                   ans.push_back(temp);
                
                r++;
            }
            l++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};