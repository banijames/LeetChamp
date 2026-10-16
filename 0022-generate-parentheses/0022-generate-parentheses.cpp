class Solution {
private:
    void combinations(int n, string ways, vector<string> &ans, int opening, int closing){
        //base condition
        if(ways.size()>=n*2){
            ans.push_back(ways);
            return ;
        }
        //pushing opening
        if(opening < n){
            combinations(n,ways+'(',ans,opening+1,closing);
        }
        //pushing closing
        if(closing < n && closing+1 <= opening){
            combinations(n,ways+')',ans,opening,closing+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ways = "";
        combinations(n,ways,ans,0,0);
        return ans;
    }
};