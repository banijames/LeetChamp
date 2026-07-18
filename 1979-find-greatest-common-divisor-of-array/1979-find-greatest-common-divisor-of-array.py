import math
class Solution:
    def findGCD(self, nums: List[int]) -> int:
        smallest=min(nums)
        larget=max(nums)
        return math.gcd(smallest,larget)
