class Solution {
public:
    bool isPalindrome(string &s) {
        int n = s.size();
        int i = 0, j = n -1;

        while(i<j) {
            if(s[i]!=s[j])
               return false;

            i++,j--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;

        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                string temp = s.substr(i, j-i+1);
                if(isPalindrome(temp))
                   count++;
            }
        }

        return count;
    }
};