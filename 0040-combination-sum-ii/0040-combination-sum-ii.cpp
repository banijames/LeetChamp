class Solution {
private:
    void solve(vector<int>& candidates,int target,vector<int> &output,int index,vector<vector<int>>& ans){

        //target reached
        if(target==0){
            ans.push_back(output);
            return;
        }
        
        for(int i=index; i<candidates.size(); i++){
            //skip duplicate
            if(i>index && candidates[i]==candidates[i-1]) continue;
            //combination found
            if(candidates[i]>target) break;

            output.push_back(candidates[i]);
            solve(candidates,target-candidates[i],output,i+1,ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates,target,output,0,ans);
        return ans;
    }
};