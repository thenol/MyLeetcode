'''
[medium]

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''

# version 1: O(n^2)
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:return 0
        f=[1]*len(nums)
        for i in range(1,len(nums)):# Note the state transition, f(0-(i-1)) -> f(i)
            for j in range(i):
                if nums[j]<nums[i]:
                    f[i]=max(f[i],f[j]+1)
        return max(f)