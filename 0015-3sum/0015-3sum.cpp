class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());
       //running through the 1st 3 in order to avoid duplicate
        vector<vector<int>> result;
        //skip duplicates
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int s = i+1;
            int e = nums.size()-1;
            while(s<e){
                int sum = nums[i]+nums[s]+nums[e];

                if(sum==0){
                    result.push_back({nums[i],nums[s],nums[e]});
                
                    //skip duplicates of s and e
                    while(s<e && nums[s]==nums[s+1]) s++;
                
                    while(s<e && nums[e]==nums[e-1]) e--; 
                    //move pointers inward
                    s++;
                    e--;
                    
                }else if(sum<0){
                    s++;
                }else{
                    e--;
                }
            }
        }
        return result;
    }
};