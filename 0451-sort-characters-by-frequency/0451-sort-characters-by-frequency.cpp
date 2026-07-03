class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(char ch : s)
            freq[ch]++;

        vector<pair<int, char>> arr;

        for(auto &it : freq)
            arr.push_back({it.second, it.first});

        sort(arr.begin(), arr.end(), greater<pair<int, char>>());

        string ans = "";

        for(auto &it : arr) {
            ans.append(it.first, it.second);
        }

        return ans;
    }
};