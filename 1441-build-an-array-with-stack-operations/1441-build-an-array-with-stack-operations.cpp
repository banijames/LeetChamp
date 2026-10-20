class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        //stack<int> s; since the qs asks for vector of strings no need of actual stack
        vector<string>ans;
        //traverse through the target array
        int targetIndex = 0;
        for(int i=1; i<=n; i++){
            //target empty
            if(targetIndex>=target.size()){
                break;
            }
            ans.push_back("Push");
            //if target number matches the current number
            if(target[targetIndex]==i){
                targetIndex++;//increment to next value
            }else{
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};