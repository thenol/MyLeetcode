'''
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        while n!=0 and n&1==0:
            n>>=1
        if n==1:
            return True
        else:
            return False

