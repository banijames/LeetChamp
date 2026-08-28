class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            //removing all special characters from left
            if(!isalnum(s[start])){
                start++;
            }
            //removing special characters from right
            else if(!isalnum(s[end])){
                end--;
            }
            else if(tolower(s[start++])!=tolower(s[end--])){
                return false;
            }
        }
        return true;
    }
};