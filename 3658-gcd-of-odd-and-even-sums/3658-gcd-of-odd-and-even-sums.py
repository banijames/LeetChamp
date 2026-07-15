class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        sumOdd=0
        sumEven=0
        for i in range(1,n+1):
            sumOdd+=i*2
            sumEven+=(i*2)-1
        gcd=(sumOdd//n,sumEven//n)
        return min(gcd)