class Solution {
public:
    long long reverse(int n) {
        long num = 0;

        while(n>0) {
            long digit = n%10;
            num = num*10 + digit;
            n = n/10;
        }

        return num;
    }
    long long sumAndMultiply(int n) {
        long num = 0;
        long sum = 0;

        while(n>0) {
            long digit = n%10;

            if(digit!=0) {
                sum+=digit;
                num = num*10 + digit;
            }
            n = n/10;
        }

        long reversedNum = reverse(num);

        return reversedNum*sum;
    }
};