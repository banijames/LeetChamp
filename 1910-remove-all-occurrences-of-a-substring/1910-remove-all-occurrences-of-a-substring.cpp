class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int partLen = part.length();
        for(char ch : s){
            result.push_back(ch);//add character to result
            if(result.length()>=partLen && 
               result.substr(result.length()-partLen)==part){
               result.erase(result.length() - partLen);
                
            }
        }
        return result;
    }
};