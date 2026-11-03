class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *max_element(nums.begin(),nums.end());
        int ans = 0;
        for(int i : nums){
            ans += mn-i;
        }
        return ans;
    }
};