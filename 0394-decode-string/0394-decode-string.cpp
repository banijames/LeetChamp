class Solution {
public:
    int i = 0;
    string decodeString(string s) {
        string res;
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i])) n = n * 10 + s[i++] - 48;
                i++;
                string t = decodeString(s);
                i++;
                while (n-- > 0)res += t;
            }
        }
        return res;
    }
};