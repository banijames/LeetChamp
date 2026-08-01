class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            int targetIndex= abs(nums[i])-1;

            if(nums[targetIndex]<0){
                result.push_back(abs(nums[i]));
            }
            else{
                nums[targetIndex]= -nums[targetIndex];
            }
        }
        return result;
    }
};