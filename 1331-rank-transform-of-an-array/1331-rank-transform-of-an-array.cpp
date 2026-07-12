class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> temp = arr;

        sort(arr.begin(), arr.end());

        unordered_map<int, int> rank;
        int currRank = 1;

        for (int i = 0; i < n; i++) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                rank[arr[i]] = currRank;
                currRank++;
            }
        }

        for (int i = 0; i < n; i++) {
            temp[i] = rank[temp[i]];
        }

        return temp;
    }
};