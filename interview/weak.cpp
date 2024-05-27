#include <iostream>

class WeakPointer; // Forward declaration

class SharedPointer {
private:
    int* ptr;       // Raw pointer
    int* ref_count; // Shared reference count
    int* weak_count; // Weak reference count

public:
    // Default constructor
    explicit SharedPointer(int* p = nullptr)
        : ptr(p), ref_count(new int(p ? 1 : 0)), weak_count(new int(0)) {
    }

    // Destructor
    ~SharedPointer() {
        release();
    }

    // Copy constructor
    SharedPointer(const SharedPointer& other)
        : ptr(other.ptr), ref_count(other.ref_count), weak_count(other.weak_count) {
        if (ptr) {
            ++(*ref_count);
        }
    }

    // Copy assignment operator
    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            weak_count = other.weak_count;
            if (ptr) {
                ++(*ref_count);
            }
        }
        return *this;
    }

    // Move constructor
    SharedPointer(SharedPointer&& other) noexcept
        : ptr(other.ptr), ref_count(other.ref_count), weak_count(other.weak_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
        other.weak_count = nullptr;
    }

    // Move assignment operator
    SharedPointer& operator=(SharedPointer&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            weak_count = other.weak_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
            other.weak_count = nullptr;
        }
        return *this;
    }

    // Construct from WeakPointer
    SharedPointer(const WeakPointer& wp);

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
        return ref_count ? *ref_count : 0;
    }

    // Get weak count
    int weak_count_() const {
        return weak_count ? *weak_count : 0;
    }

    // Friend class WeakPointer
    friend class WeakPointer;

private:
    void release() {
        if (ref_count && --(*ref_count) == 0) {
            delete ptr;
            if (*weak_count == 0) {
                delete ref_count;
                delete weak_count;
            }
        } else if (weak_count && *weak_count == 0) {
            delete weak_count;
        }
    }
};

class WeakPointer {
private:
    int* ptr;         // Raw pointer
    int* ref_count;   // Shared reference count
    int* weak_count;  // Weak reference count

public:
    // Default constructor
    WeakPointer()
        : ptr(nullptr), ref_count(nullptr), weak_count(nullptr) {
    }

    // Constructor from SharedPointer
    WeakPointer(const SharedPointer& sp)
        : ptr(sp.ptr), ref_count(sp.ref_count), weak_count(sp.weak_count) {
        if (weak_count) {
            ++(*weak_count);
        }
    }

    // Copy constructor
    WeakPointer(const WeakPointer& other)
        : ptr(other.ptr), ref_count(other.ref_count), weak_count(other.weak_count) {
        if (weak_count) {
            ++(*weak_count);
        }
    }

    // Copy assignment operator
    WeakPointer& operator=(const WeakPointer& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            weak_count = other.weak_count;
            if (weak_count) {
                ++(*weak_count);
            }
        }
        return *this;
    }

    // Destructor
    ~WeakPointer() {
        release();
    }

    // Lock function to promote WeakPointer to SharedPointer
    SharedPointer lock() const {
        return expired() ? SharedPointer() : SharedPointer(*this);
    }

    // Check if the resource is still managed by a SharedPointer
    bool expired() const {
        return !ref_count || *ref_count == 0;
    }

private:
    void release() {
        if (weak_count && --(*weak_count) == 0 && (!ref_count || *ref_count == 0)) {
            delete ref_count;
            delete weak_count;
        }
    }

    // Friend class SharedPointer
    friend class SharedPointer;
};

// Construct SharedPointer from WeakPointer
SharedPointer::SharedPointer(const WeakPointer& wp)
    : ptr(wp.ptr), ref_count(wp.ref_count), weak_count(wp.weak_count) {
    if (ref_count && *ref_count > 0) {
        ++(*ref_count);
    } else {
        ptr = nullptr;
        ref_count = nullptr;
        weak_count = nullptr;
    }
}

// Example usage
int main() {
    SharedPointer sp1(new int(5));
    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl; // Output: 1
    std::cout << "sp1 weak_count: " << sp1.weak_count_() << std::endl; // Output: 0

    WeakPointer wp1 = sp1;
    std::cout << "sp1 weak_count after wp1: " << sp1.weak_count_() << std::endl; // Output: 1

    {
        SharedPointer sp2 = wp1.lock();
        std::cout << "sp1 use_count after sp2: " << sp1.use_count() << std::endl; // Output: 2
        std::cout << "sp2 use_count: " << sp2.use_count() << std::endl; // Output: 2
        std::cout << "sp1 weak_count after sp2: " << sp1.weak_count_() << std::endl; // Output: 1
    }

    std::cout << "sp1 use_count after sp2 destroyed: " << sp1.use_count() << std::endl; // Output: 1
    std::cout << "sp1 weak_count after sp2 destroyed: " << sp1.weak_count_() << std::endl; // Output: 1

    return 0;
}
