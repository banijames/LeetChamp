class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s; // We store INDICES in the stack, not values
        
        // Loop twice (up to 2*n) to simulate the circular array
        for (int i = 0; i < 2 * n; i++) {
            int cyclicIndex = i % n;
            
            // While stack isn't empty and we found a strictly greater element
            while (!s.empty() && nums[s.top()] < nums[cyclicIndex]) {
                ans[s.top()] = nums[cyclicIndex];
                s.pop();
            }
            
            // Only push to the stack during the first pass (i < n)
            // The second pass is only used to resolve left-over items in the stack
            if (i < n) {
                s.push(i);
            }
        }
        
        return ans;
    }
};