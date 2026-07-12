class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        res=0
        curr_sum=0
        count=defaultdict(int)
        l=0
        for r in range(len(nums)):#adding r element to curr sum
            curr_sum+=nums[r]
            count[nums[r]]+=1
            #if our window size exceeds k, shrink it from left
            if r-l+1>k:
                count[nums[l]]-=1
                if count[nums[l]]==0:
                    count.pop(nums[l])
                curr_sum-=nums[l]#subtract the outgoing left element
                l+=1#shift left forward
            if len(count) == r-l+1==k:
                res=max(res,curr_sum)
        return res
