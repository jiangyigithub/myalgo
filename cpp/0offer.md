# 剑指offer
[hello algorithm](https://www.hello-algo.com/chapter_computational_complexity/)
[illustration-of-algorithm](https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/55bvvv/)

## 面试 
  1. 剑指offer的NB之处在于提供了一个渐进的优化解法，面试的时候可以参考，不要急于给出最优解，一步一步先给出差的解，然后次优解，最优解，并且伴随分析的过程，这样既表现了自己的算法功底，又展示了自己的现场解决问题的能力，还拖延了时间，省的答完了人家又出一个，问到不熟练的问题。
  2. 边际成本，刷多少道，哪些题目要重点刷

## 认识
记忆和推理是人脑解决问题的两种方式，推理是空间复杂度低，时间复杂度高；但记忆是时间复杂度低，空间复杂度高。现实世界中往往对时间复杂度要求更高。
推理是思考方式像一棵树,而记忆则像哈希表

### 数据结构
* 优先队列和堆
* 双向链表
* 平衡二叉树
* 二叉搜索树

### 算法
- 二分搜索
- 回溯法（DFS）
- BFS
- 动态规划
- 分而治之
- 双指针
- 分治
- 递归

### 对称性
- DFS和BFS
- 顺序存储和链式存储
- 自下而上（循环） 自上而下（递归）
- 实践->量变->质变->认识->再实践

### 术
- 调试。循环结构和递归结构，断点法和log法，全局和细节

## 实践
### 1 数据结构
**offer 05替换空格**
1. core: `统计空格数量` + `改变容器的大小resize` + `倒序遍历` + `forward 2 step`
2. 循环的次数,(while i>=0)
3. C++ 中string是可变类型,以char'0'结尾,且空字符串大小也不为0;
4. similar to "reverse string"

**offer 06从尾到头打印链表**
1. 基础： 怎么遍历链表，栈数据入栈出栈
   `C++ stack的基本用法` ,`判空 empty`,`取栈头 top`,`压栈 pop`
   `遍历链表`

**offer 09用两个栈实现队列**
1. 删除操作，前一步是删除操作，前一步是添加操作
2. `while` 和 `if` 的差异和共同点

**剑指 Offer 20. 表示数值的字符串**
1. 状态机
2. 第一步，理清逻辑，设计状态机；第二步根据状态机图实现代码

**offer 24反转链表**
(双指针，循环断舍离)
1. 双指针 cur pre temp
2. 切断链表
3. 改变链表指针朝向
4. 等号左边是待写项，等号右边是读入项
```c++
pre= cur //pre将被改写，cur不会被改变
cur=cur->next //cur将被改写
```
5. 先备份，再写入
6. 双指针步进，先pre，后cur

**剑指 Offer 30. 包含 min 函数的栈**
- 对时间复杂度有额外需求,一般的思路是以空间换时间
- min stack为空时怎么处理
- python类的实例化

**offer 35复杂链表的复制**
1. 三步走
   - 复制各节点
   - 构建指针random的连接关系
   - 拆分链表,以构建指针next的连接关系
2. 复制指针指向时，如果指向的nullptr，可以跳过复制，因为初始化时，已初始化为nullptr了
3. 双指针用来拆分链表
4. 指针的步进，步进一步，步进两步

**offer 58-2左旋转字符串**
1. stl 区间为左开右闭
2. 旋转的原子操作是swap

**剑指 Offer 59 - I. 滑动窗口的最大值**
1. 优先级队列
- 优先级队列中元素为pair，i 与num[i]一对数据

2. 单调队列（通过deque来是实现）
- 按索引对应的数据排序，但可以只存索引，既可以找到对应的数据
- for deque, we can remove data from both front and back
- for deque, remove from back new inserted data is more larger
- for deque, remove from front if the window is sliding out 
- put the available max value in the front of deque
* add first element into deque
* condition remove, check whether the container is empty?
* i-k, the lenght of window is 3, while i =4,
* if the lenght of window equal to data pool size, return the result at the first loop
* the boundary condition the deque value is out of the range of window

  |
0 1 [2 3 4]
2 8 [5 6 7]

i=4
k=3
i-k
deque.front 1
nums[deque.front] 8



**剑指 Offer 59 - II. 队列的最大值**
- 对时间复杂度有额外需求,一般的思路是以空间换时间
- 维护一个单调的双端队列
- 对于普通队列，pop 和push操作没有特殊，需要做的是对deque设计特殊的pop,push,max_value操作
- 与`30题：包含 min 函数的栈`的联系

**剑指 Offer 67. 把字符串转换成整数**
- 状态机法

### 2 查找算法
**剑指 Offer 03. 数组中重复的数字**
方法1：哈希表 C++怎么模型元素是否再hash表中
- 次数为2次以内用<int,bool> ，大于2次可用<int,int>来统计
- 先做if判断，再做赋值操作

方法2： 交换 num[ num[ i]] 和num[ i]
- 先做if判断，再做交换操作

**剑指 Offer 04. 二维数组中的查找**
- 2分查找的矩阵形式，两维形象
- 2分查找怎么确定查找的起点，通过起点可以消除一半的搜索范围

**剑指 Offer 11. 旋转数组的最小数字**
- 二分查找，需要移动左边界或右边界来减少搜索范围
- 最右侧元素一定大于等于说要查找的元素
- 该题与最基础的二分查找的区别
- 应用if else三连，而非多个if
```python
def binary_search(arr, x):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (right + left) // 2
        if arr[mid] < x:
            left = mid + 1
        elif arr[mid] > x:
            right = mid - 1
        else:
            return mid
    return -1
```

**剑指 Offer 50. 第一个只出现一次的字符**
- 哈希表的初始化和再赋值，第一次字符即为哈希表的初始化过程，将哈希表中value初始化为true，再赋值即该key再出现的话，若其存在于哈希表，则将其value设为false，所以有序哈希表中第一个value为true所对应的key值即是题目中所求
- 对空间复杂度的优化，将记录次数的，value类型为int哈希表改为value类型为bool的哈希表
- 对时间复杂的优化，遍历string是跟string的长度相关的，而遍历哈希表，哈希表中的key数量的有限的,可以通过遍历哈希表来取代遍历字符串来降低时间复杂度
- 题目中要求是第一个出现，这就要求string 里第一个key对应的value是true的元素，因此需要有序字典，只有是有序字典，才能保证哈希表里的元素位置与其在string的位置对应

**剑指 Offer 53 - I. 在排序数组中查找数字 I**
- 哈希表 时间复杂度为O(n)
- 输入是有序的 --> 二分 
- 边界问题
  - 二分查找循环终止条件,left< right 还是left<= right
  - 左右指针更新的值，左边界更新为是mid,还是mid+1
  - 与target的比较，有没有等号，nums[mid]<=target

**剑指 Offer 53 - II. 0～n-1 中缺失的数字**
- 二分判断条件：nums[mid]==mid
- 边界问题
  - 二分查找循环终止条件,left< right 还是left<= right
  - 左右指针更新的值，是mid,还是mid+1

### 3 排序

**offer 40**

- 排序的基础操作是`交换`
- 快速排序和二份查找之间的联系

**offer 41**

- 优先队列

**offer 45**

- 重新定义数据大小的metric

**offer 61**

### 4 双指针
- 一般应用于数组，链表，字符串的题目
- 逆向双指针，数组首尾节点
- 同向双指针，链表相邻节点

**offer 18**

- 链表 头节点，尾节点的特殊情况

- 链表的遍历（单指针和双指针）

- 链表的删除操作 pre->next = cur->next;


- 链表的表示方法只用head就可以表示一个链表， （字符串和数值， 只用指针表示）

**offer 21**

- quick sort 中交换的metric, 以大小为metric，以奇偶为metric

**offer 22**

- 链表查找和链表size的关系

**offer 25**

- 链表成员val的赋值 和 指针的赋值的区别  
- if else 中都要执行的操作放在条件判断的外面
- 链表中插入元素需要缓存插入处前后两个节点，
- 比较两个链表元素的前提是，两个链表都为非空，为空的话，->val为非法
- 比较元素之后，还需要把剩余元素加上

**剑指Offer 52. 两个链表的第一个公共节点**

- 复制链表和原链表 = copyA 和 = A
- 链表走的步数一致，这件事是可以控制的
- 环路思维

**offer 57**
- for 循环中，小于size()和小于等于size()-1 这两个边界是一致的
- 注意数值这个递增条件

**offer 58-1**

- if和 while ，只执行一次用if，可能执行多次用while
- 处理字符串的一个常用操作是取子字符串

### 5 搜索与回溯算法

觉得树很难，先用分而治之的办法想想，能不能拆解为基本概念，基本性质和基本问题

- 二叉树算法的返回值特点。遍历是树转化为向量，重构是向量转为树。还可以把树直接转为另一个树
- 递归中的return 语句，如果return 整型会怎么样，return void会怎么样，函数栈怎么传递return的结果
- DFS 决策树 路径 选择列表 剪枝 回溯 

**offer 12 矩阵中的路径**

- 二维数组的遍历与多叉树的遍历的关系
- 二维矩阵的下标与树的指针，数组前后-->上下左右，双向链表pre/next-->左子树/右子树
- 顺序存储和链式存储
- k值怎么加1
- 回溯法的几个普遍问题
  - 找到一条可行路径就退出
  - 剪枝

**offer13 机器人的运动范围**

- (子问题)数位和的求法，数位增量公式
- 怎么把一个矩阵看做一个抽象的二叉树
- 显式metric1-位数和，隐式metric2-无法跨越obstacle
- DFS 和 BFS
- {0, 0, 0, 0} 和 k < si + sj

**offer 26 二叉树的子树**

- 叶子节点和底层叶子节点的特点

- 怎么一个树是另一个树的子树

- 二叉树的遍历只能一个一个遍历，但为了缓存数据，需要将左子树或右子树缓存，

  对于深度优先（先序，中序，后序），有下层节点先与上层节点被访问，可能会用到栈

- 对于广度优先，需要用到队列

- 树的遍历中递归算法应用于查找子树

**offer 27 二叉树镜像** 

- 二叉树的镜像与层次遍历的逆序

**offer 28 对称的二叉树**

**offer 32-1**二叉树层次遍历

- 关注visit 向量和queue中存的值

- 根判空返回

  队列先进根

  循环取队头

  进值看左右

- 队列出队头的一个元素，再进该元素的子节点（出父节点，进子节点）

**offer 32-2** 二叉树按层打印

- queue  的size() 方法 
- 怎么知道当前遍历到哪一层
- 统计每层的元素总数

**offer 32-3** 二叉树蛇形打印

- 怎么判断在奇数层还是在偶数层
- 空层怎么保证不打印出来

**offer 34** 二叉树的路径

- vector的pop_back(),参数为void,与stack的pop()方法不同
- 树的路径搜素 -> 先序遍历的递归版本的变种

```c++
recur(root->left, tar);
recur(root->right, tar);
path.pop_back();
```

- 双重递归函数的调用顺序-->树的遍历的递归方法其实也是双重递归问题
- 递归函数后面的语句什么时候执行 recur; statement;

**? offer 36 二叉搜索树和双向链表**

- 对二叉搜素树进行中序遍历可以得到有序
- 构建链表时使用双指针
- 双向链表的定义，怎么通过一个head来表示一个双向链表

**offer 37 序列化二叉树**

- (子问题)字符串的spilit-->双指针
- 树节点的创建，new TreeNode*

**offer 38 字符串的排列**

- 全排列问题
- 减枝，回溯，添加备选路线
- loop 层数, recursive 深度
- 交换元素来降低空间复杂度
- 不知道层数的多重循环，不知道循环层数，用递归
- 不知道循环次数，用while
- 只一次用if
- 走500m就停，和到星龙街就停
- 解空间，解空间里有多个解，解空间里只要一个解（该问题与递归无关）
- 计算机擅长做重复的事情，循环即使计算机删除的逻辑，如果高效的循环怎么人需要设计

**offer 54 二叉搜索树的第 k 大节点**

- 遍历完再取值，和边遍历边比较
- 递归中找到对应的值怎么退出递归

**offer 55a 二叉树的深度**

**offer 55b 平衡二叉树**

- 递归有返回值

**offer 64 求1到n的和**

**剑指 Offer 68 - I. 二叉搜索树的最近公共祖先**

- 最近公共祖先的定义
- 最近公共祖先的情况遍历
- 与链表的公共节点的联系

**剑指 Offer 68 - II. 二叉树的最近公共祖先**

### 6 分治算法

**offer 07 重建二叉树**

- 中序+先序/后序可重建，必须包含中序

- 重建二叉树关键在于怎么计算递归参数，本题中有3个递归参数:root,left,right

- 在preorder list中确定root的位置，通过root新建二叉树节点-->参数root

- 在inorder list确定左/右子树元素的数量-->参数left,right

- inorder 和 preorder里元素都是相同，重建二叉树需要同时参考这两个列表，两者关联点在于元素，所以把元素作为hashmap的key

- 右子树的根节点索引：根节点索引 + 左子树长度 + 1

- i和1在代码中分开,用index=id

  ```markdown
  先序遍历用来确定根的位置；
  中序遍历用来确定左右子树的数量；
  在递归体中，root表示根的位置in preorder；
  left和right表示左右子树的边界in inorder;
  用到了三次recur，其中参数分别表示：
  
  recur(0,0,len(inorder)-1):本句为建立整棵二叉树，pre[0]为根元素，在inorder中左边界和 右边界分别是整个数组的左右边界
  
  node.left = recur(root+1,left,i-1)：本句为建立左子树，左子树的根在整棵树根的下一个位置（在preorder中找位置）即root+1；左子树的左边界仍为原树的左边界；左子树的右边界在inorder中位于根元素位置的左侧一个，即i-1
  
  node.right = recur(i-left+root+1,i+1,right):本句为建立右子树，右子树的根的位置需要在原树根位置root的基础上加上左子树的元素个数i-left的下一位置（在preorder中找位置）,即root+(i-left)+1；右子树的右边界仍为原树的右边界；右子树的左边界在inorder中位于根元素位置的右侧一个，即i+1
  ```

**剑指 Offer 17. 打印从 1 到最大的 n 位数**
- 分治算法解决全排列问题
- 将int数据问题转成字符串排列问题


**offer33 二叉搜索树的后序遍历**

- 后序遍历的特点，左子树->右子树->根，根必然是最后一个元素，设右子树的第一个元素为m，树的第一个元素为i，最后一个元素为j，这树可表示为 (左子树[i:m-1],右子树[m:j-1],根[j])
- 问题是判断是否为二叉搜索树的后序遍历，转化为问题-->判断后序遍历是否为二叉搜索树
- 递归终止条件在递归函数的最开始
- 递归参数tree,i,j

**offer 51 归并排序**

- if else 在递归类函数中的调用，不同递归层次执行的判断条件不一样

- if else 满足交换律，合并等效

- i,j双指针从两个子数组里选元素填到带排序数组中，无论哪中情况，都执行k++，将每个条件都会执行操作单独拿出来。

- 条件逻辑的总结：1递归，2条件顺序交换，3条件合并，4条件执行语句的合并

- 先考虑两个有序数组合并成一个有序数组的问题，再把问题推广到递归解法, recur body在双指针之前，二分之后

- 带返回值的递归，递归终止返回值是什么

- 条件顺序交换，先判断越界条件(不先判断会导致递归程序崩溃--> 递归对判断条件的影响)

- 测试用例中，数组有相同的元素的情况，条件中要带等号 tmp[i] <= tmp[j]

- 逆序对个数m-i+1个

### 7 动态规划

**offer 10a fib**

- fib的四种方法
  1. brute force recur
  2. recur with pruning --> time comlexity optimize
  3. convert top-down to down-top(recur-->loop)
  4. space complexity optimization for DP table
- return `pre` but not `sum`, loop boundry`(i<n)`



**offer 10b**
- different initial value

**offer 19**

**offer 42**
- 求和问题
- 动态规划的几大要素
- 代码简化
  if dp[i−1]>0
    dp[i]= dp[i−1]+nums[i]
  if dp[i−1]≤0  
    dp[i]= nums[i]​
  等价于：
  nums[i] += max(nums[i - 1], 0)


**offer 46**
**offer 47**
1. dp转移方程
if i=0,j=0
  dp(i,j)=grid(i,j)
if i=0,j/=0
  dp(i,j)=grid(i,j) + dp(i,j-1)
if i/=0,j=0
  dp(i,j)=grid(i,j)+dp(i-1,j)
if i/=0,j/=0
  dp(i,j)=grid(i,j)+max(dp(i-1,j),dp(i,j-1))
2. 一维到二维的拓展，剑指 Offer 42. 连续子数组的最大和
3. 题目中的条件，全都是正值
4. 理论上只有一个表达式 dp(i,j)=grid(i,j)+max(dp(i-1,j),dp(i,j-1))，边界项的dp(i-1,j)或dp(i,j-1)为0
5. 对矩阵中dp(i-1,j)为上边的值，dp(i,j-1)为左面的值这一点要熟悉
   上 (i-1,j)
   下 (i+1,j)
   左 (i,j-1)
   右（i,j+1)

