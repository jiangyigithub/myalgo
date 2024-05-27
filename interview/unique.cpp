#include <iostream>

class UniquePointer {
private:
    int* ptr;  // Raw pointer

public:
    // Default constructor
    explicit UniquePointer(int* p = nullptr)
        : ptr(p) {
    }

    // Destructor
    ~UniquePointer() {
        delete ptr;
    }

    // Move constructor
    UniquePointer(UniquePointer&& other) noexcept
        : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment operator
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr;  // Delete the old resource
            ptr = other.ptr;  // Transfer ownership
            other.ptr = nullptr;  // Nullify the source pointer
        }
        return *this;
    }

    // Deleted copy constructor and copy assignment operator
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Dereference operator
    int& operator*() const {
        return *ptr;
    }

    // Arrow operator
    int* operator->() const {
        return ptr;
    }

    // Get raw pointer
    int* get() const {
        return ptr;
    }

    // Release ownership of the pointer
    int* release() {
        int* oldPtr = ptr;
        ptr = nullptr;
        return oldPtr;
    }

    // Reset the pointer with a new raw pointer
    void reset(int* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

// Example usage
int main() {
    UniquePointer up1(new int(5));
    std::cout << "up1 value: " << *up1 << std::endl; // Output: 5

    UniquePointer up2 = std::move(up1);  // Use move constructor
    std::cout << "up2 value: " << *up2 << std::endl; // Output: 5
    std::cout << "up1 value: " << (up1.get() ? *up1 : 0) << std::endl; // Output: 0

    UniquePointer up3(new int(10));
    up3 = std::move(up2);  // Use move assignment operator
    std::cout << "up3 value: " << *up3 << std::endl; // Output: 10
    std::cout << "up2 value: " << (up2.get() ? *up2 : 0) << std::endl; // Output: 0

    return 0;
}
