class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        current_sum = 0
        prefix_sums = defaultdict(int)
        prefix_sums[0] = 1

        for num in nums:     # [1, 1, 1] K=2
            current_sum += num     # 1, 2, 3 
            if(current_sum - k) in prefix_sums:
                count += prefix_sums[current_sum - k]
            prefix_sums[current_sum] += 1     # {0:1, 1:1, 2:1, 3:1}

        return count


