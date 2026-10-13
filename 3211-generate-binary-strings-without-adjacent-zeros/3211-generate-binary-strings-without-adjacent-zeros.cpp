class Solution {
private:
void consequtive(string str, int n, vector<string> &ans){
    if(str.size()==n){
        ans.push_back(str);
        return;
    }
    str.push_back('1');
    consequtive(str,n,ans);
    str.pop_back();

    if(str.size()==0 || str[str.size()-1]!= '0'){
        str.push_back('0');
        consequtive(str,n,ans);
        str.pop_back();
    }
       
}
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string str = "";
        consequtive(str,n,ans);
        return ans;
    }
};