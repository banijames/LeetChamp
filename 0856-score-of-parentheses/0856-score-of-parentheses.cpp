class Solution {
public:
    int scoreOfParentheses(string s) {
        int count = 0;
        int total = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]== '('){//checking for whether we can enter
                count++;//increments the value
            }else{
                count--;//no start or exiting
                if(s[i-1]=='('){
                    total += 1 << count;
                }
            }
        }
        return total;
    }
};