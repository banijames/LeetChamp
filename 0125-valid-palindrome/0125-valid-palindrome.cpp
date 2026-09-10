class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            //removing all special characters from left
            while(start<end && !isalnum(s[start])){
                start++;
            }
            //removing special characters from right
            while(start<end && !isalnum(s[end])){
                end--;
            }
            if(tolower(s[start++])!=tolower(s[end--])){
                return 0;
            }
        }
        return 1;
    }
};