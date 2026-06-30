class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0;
        int count = 0;

        unordered_map<char,int>chars;

        while(r<s.size()) {
            chars[s[r]]++;

            while(chars['a']>0 && chars['b']>0 && chars['c']>0){
                chars[s[l]]--;
                l++;
            }
            
            count += l;
            r++;
        }

        return count;
    }
};