#include <iostream>

// 1. What should the private members of the class be?
// 2. Write the constructor/destructor
// 3. Write the assignment operator/copy constructor. (Hint: What happens with self-assignment?)

class SharedPointer {

private:
    int* ptr;  // 原始指针
    int* ref_count;  // 引用计数

public:
    // 构造函数
    explicit SharedPointer(int* p = nullptr)
        : ptr(p), ref_count(new int(p ? 1 : 0)) {
    }

    // 拷贝构造函数
    SharedPointer(const SharedPointer& other)
        : ptr(other.ptr), ref_count(other.ref_count) {
        if (ptr) {
            ++(*ref_count);
        }
    }

    // 拷贝赋值运算符
    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            // 减少旧对象的引用计数
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }

            // 复制数据和引用计数指针
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ptr) {
                ++(*ref_count);
            }
        }
        return *this;
    }

    // 析构函数
    ~SharedPointer() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    // 重载解引用运算符
    int& operator*() const {
        return *ptr;
    }

    // 重载箭头运算符
    int* operator->() const {
        return ptr;
    }

    // 获取原始指针
    int* get() const {
        return ptr;
    }

    // 获取引用计数
    int use_count() const {
        return *ref_count;
    }
};

// 示例使用
int main() {
    SharedPointer sp1(new int(5));
    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl; // 输出: 1

    {
        SharedPointer sp2 = sp1;
        std::cout << "sp1 use_count: " << sp1.use_count() << std::endl; // 输出: 2
        std::cout << "sp2 use_count: " << sp2.use_count() << std::endl; // 输出: 2
    }

    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl; // 输出: 1

    return 0;
}
