class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Map to store: {remainder -> earliest index where it occurred}
        std::unordered_map<int, int> remainderMap;
        
        // Base case: A remainder of 0 conceptually occurs at index -1
        // This handles valid subarrays that start exactly at index 0
        remainderMap[0] = -1;
        
        int runningSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            
            // Calculate remainder safely (handling k = 0 if constraints allowed, though k >= 1 here)
            int remainder = runningSum % k;
            
            // If the remainder has been seen before
            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Check if the subarray length is at least 2
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                // Only store the index the FIRST time you see the remainder
                // This keeps the stored index as small as possible to maximize subarray length
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};