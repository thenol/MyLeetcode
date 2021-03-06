'''
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
'''


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p,q=m-1,n-1
        while p>=0 and q>=0:
            if nums1[p]>=nums2[q]:
                nums1[p+q+1]=nums1[p]
                p-=1
            else:
                nums1[p+q+1]=nums2[q]
                q-=1


        # importante step, think about it carefully
        if q>=0:
            for i in range(q,-1,-1):
                nums1[i]=nums2[i]
        
        