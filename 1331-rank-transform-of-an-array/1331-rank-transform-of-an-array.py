class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        sorted_arr=sorted(set(arr))
        rank_map={}
        for i,num in enumerate(sorted_arr):
            rank_map[num]=i+1
        result=[]
        for num in arr:
            result.append(rank_map[num])
        return result