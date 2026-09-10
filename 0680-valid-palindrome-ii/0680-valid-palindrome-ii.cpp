class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return isPalindrome(s,start+1,end) || isPalindrome(s,start,end-1);
            }
            start++;
            end--;
        }
        return 1;
    }
};