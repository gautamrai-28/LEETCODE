class Solution {
public:
    typedef pair<int,int>P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        unordered_map<int,int>mpp;

        //1. store freq
        for(int num : nums) 
           mpp[num]++;
        

        for(auto &it : mpp) {
            int value = it.first;
            int freq = it.second;
            
            //2.push it into min heap acc to freq of element
            pq.push({freq,value});

            //3.maintain k size pq only
            if(pq.size()>k) 
              pq.pop();
        }

        //4.store it in ans 
        vector<int>ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};