class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;

        for(char ch : word) {
            if(isupper(ch))
               upperCount+=1;
        }


        return upperCount == word.size() || upperCount == 0 ||
                     (upperCount == 1 && isupper(word[0]));
    }
};