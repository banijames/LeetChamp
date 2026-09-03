class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int left = 0;
        int current_product = 1;
        int max_count = 0;
        for(int right=0; right<nums.size(); right++){
            current_product*=nums[right];

            while(current_product>=k){
                current_product /= nums[left];//shrinks the size
                left++;
            }
            max_count +=right-left+1;
        }
        return max_count;
    }
};