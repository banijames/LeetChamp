class Solution {
private:
    void solve(vector<int> &candidates, int target, vector<int> output, int sum,int index, vector<vector<int>>&ans){
        //base case
        if(index>=candidates.size() || target<0) return;

        //found combinations
        if(sum==target){
            ans.push_back(output);
            return;
        }
         //main part 
        if(sum+candidates[index]<=target){
            output.push_back(candidates[index]);
            solve(candidates,target,output,sum+candidates[index],index,ans);
            output.pop_back();
        }
        solve(candidates,target,output,sum,index+1,ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(candidates,target,output,0,index,ans);
        return ans;
    }
};