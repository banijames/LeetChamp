class Solution {
private:
    void solve(vector<int> &candidates, int target, vector<int> output,int index, vector<vector<int>>&ans){
        //target reached
        if(target==0){
            ans.push_back(output);
            return;
        }
        if(index>=candidates.size()) return;
        //main part 
        if(candidates[index]<=target){
            output.push_back(candidates[index]);
            solve(candidates,target-candidates[index],output,index,ans);
            output.pop_back();
        }
        solve(candidates,target,output,index+1,ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates,target,output,0,ans);
        return ans;
    }
};