#include <iostream>

template <typename T>
class MyUniquePtr {
private:
    T* ptr;

public:
    // Constructor
    explicit MyUniquePtr(T* ptr = nullptr) : ptr(ptr) {}

    // Destructor
    ~MyUniquePtr() {
        delete ptr;
    }

    // Move constructor
    MyUniquePtr(MyUniquePtr&& other) noexcept : ptr(other.release()) {}

    // Move assignment operator
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    // Disable copy constructor and assignment operator
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // Get the raw pointer
    T* get() const noexcept {
        return ptr;
    }

    // Release the ownership
    T* release() noexcept {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Reset the pointer
    void reset(T* newPtr = nullptr) noexcept {
        if (ptr != newPtr) {
            delete ptr;
            ptr = newPtr;
        }
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Member access operator
    T* operator->() const noexcept {
        return ptr;
    }

    // Boolean conversion operator
    explicit operator bool() const noexcept {
        return ptr != nullptr;
    }
};

// Example usage
int main() {
    MyUniquePtr<int> ptr(new int(42));
    std::cout << *ptr << std::endl; // Output: 42

    // Move semantics
    MyUniquePtr<int> ptr2 = std::move(ptr);
    std::cout << *ptr2 << std::endl; // Output: 42
    // std::cout << *ptr << std::endl; // Error: ptr is nullptr now

    // Reset
    ptr2.reset(new int(10));
    std::cout << *ptr2 << std::endl; // Output: 10

    return 0;
}
