class Solution {
private:
    void solve(string &ans, int start, int end){
        //base case
        if(start==end){
            return ;
        }
        string temp = "";
        int count = 1;
        for(int i=1; i<ans.length(); i++){
            if(ans[i-1]==ans[i]){
                count++;
            }else{
                temp += to_string(count)+ans[i-1];
                count = 1;
            }
        }
        temp += to_string(count) + ans.back();
        ans = temp;
        solve(ans,start+1,end);

    }
public:
    string countAndSay(int n) {
        string ans = "1";
        if(n==1) return "1";
        solve(ans,1,n);
        return ans;
    }
};