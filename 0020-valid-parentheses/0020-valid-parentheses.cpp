class Solution {
public:
    bool isValid(string s) {
        string var = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]== '{' || s[i]=='['){
                var.push_back(s[i]);
            }else if(var.size()==0 || (s[i]==')' && var[var.size()-1]!='(')){
                return false;
            }else if(var.size()==0 || (s[i]==']' && var[var.size()-1]!='[')){
                return false;
            }else if(var.size()==0  || (s[i]=='}' && var[var.size()-1]!='{')){
                return false;
            }else{
                var.pop_back();
            }
        }
        if(var.size()==0){
            return true;
        }else{
            return false;
        }
    }
};