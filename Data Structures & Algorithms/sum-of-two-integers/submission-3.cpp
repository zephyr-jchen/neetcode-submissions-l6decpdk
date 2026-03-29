class Solution {
public:
    int getSum(int a, int b) {
        // 如果 b 一开始就是 0，直接返回 a
        while(b){
            int sum = a^b;
            int carry = (unsigned int)(a&b)<<1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
