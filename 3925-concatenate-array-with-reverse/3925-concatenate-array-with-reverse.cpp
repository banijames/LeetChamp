class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans = nums;
        int start = 0;
        int end =  ans.size()-1;
        while(start<end){
            swap(ans[start],ans[end]);
            start++;
            end--;
        }
        for(int i=0; i<ans.size(); i++){
            nums.push_back(ans[i]);
        }
        return nums;
        
    }
};