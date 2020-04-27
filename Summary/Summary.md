## Remember Normal Framework of Algorithm

#### 1. Recursive
* Backtrack __(DFS)__
    * Demo:
     ```python
        class Solution:
            def permuteUnique(self, nums: List[int]) -> List[List[int]]:
                res=[]
                def dfs(nums,path):
                    if not nums:
                        res.append(path)
                    else:
                        last='' # use last to remember variable just selected
                        for i in range(len(nums)):
                            if not nums[i]==last: # skip the variable just selected
                                dfs(nums[:i]+nums[i+1:],path+[nums[i]])
                                last=nums[i]

                dfs(sorted(nums),[]) # Deduplication, sorted()
                return res
     ```
    * Scenarios:
        * Problems related to path
        * __Enumeration__
    * Features:
        * __set enumeration__

#### 2. Dynamic Programming
* __Condition__:
    * Optimal substructure
    * Overlapping sub-problems
* __Implementation__:
    * This can be achieved in either of two ways:
        * __*Top-down approach*__: This is the direct fall-out of the recursive formulation of any problem. If the solution to any problem can be formulated recursively using the solution to its sub-problems, and if its sub-problems are overlapping, then one can easily memoize or store the solutions to the sub-problems in a table. Whenever we attempt to solve a new sub-problem, we first check the table to see if it is already solved. If a solution has been recorded, we can use it directly, otherwise we solve the sub-problem and add its solution to the table.
        * __*Bottom-up approach*__: Once we formulate the solution to a problem recursively as in terms of its sub-problems, we can try reformulating the problem in a bottom-up fashion: try solving the sub-problems first and use their solutions to build-on and arrive at solutions to bigger sub-problems. This is also usually done in a tabular form by iteratively generating solutions to bigger and bigger sub-problems by using the solutions to small sub-problems. For example, if we already know the values of F41 and F40, we can directly calculate the value of F42.
    
* The __*core*__ of dynamic programming: __*recursive formulas (i.e. the transfer of state equations), then fill in the state table*__
    * Therefore, you must know exactly what the state means in the equation, e.g. the meaning of $(i,j)$
    * Dimensionality reduction
* Differences from "divide and conquer":
    * There are two key attributes that a problem must have in order for dynamic programming to be applicable: optimal substructure and overlapping sub-problems. If a problem can be solved by combining optimal solutions to non-overlapping sub-problems, the strategy is called "divide and conquer" instead.[1] This is why merge sort and quick sort are not classified as dynamic programming problems
* __Procedure__:
    * Determine the state
        * Accurately identify each state and make sense
            * e.g. the share problem
            ```python
            for 状态1 in 状态1的所有取值：
                for 状态2 in 状态2的所有取值：
                    for ...
                        dp[状态1][状态2][...] = 择优(选择1，选择2...)
            
            每天都有三种「选择」：买入、卖出、无操作，我们用 buy, sell, rest 表示这三种选择。但问题是，并不是每天都可以任意选择这三种选择的，因为 sell 必须在 buy 之后，buy 必须在 sell 之后。那么 rest 操作还应该分两种状态，一种是 buy 之后的 rest（持有了股票），一种是 sell 之后的 rest（没有持有股票）。而且别忘了，我们还有交易次数 k 的限制，就是说你 buy 还只能在 k > 0 的前提下操作

        
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
                          max(   选择 rest  ,           选择 sell      )

            解释：今天我没有持有股票，有两种可能：
            要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
            要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
                          max(   选择 rest  ,           选择 buy         )

            解释：今天我持有着股票，有两种可能：
            要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
            要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。

            作者：labuladong
            链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/
            来源：力扣（LeetCode）
            著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
            ```
        * Always pay attention to the __factors__, which are usually the dimension of the array(table) and come from condition
        * The last step (optimal coin combination:(2,5,7)->27, $a_k$)
        * Translate into subproblems (27-$a_k$)
        * Note the state collision

    * __State transition equation__
        * __It is the process of breaking a big problem into sub-problems__
        * __The essence is to avoid calculating the value of overlapping sub-problems, which occurs in conventional recursive solving methods. The strategy is to record the value of overlapping sub-problems.__
        * __$F[x]=min\{F[x-2]+1,F[x-5]+1,F[x-7]+1\}$__
        * __$f(x)=min\{f(x-2)+1,f(x-5)+1,f(x-7)+1\}$__
        * __$x$ acutually is the parameter of the function $f$__.
        * __Hence, $dp[a][b]$ can be regarded as the function $f(a,b)$__
    * Initial condition and the boundary condition
        * $F[0]=0, the\;F[y]=+INF$ if it cannot be combined by $y$
        * Note that initialization (i.e. the way to fill in the table) depends on the state transition equation
            * For example, check whether a string is palindrome
            ```java
                boolean[][] dp = new boolean[s.length()][s.length()];
                int length = s.length();
                //考虑所有长度的子串
                for (int len = 1; len <= length; len++) {
                    //从每个下标开始
                    for (int i = 0; i <= s.length() - len; i++) {
                        int j = i + len - 1; // i and j change synchronously
                        dp[i][j] = s.charAt(i) == s.charAt(j) && (len < 3 || dp[i + 1][j - 1]);
                    }
                }

                作者：windliang
                链接：https://leetcode-cn.com/problems/palindrome-partitioning/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-3-7/
                来源：力扣（LeetCode）
                著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
            ```
            <img src='./resources/fill.png'>
        * 

    * The calculation order:
        * $F[0], F[1], F[2]...$
    * 5 easy steps:
        <img src='./resources/dp.png'>
