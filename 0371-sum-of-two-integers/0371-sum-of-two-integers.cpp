class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int carry = a & b;
            a = a^b;
            b=carry<<1;//left shift the carry
        }
        return a;
    }
};
//simple logic just we need to add until b is zero 
//a=1,b=2 -> 01 + 10 = 00
//a=11 b=00<<1 means just shifting the position of zero to left so 
//b becomes zero the ans is a 11-> 3