class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0){return 0;}
        if(x == 1){return 1;}
        long power = abs((long(n)));
        double res = 1;
        double current_product = x;
        while(power){
            if(power & 1){
                res *= current_product;
            }
            current_product *= current_product;
            power >>= 1;
        }
        return n > 0 ? res:1/res;
    }
};
