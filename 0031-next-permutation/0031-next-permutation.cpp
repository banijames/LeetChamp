class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp = -1;
        for(int i=nums.size()-2; i>=0; i--){
            //check for condition where arr[i]<arr[i+1]
            if(nums[i]<nums[i+1]){
                temp = i;
                break;
            }
        }
        //if all are in backward increasing order then sort and return 
        if(temp==-1){
            return sort(nums.begin(),nums.end());
        }

        for(int i=nums.size()-1; i>=temp; i--){
            if(nums[i]>nums[temp]){
                swap(nums[i],nums[temp]);
                break;
            }
        }
        sort(nums.begin()+temp+1, nums.end());
    }
};