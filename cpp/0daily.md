# basic problem
## recur 递归
## double while 双循环
## digit problem 数位问题
## swap 交换
## binary search 二分搜索

## 06/29 **Day 1**  **栈与队列（简单）**
1. 剑指 Offer 09. 用两个栈实现队列
2. 剑指 Offer 30.  包含 min 函数的栈

## 06/30 **Day 2** **链表（简单）**  
1. 剑指 Offer 06. 从尾到头打印链表
2. 剑指 Offer 24. 反转链表
剪断，反指，一起前进
3. 剑指 Offer 35. 复杂链表的复制

## 7/01 **Day 3**  **字符串（简单）**
1. 剑指 Offer 05. 替换空格
2. 剑指 Offer 58 - II. 左旋转字符串

# binary search
* Goal: binary search

* detail
双闭区间
m = (i + j)/2  --> optimize item: m = i + (j - i) / 2
update mechanism: i=m+1 j=m-1

* scenario
二分查找仅适用于有序数据
二分查找仅适用于数组(二维)

* extension
二分查找边界,left/right
二维

```c++ implement
int binary_search(const std::vector<int>& arr, int target) {
    /// initinazation
    int low = 0;
    int high = arr.size() - 1;

    /// dynamics update, low high mid
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
```

## 7/02 **Day 4**  **查找算法（简单）** 

1. 剑指 Offer 03. 数组中重复的数字
`哈希查找`

2. 剑指 Offer 53 - I. 在排序数组中查找数字出现的次数
`二分查找边界` https://www.hello-algo.com/chapter_searching/binary_search_edge/#1022

3. 剑指 Offer 53 - II. 0～n-1 中缺失的数字
`二分查找`
* the target we donnot know, alse we can declare the target is dynamics/changable

## 7/03 **Day 5**  **查找算法（中等）**
1. 剑指 Offer 04. 二维数组中的查找
`二分查找`
two dimension

2. 剑指 Offer 11. 旋转数组的最小数字
`二分查找`
* the update method of left and right pointer is different to standard binary search method.
* the target we donnot know, alse we can declare the target is dynamics/changable

3. 剑指 Offer 50. 第一个只出现一次的字符
`哈希查找`
* `重复 VS 第一次出现`, these two concept is same
* dic[c] = dic.find(c) == dic.end(); // 第一个出现,marked as "true"
* while we use `return` in the if condition among for loop, the `return` have the function of `break`

# 二叉树+递归/栈+DFS+回溯+剪枝 | BFS+队列
https://labuladong.github.io/algo/di-ling-zh-bfe1b/dong-ge-da-334dd/
快速排序就是个二叉树的前序遍历，归并排序就是个二叉树的后序遍历
https://www.hello-algo.com/chapter_tree/binary_tree_traversal/#_4

## 7/04 **Day 6**   **搜索与回溯算法（简单）**
1. 剑指 Offer 32 - I. 从上到下打印二叉树
visit the root,then push the left sub and the right sub to the queue, loop to vist this queue, then this tree will be traversal
   * 怎么层遍，把所有节点，按一定顺序放在队列中，取队列头，把它的值遍历一遍
               TreeNode *node = que.front();
               que.pop();
               res.push_back(node->val);

   * 那怎么把二叉树节点放在队列中呢，把头放在队列，再从左到右把子树放在队列
     que.push(root);
2. 剑指 Offer 32 - II. 从上到下打印二叉树 II
  * 需要解决的问题，怎么知道二叉树每层的元素个数
  * 关键点，`双层循环`（给你什么提示，你知道这道题怎么做）
  * for loop, https://www.programiz.com/cpp-programming/for-loop
  * while visit the value of the layer,the queue will store all nodes of next layer. (visit the former layer and store the next layer nodes in queue)

3. 剑指 Offer 32 - III. 从上到下打印二叉树 III
   * 双端队列 deque

## 7/05 **Day 7**   **搜索与回溯算法（简单）** 
1. 剑指 Offer 26. 树的子结构 --> ????
    
2. 剑指 Offer 27. 二叉树的镜像
    * swap left and right node
    * `swap(node->left,node->right)` instead of `res.push_back(node->val)`
3. 剑指 Offer 28. 对称的二叉树
    * end condition --> conditions for recur end 
    if(condition) return
    * return --> bool
    * recur function parameter
    * 1 recur call 2 recur base

