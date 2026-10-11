class Solution {
private:
    int findSquare(int number){
        int ans = 0;
        while(number > 0){
            int rem = number % 10;
            ans += rem*rem;
            number /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = findSquare(slow);//moves single step
            fast = findSquare(findSquare(fast));//moves two step
        }while(slow != fast);

        if(slow == 1){
            return true;
        }else{
            return false;
        }
    }
};