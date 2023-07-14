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

## binary search
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

## 二叉树
https://labuladong.github.io/algo/di-ling-zh-bfe1b/dong-ge-da-334dd/
https://www.hello-algo.com/chapter_tree/binary_tree_traversal/#_4

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

## 7/12
1. 剑指 Offer 10- I. 斐波那契数列
di gui `pre`+`cur`
2. 剑指 Offer 10- II. 青蛙跳台阶问题
3. 剑指 Offer 63. 股票的最大利润
    * di gui qiu jiao xiao
    * zai bi di zhi cha

## 7/13
1. 剑指 Offer 42. 连续子数组的最大和
2. 剑指 Offer 47. 礼物的最大价值
    * https://www.hello-algo.com/chapter_dynamic_programming/dp_solution_pipeline/#1335
    * 二维, 求最值
    * the ralation with 股票的最大利润
3. 剑指 Offer 46. 把数字翻译成字符串
    * DP transfer equation with condition .different condition, 
    different DP transfer equation 
    * code structure same as 斐波那契数列
4. 剑指 Offer 48. 最长不含重复字符的子字符串
/// unordered_map 的使用方法： find ,判断元素在不在hash_map中
/// 空间复杂度的优化
