#include <iostream>
#include <utility>  // For std::swap

class SharedPointer {
private:
    int* ptr;       // Raw pointer
    int* ref_count; // Reference count

public:
    // Default constructor
    explicit SharedPointer(int* p = nullptr)
        : ptr(p), ref_count(new int(p ? 1 : 0)) {
    }

    // Copy constructor
    SharedPointer(const SharedPointer& other)
        : ptr(other.ptr), ref_count(other.ref_count) {
        if (ptr) {
            ++(*ref_count);
        }
    }

    // Move constructor
    SharedPointer(SharedPointer&& other) noexcept
        : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // Copy assignment operator
    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            // Decrease old object's reference count
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }

            // Copy data and reference count pointer
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ptr) {
                ++(*ref_count);
            }
        }
        return *this;
    }

    // Move assignment operator
    SharedPointer& operator=(SharedPointer&& other) noexcept {
        if (this != &other) {
            // Decrease old object's reference count
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }

            // Move data and reference count pointer
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // Destructor
    ~SharedPointer() {
        if (ref_count && --(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

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

    // Get reference count
    int use_count() const {
        return *ref_count;
    }
};

// Example usage
int main() {
    SharedPointer sp1(new int(5));
    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl; // Output: 1

    {
        SharedPointer sp2 = sp1;
        std::cout << "sp1 use_count: " << sp1.use_count() << std::endl; // Output: 2
        std::cout << "sp2 use_count: " << sp2.use_count() << std::endl; // Output: 2
    }

    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl; // Output: 1

    SharedPointer sp3(new int(10));
    std::cout << "sp3 use_count: " << sp3.use_count() << std::endl; // Output: 1
    sp3 = std::move(sp1);  // Use move assignment operator
    std::cout << "sp3 use_count: " << sp3.use_count() << std::endl; // Output: 1
    std::cout << "sp1 use_count: " << (sp1.get() ? sp1.use_count() : 0) << std::endl; // Output: 0

    return 0;
}