* __Scenarios__
    * optimal value
    * count problem
    * exist or not

* __Classical Problems__
    * sub sequenece problems
        <img src='./resources/ss.png'>
    * knapsack
    * edit distances
    * 


* __Types__:
    * __Digit DP__
        * <a href='https://blog.csdn.net/wust_zzwh/article/details/52100392?depth_1-utm_source=distribute.pc_relevant.none-task-blog-OPENSEARCH-3&utm_source=distribute.pc_relevant.none-task-blog-OPENSEARCH-3'>csdn blog</a>
        * <a href="https://www.bilibili.com/video/BV1Fc411h76q?from=search&seid=8872914714857826356">Video tutorial</a>
    * __Probability DP__

    
* __Summary__:
    * Note the form of the equation when two or more objects are involved, where the equation must contain pointers that can represent each object individually
    * Most recursion can be rewritten with the idea of dynamic programming
* __References__:
    * https://en.wikipedia.org/wiki/Dynamic_programming


#### 3. The theory of Graph

* __BFS__

* __DFS__
    


#### 4. Search

#### 5. Iteration

#### 6. Number Theory
* Prime numbers
* 


#### 7. Data structure
* __LinkNode__
    * Reverse: 
        * Head insertion $O(N)$

#### 8. Special data structure
* Monotonic queue & stack
    * Features:
        * The elements of the stucture is monotonic
    * monotonic queue:
        * The essence is to get optimal value of previous $k-length$ interval in $O(1)$
        * E.g.: <a href='https://leetcode-cn.com/problems/sliding-window-maximum/'>239.Sliding Window Maximum</a>

    * monotonic stack:
        * The essence is to get the value less than or greater than the current element in $O(n)$
        * E.g.: Find the next person taller than you
#### 9. Double pointer
* Demo: $Leetcode_{209}$
* Control one pointer:
```python
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l = total = 0
        ans = len(nums) + 1
        for r in range(len(nums)):
            total += nums[r]
            while total >= s:
                ans = min(ans, r - l + 1)
                total -= nums[l]
                l += 1
        return  0 if ans == len(nums) + 1 else ans
```
* Control two pointers:
```python
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        le=sm=l=r=0
        N=len(nums)
        mn=N+1
        while r<N or sm>=s:# loop ending: r==N && sm<s 
            if sm<s:
                sm+=nums[r]
                r+=1
                le+=1
            else:
                mn=min(mn,le)
                sm-=nums[l]
                l+=1
                le-=1
        # print(nums[l],nums[r-1],sm)
        if sm>=s:
            mn=min(mn,le)
        if mn==N+1:
            mn=0
        return mn
```
#### Notice
* Never pursue the complexity of control logic
* On the other hand, simple, efficient and easy to understand is the ultimate goal of coding


#### Appendix:
* The **Merge** type:
    * by a group of two
    * divid and conquer

* Linked list operation:
    * Note the head insertion and tail insertion
    * Note the importance of Head Node


* __Sorting__ is sometimes useful

* Note the mechanism of signal variables in control logic

* The characteristics of the Algorithm:
    * An important technique for proving the finiteness and correctness of an algorithm is to look at the entire calculation process from an appropriate perspective and discover some of its __**invariance**__ and __**monotonicity**__.
* __xor__ operator:
    * Carryless addition: 
    ```c
    0 xor 0=0+0=0, 0 xor 1=0+1=1
    0 xor 1=0+1=1, 1 xor 0=1+0=1
    1 xor 0=1+0=1, 1 xor 1=1+1=0
    1 xor 1=1+1=0
    ```
* __Polynomial__:
    * e.g. $P171:\;'AB'->28$

        A|B|C|result
        -|-|-|-
        $1*26^2$|$2*26^1$|$3*26^0$|$\sum$

* __Loop check__:
    * Freud cycle search algorithm：
        * The core idea of ​​the algorithm is to start a double pointer, just like a rabbit game that catches turtles. If they walk in a loop at different speeds, they will definitely be able to meet in the future.
        

* __Common Error__:
    * Note the return in the recursive function
    * Note the dynamic length of the dynamically changing stack or queue
    * Note that the results are correct if and only if every step in the coding is correct
    * Comprehand the code by looking at the key logic


    
    
    