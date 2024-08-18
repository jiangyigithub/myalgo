#include <memory>
#include <iostream>
#include <string>
using namespace std;

class Dog
{
    string m_name;

public:
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog(string name)
    {
        cout << "Dog is created: " << name << endl;
        m_name = name;
    }
    Dog()
    {
        cout << "Nameless dog created." << endl;
        m_name = "nameless";
    }
    ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
    // void enter(DogHouse* h) { h->setDog(shared_from_this()); }  // Dont's call shared_from_this() in constructor
};

// dangling pointer
void foo1()
{
    Dog *p = new Dog("Gunner");
    //...
    delete p;
    //...
    p->bark(); // p is a dangling pointer - undefined behavior
}

// memory leak
void foo2()
{
    Dog *p = new Dog("Gunner");
    //...
    //...
    p->bark();
} // Memory leak

void foo3()
{
    shared_ptr<Dog> p1(new Dog("Gunner")); // count = 1
    {
        shared_ptr<Dog> p2 = p1; // count = 2
        p2->bark();
        // stack object
        Dog p3("Stack Gunner");
        // temp object
        Dog("Temp Gunner");
    } // count = 1 , out of p2 range
    p1->bark();
} // count = 0, out of p1 range

void foo4()
{
    auto p = std::make_shared<int>(4);
    auto p1 = std::shared_ptr<int>(new int(4));
    std::cout << p << "\t" << p1 << "\n";
}

void foo5()
{
    auto p = std::make_shared<int>(4);
    auto p1 = p;// 拷贝赋值
    std::cout << "p use_count: " << p.use_count() << "\n";
    auto p2 = std::move(p);// 
    std::cout << "p use_count: " << p1.use_count() << "\n";
}
int main()
{
    // foo3();
    // foo4();
    foo5();
    return 0;
}