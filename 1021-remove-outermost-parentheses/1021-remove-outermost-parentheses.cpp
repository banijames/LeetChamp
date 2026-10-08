class Solution {
public:
    string removeOuterParentheses(string s) {
        //approach based on if an open paren then lvl++ else lvl--
        string res;//to store the result
        int lvl = 0;
        for(char c : s){//loop through the given string
            if(c=='('){
                if(lvl > 0)//find the initial matching string
                    res+=c;//store the opening paran to the res
                lvl++;//increment lvl
            }else{
                lvl--;//decrement
                if(lvl>0){
                    res+=c;
                }
            }
        }
        return res;   
    }
};