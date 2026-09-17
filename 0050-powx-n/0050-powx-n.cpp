class Solution {
private:
    double help(double x , int n){
        if(x==0) return 0;
        if(x==1 || n==0) return 1;
        double halfPwr = help(x,n/2);
        if(n%2==0){
            return halfPwr*halfPwr;
        }else{
            return x*halfPwr*halfPwr;
            //if 2^9 2*2^4*2^4
        }
    }
public:
    double myPow(double x, int n) {
        bool neg=(n<0)?true:false;
        int pwr = n;
        
        double ans=help(x,pwr);
        if(neg) return 1/ans;//if power is negative then the required ans is 1/ans
        return ans;//
    }
};