**offer 48**
1. 双指针法
一个指针来遍历字符串，怎么决定另一个指针
2. hashmap
`find` `key`
`->second` `value`
3. 这个问题应该是这样的，j指向当前元素，当前元素和上一个当前元素之间的字符串可能为最长子序列，为保证该字符串内无重复数据，应保证左索引为max（i，s[j]上次出现的索引）
4. i 初始化为-1
5. 子问题问题是怎么确定两次重复出现字符之间的间隔
6. 空间复杂度的优化，采用buffer的形成，空间复杂度怎么降低，一块内存更新前和更新后，来实现buffer的功能

**offer 49**
1. 三指針
2. 不止一個指針步進
3. c++ std::min 輸入參數為三個（>2個）

**offer 63**
- 求两个极值的差的问题
- 求数组中前m个元素的最小值 min(array[0:i])
- 暴力算法：
  1. 求数组中的最小值 min
  2. 求以最小值为左边界剩余数组中的最大值 max
  3. 最大利润为max - min


### 8  模拟
**offer29**
- 基础问题:打印一行
- 边界初值,边界更新
- 循环结束条件,边界干涉是循环结束
- while(true)循环，通过内部break退出循环
- 矩阵分为行列
- 矩阵bottom边界 为矩阵行数-1，matrix.size()-1;矩阵right边界 为矩阵列数-1，matrix[0].size()-1
- break条件 left> right和right< left 不是一个意思，两者不等价

