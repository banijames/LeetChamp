class Solution {
public:
    bool isValid(string s) {
        string str = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                str.push_back(s[i]);
            }else if(str.length()==0 ||(s[i]==']' && str[str.length()-1]!='[')){
                return false;
            }else if(str.length()==0 || (s[i]=='}' && str[str.length()-1]!='{')){
                return false;
            }else if(str.length()==0 || (s[i]==')' && str[str.length()-1]!='(')){
                return false;
            }else{
                str.pop_back();
            }
        }
        if(str.length()==0){
            return true;
        }else{
            return false;
        }
    }
};