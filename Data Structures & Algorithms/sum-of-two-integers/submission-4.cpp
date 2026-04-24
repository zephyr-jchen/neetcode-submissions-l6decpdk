class Solution {
public:
    int getSum(int a, int b) {
        // 如果 b 一开始就是 0，直接返回 a
        while(b){
            int carry = (unsigned int)(a&b)<<1; //1&1 = 1 otherwise 0
            a =  a^b; //xor 不带进位的加法
            b = carry;
        }
        return a;
    }
};
