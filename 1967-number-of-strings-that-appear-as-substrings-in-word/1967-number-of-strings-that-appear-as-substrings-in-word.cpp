class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for(string st : patterns) {
            if(word.contains(st)) 
              count++;
        }

        return count;
    }
};