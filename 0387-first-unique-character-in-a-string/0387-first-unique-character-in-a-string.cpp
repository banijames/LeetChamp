class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;//traverse through the string and store the frequencies
        }
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]-'a']==1){//check for whether it has a frequency of one
                return i;
            }
        }
        return -1;
    }
};