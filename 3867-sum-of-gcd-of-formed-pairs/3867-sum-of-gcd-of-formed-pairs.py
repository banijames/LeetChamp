import math
class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        prefix_gcd = []
        current_max = -1
        
        # Step 1: Build the prefixGcd array using the maximum seen so far
        for x in nums:
            current_max = max(current_max, x)
            prefix_gcd.append(math.gcd(x, current_max))
            
        # Step 2: Sort the prefixGcd values in non-decreasing order
        prefix_gcd.sort()
        
        # Step 3: Form pairs from outside-in (smallest with largest)
        # Using two pointers matches the logic and automatically ignores 
        # the middle element if n is odd.
        total_gcd_sum = 0
        left = 0
        right = n - 1
        
        while left < right:
            total_gcd_sum += math.gcd(prefix_gcd[left], prefix_gcd[right])
            left += 1
            right -= 1
            
        return total_gcd_sum