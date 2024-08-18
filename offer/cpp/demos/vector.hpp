#include <iostream>  // std::cerr
#include <stdexcept> // std::out_of_range
#include <vector>

using namespace std;

/* 列表类简易实现 */
class MyList
{
public:
    int *nums;            // 数组（存储列表元素）
    int numsCapacity = 3; // 列表容量
    int numsSize = 0;     // 列表长度（即当前元素数量）
    int extendRatio = 2;  // 每次列表扩容的倍数

public:
    /* 构造方法 */
    MyList()
    {
        nums = new int[numsCapacity];
    }

    /* 析构方法 */
    ~MyList()
    {
        delete[] nums;
    }

    /* 获取列表长度（即当前元素数量）*/
    int size()
    {
        return numsSize;
    }

    /* 获取列表容量 */
    int capacity()
    {
        return numsCapacity;
    }

    /* 访问元素 */
    int get(int index)
    {
        // 索引如果越界则抛出异常，下同
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        return nums[index];
    }

    /* 更新元素 */
    void set(int index, int num)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        nums[index] = num;
    }

    /* 尾部添加元素 */
    void add(int num)
    {
        // 元素数量超出容量时，触发扩容机制
        if (size() == capacity())
            extendCapacity();
        nums[size()] = num;
        // 更新元素数量
        numsSize++;
    }

    /* 中间插入元素 */
    void insert(int index, int num)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        // 元素数量超出容量时，触发扩容机制
        if (size() == capacity())
            extendCapacity();
        // 索引 i 以及之后的元素都向后移动一位
        for (int j = size() - 1; j >= index; j--)
        {
            nums[j + 1] = nums[j];
        }
        nums[index] = num;
        // 更新元素数量
        numsSize++;
    }

    /* 删除元素 */
    int remove(int index)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        int num = nums[index];
        // 索引 i 之后的元素都向前移动一位
        for (int j = index; j < size() - 1; j++)
        {
            nums[j] = nums[j + 1];
        }
        // 更新元素数量
        numsSize--;
        // 返回被删除元素
        return num;
    }

    /* 列表扩容 */
    void extendCapacity()
    {
        // 新建一个长度为原数组 extendRatio 倍的新数组
        int newCapacity = capacity() * extendRatio;
        int *tmp = nums;
        nums = new int[newCapacity];
        // 将原数组中的所有元素复制到新数组
        for (int i = 0; i < size(); i++)
        {
            nums[i] = tmp[i];
        }
        // 释放内存
        delete[] tmp;
        numsCapacity = newCapacity;
    }

    /* 将列表转换为 Vector 用于打印 */
    vector<int> toVector()
    {
        // 仅转换有效长度范围内的列表元素
        vector<int> vec(size());
        for (int i = 0; i < size(); i++)
        {
            vec[i] = nums[i];
        }
        return vec;
    }
};

