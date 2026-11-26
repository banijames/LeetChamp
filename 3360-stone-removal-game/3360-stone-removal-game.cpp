class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;

        bool t = false;
        int pile = 10;

        while(n>=pile){
            n -= pile--;
            t ^= true;
        }
        return t;
    }
};