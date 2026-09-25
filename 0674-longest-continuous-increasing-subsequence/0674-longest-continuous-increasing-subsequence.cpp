class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int current = 1;
        int max_count = 1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                current++;
                max_count=max(max_count,current);
            }else{
                current = 1;
            }
        }
        return max_count;
    }
};