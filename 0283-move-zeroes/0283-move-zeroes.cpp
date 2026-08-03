class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;//checks for the non zero element

        for(int i = 0; i<nums.size(); i++){//scans through entire array
            if(nums[i]!=0){
                //swap slow and non zero
                swap(nums[slow],nums[i]);
                //forwards slow
                slow++;
            }

        }

    }
};