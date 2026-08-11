class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end()); // Array MUST be sorted
    vector<vector<int>> result;

    for (int i = 0; i < (int)nums.size() - 2; i++) {
        // Skip duplicate values for 'i' to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum == 0) {
                result.push_back({nums[i], nums[j], nums[k]});
                
                // Skip duplicates for 'j' and 'k'
                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;

                j++;
                k--;
            } 
            else if (sum < 0) {
                j++; // Sum too small -> move left pointer right
            } 
            else {
                k--; // Sum too large -> move right pointer left
            }
        }
    }
    return result;
    }
};