**offer31**
- while 循环中，怎么包含for循环中步进index的功能
- 双重循环，都时间复杂度 是O(N)


### 9 位运算
**offer 15 二进制中1的个数**
- 二进制的与运算 ,`(n-1)`和`n&(n-1)`,做一次与运算消去一个1

### 10 数学
**offer 14-1**
- 动态规划，状态转移方程：dp[i]=max(dp[i],j*max(dp[i-j],i-j))

**offer 14-2**
- 输入的取值范围决定算法的复杂度
- 对大数越界的处理
- 数据结论，每段按长度2或3来分割，在考虑余数的情况

**剑指 Offer 39. 数组中出现次数超过一半的数字**
- hash法统计每个元素出现的次数，空间复杂度O(n)
  ```c++
      int majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(int n:nums)   
            if(++ mp[n] > nums.size()/2)   return n;         
        return -1;}
  ```
- 排序法
  ```c++
      int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2]; }         //因为出现频率大于n/2，所以排序后的中间位置必然是众数
  ```
- 摩尔投票,空间复杂度O(1)

**剑指Offer 57 - II. 和为 s 的连续正数序列**
- python 中的return的返回层级,缩进的影响
- 对空间复杂度的优化

**剑指 Offer 66. 构建乘积数组**
- 上三角，下三角
- 非空判断
- 减序循环 for(int i=len-2;i>=0;i--)
- vector 下标操作，初始化时，需要初始足够的大小的内存，不通过push_back可以直接给容器赋值
- 多个for循环，怎么减少循环数量，空间复杂度怎么优化