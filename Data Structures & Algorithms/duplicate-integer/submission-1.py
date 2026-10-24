class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        freq = defaultdict(int)

        flag = False

        for i in nums:
            freq[i] += 1
        
        for key, value in freq.items():
            if value > 1:
                flag = True
        return flag
