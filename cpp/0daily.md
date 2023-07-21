# basic problem
## recur
## double while
## digit problem
## swap
## binary search

## 06/29 **Day 1**  **栈与队列（简单）**
1. 剑指 Offer 09. 用两个栈实现队列
2. 剑指 Offer 30.  包含 min 函数的栈

## 06/30 **Day 2** **链表（简单）**  
1. 剑指 Offer 06. 从尾到头打印链表
2. 剑指 Offer 24. 反转链表
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

# 动态规划

## 7/12 **Day 8**   **动态规划（简单）**
1. 剑指 Offer 10- I. 斐波那契数列
di gui `pre`+`cur`
2. 剑指 Offer 10- II. 青蛙跳台阶问题
3. 剑指 Offer 63. 股票的最大利润
    * https://medium.com/@ganeshprasad227/best-time-to-buy-and-sell-stock-1-only-one-stock-allowed-python-cpp-coding-interview-b2a8856b1fc4
    * di gui qiu jiao xiao
    * zai bi di zhi cha

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