## 7/19  **Day 14**  **搜索与回溯算法（中等）**
1. 剑指 Offer 12. 矩阵中的路径
* `size()` `< size()` VS `size()-1` `<=size()-1`
2. 剑指 Offer 13. 机器人的运动范围
* combination problem: DigitSum  --> (i + 1) % 10 != 0 ? si + 1 : si - 8
    * recur parameter: i j si sj
    * recur return value: int
    * recur end condition(if-return): if(i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
    * matrix boundary i >= m || j >= n 
```c++
int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
```

## 7/21 **Day 15** **搜索与回溯算法（中等）**
1. 剑指 Offer 34. 二叉树中和为某一值的路径
* 二叉树遍历 前序 后序
* 前序遍历(cpp/dfs_tree.cpp) --> 前序遍历搜索路径 --> 二叉树中和为某一值的路径
* recur parameter: target
* recur end condtion
* 记录解 if no return
* private memeber: define `path` to add or substract, define `result` to store if the condition is satified

## 7/24
2. 剑指 Offer 36. 二叉搜索树与双向链表
* 二叉树中序遍历 <--> 二叉搜索树
* DoublyList
`3 steps`   
 pre-->cur
 pre<--cur
 pre=pre->next
        pre->next = cur;
        cur->prev = pre;
        pre = cur;


3. 剑指 Offer 54. 二叉搜索树的第 k 大节点
* 二叉树中序遍历 <--> 二叉搜索树
* if (--k == 0)


# 动态规划

## 7/12 **Day 8**   **动态规划（简单）**
1. 剑指 Offer 10- I. 斐波那契数列
di gui `pre`+`cur`
2. 剑指 Offer 10- II. 青蛙跳台阶问题
3. 剑指 Offer 63. 股票的最大利润
    * https://medium.com/@ganeshprasad227/best-time-to-buy-and-sell-stock-1-only-one-stock-allowed-python-cpp-coding-interview-b2a8856b1fc4
    * 递归求较小
    * 更新较大差

## 7/13 **Day 9**   **动态规划（中等）**
1. 剑指 Offer 42. 连续子数组的最大和
2. 剑指 Offer 47. 礼物的最大价值
    * https://www.hello-algo.com/chapter_dynamic_programming/dp_solution_pipeline/#1335
    * 二维, 求最值
    * the ralation with 股票的最大利润
    * boundry condition: 二维

## 7/14 **Day 10**  **动态规划（中等）**   
1. 剑指 Offer 46. 把数字翻译成字符串
    * DP transfer equation with condition .different condition, 
    different DP transfer equation 
    * code structure same as 斐波那契数列
2. 剑指 Offer 48. 最长不含重复字符的子字符串
    * unordered_map 的使用方法： find ,判断元素在不在hash_map中

# 双指针

## 7/16  **Day 11**  **双指针（简单）** 
1. 剑指 Offer 18. 删除链表的节点
    * how to delete one node in the linked.pre->next = cur->next; 
    * broundy condition about the linked, is the head?, is the tail?
    * how to traverse the link

2. 剑指 Offer 22. 链表中倒数第 k 个节点
    * abstract the distance between with `pre` and `cur`, the distance is not constantly 1
    * while loop condition
    * we want to design a double pointer model, the distance `cur` pointer advance `pre` pointer is K,
    while `cur` arrive the end of the linked, the distance between `pre` to the end is K

##  7/17 **Day 12**  **双指针（简单）** 
1. 剑指 Offer 25. 合并两个排序的链表
* 当你需要创造一条新链表的时候，可以使用虚拟头结点简化边界情况的处理。
* core: cur->next=l1 or cur->next=l2; then walk through (merge)
* create dummy node;these two linked all have value, we can compare the value, execute choose l1 or l2 value; after choose ,make the linked walk; if one exhausted. execute boundry condtion ;
2. 剑指 Offer 52. 两个链表的第一个公共节点
* A+ B = B+ A
* p1 =A,if A is exhausted,p1=B

## 7/18 **Day 13**  **双指针（简单）**
1. 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
* quick sort 中交换的metric, 以大小为metric，以奇偶为metric, pivot one time, quick sort need recur
* double while loop template

2. 剑指 Offer 57. 和为 s 的两个数字

3. 剑指 Offer 58 - I. 翻转单词顺序

## 7/25 **Day 16**  **排序（简单）**  
1. 剑指 Offer 45. 把数组排成最小的数
* 通常情况下，std::sort使用的是快速排序（QuickSort）算法或者是归并排序（MergeSort）算法。这两种算法都属于基于比较的排序算法，并且具有较好的平均时间复杂度。
* 直接在快速排序算法里，修改排序判断规则 为：当 AB < BA , A>B
* 类似于修改快排的sort metric，可以使用系统函数std::sort，运用 lambda expression，自定义比较函数来指定排序顺序

1. 剑指 Offer 61. 扑克牌中的顺子
* list all situations
    - 大小王
    - 重复
* sort while include specific value
    - use `continue` to skip specific value

## 8/09 **Day 17**  **排序（中等）**
1. 剑指 Offer 40. 最小的 k 个数
   * deep understood of quick sort
   * return the recursive function

2. 剑指 Offer 41. 数据流中的中位数
   * 怎么动态的把数据分到两个容器，其中较大的在一个，较小的在另一个
   * 排序有很多子问题，全部有序是一种，现在是要求，要得到较大容器中的最小值，和较小容器中的最大值
   * design two priority queue
   * A保存较大的一半, B保存较小的一半

## 8/11 **Day 18**  **搜索与回溯算法（中等）** 
1. 剑指 Offer 55 - I. 二叉树的深度
   `BFS`
   * 涉及到分层的题目，最常见的做法是while 循环里再嵌套一个 for 循环 --> it is a solution for specific question
   * 之前常见的bfs套路是先进入根节点指针然后while循环只要que不为空就一直循环，先front记录再pop出根节点指针，然后下面再根据其左右节点是否存在来进入其左右节点的指针，但这样有个问题就是que队列里可能会既有上一层的结点又有下一层的结点，所以这里很巧妙的引入了tmp队列，把左右子节点指针存到tmp里，这样就避免了父子节点指针在同一个que队列里。而把tmp赋值给que，然后新的一层循环初始化tmp这一迭代的设定则是保证tmp里是同一层节点的关键。而且本题因为没有出队操作，所以还要有一个for循环来处理，这里是增强型for循环，如果选容器适配器queue就麻烦了，因为queue没有迭代器，不能顺序访问，没法采用增强型 for 循环。
   * relationship with 06-32tree_b 
   
   `BFS`
   * return int for recur in DFS solution，递归终止条件，指的是递归树的最低端，但不代表最终结果是在执行递归终止时执行，递归最终结果，是在递归过程中，"归"这个步骤
  

2. 剑指 Offer 55 - II. 平衡二叉树


## 8/15 **Day 19** | **搜索与回溯算法（中等）
1. 剑指 Offer 64. 求 1 + 2 + … + n
2. 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
3. 剑指 Offer 68 - II. 二叉树的最近公共祖先

## 8/17 **Day 20**  **分治算法（中等）
1. 剑指 Offer 07. 重建二叉树
2. 剑指 Offer 16. 数值的整数次方
3. 剑指 Offer 33. 二叉搜索树的后序遍历序列

## 9/1 **Day 21**  **位运算（简单）**
1. 剑指 Offer 15. 二进制中 1 的个数
2. 剑指 Offer 65. 不用加减乘除做加法
异或
左移
https://iq.opengenus.org/addition-using-bitwise-operations/

**Day 22**  **位运算（中等）**
1. 剑指 Offer 56 - I. 数组中数字出现的次数
2. 剑指 Offer  56 - II. 数组中数字出现的次数 II

## 9/12 **Day 23**  **数学（简单）**
1. 剑指 Offer 39. 数组中出现次数超过一半的数字
- initialize candidate and the vote of the candidata
- iterate the vote pool,then start vote
    while the candidate is choosed, votes +1, else -1;`votes += num == x ? 1 : -1;`
    while votes equal 0; change other candidate

* `general solution` sort all elements , then choose the mid element of sorted array

2. 剑指 Offer 66. 构建乘积数组
* initiate vector 
```c++
    int n = 3;
  
    // Create a vector of size n with
    // all values as 10.
    vector<int> vect(n, 10);
```
* sum --> product --> product array output--> product array output, but exclude `a[i]`
```c++ product
    // Calculate the product of array elements
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
```
```c++ product array output
    // Calculate the product array output of array elements
    for (int i = 0; i < n; i++) {
        L[i] = L[i - 1] * arr[i-1];
    };
```
* reverse order --> boundery`j>=0`  index `R[j+1]`
* handle boundery condition equal to 1, `L[0]`,`R[len-1]`

## 9/26 **Day 24**  **数学（中等）**
1. 剑指 Offer 14- I. 剪绳子
2. 剑指 Offer 57 - II. 和为 s 的连续正数序列
滑动窗口

3. 剑指 Offer 62. 圆圈中最后剩下的数字
这是经典的约瑟夫问题
递推公式f(n, m) = (f(n-1, m) + m) % n
其中，f(1, m)等于0，因为只剩下一个数字时，它的索引肯定是0。
