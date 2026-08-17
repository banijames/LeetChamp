class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map to store the frequency of prefix sums encountered
        std::unordered_map<int, int> prefixSumMap;
        
        // Base case: A prefix sum of 0 has occurred once (handles subarrays starting from index 0)
        prefixSumMap[0] = 1;
        
        int currentSum = 0;
        int totalSubarrays = 0;
        
        for (int num : nums) {
            // Update the running prefix sum
            currentSum += num;
            
            // Check if (currentSum - k) exists in our map
            int target = currentSum - k;
            if (prefixSumMap.find(target) != prefixSumMap.end()) {
                totalSubarrays += prefixSumMap[target];
            }
            
            // Record the current prefix sum in the map
            prefixSumMap[currentSum]++;
        }
        
        return totalSubarrays;
    }
    
};