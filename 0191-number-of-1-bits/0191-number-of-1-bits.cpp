class Solution {
public:
    int hammingWeight(int n) {
        int setBits = 0;

        while(n!=0) {
            if(n%2 == 1) setBits++;

            n/=2;
        } 
        return setBits;
    }
};