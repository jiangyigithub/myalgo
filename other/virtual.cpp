#include <iostream>

class Base {
public:
    virtual void virtualFunction() {
        std::cout << "Base::virtualFunction()" << std::endl;
    }
};

class Derived : public Base {
public:
    void virtualFunction() override {
        std::cout << "Derived::virtualFunction()" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    std::cout << "Size of Base object: " << sizeof(baseObj) << std::endl;
    std::cout << "Size of Derived object: " << sizeof(derivedObj) << std::endl;

    Base* ptr1=new Derived();
    ptr1->virtualFunction();
    Base* ptr2=new Base();
    ptr2->virtualFunction();

    return 0;
}
