class Solution {
public:
    int gcd(int n, int m) {
        if(m == 0) 
          return n;
        
        return gcd(m, n%m);
    }
    int gcdOfOddEvenSums(int n) {
        int a = n*n;
        int b = n * (n+1);

        return gcd(a,b);
    }
};