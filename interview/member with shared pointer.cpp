#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }

    ~Resource() {
        std::cout << "Resource destroyed" << std::endl;
    }

    void doSomething() {
        std::cout << "Resource is doing something" << std::endl;
    }
};

class MyClass {
private:
    std::shared_ptr<Resource> sharedResource;  // shared_ptr 成员变量
    std::unique_ptr<Resource> uniqueResource;  // unique_ptr 成员变量

public:
    MyClass()
        : sharedResource(std::make_shared<Resource>()),
          uniqueResource(std::make_unique<Resource>()) {
        std::cout << "MyClass constructed" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destroyed" << std::endl;
    }

    void useResources() {
        sharedResource->doSomething();
        uniqueResource->doSomething();
    }

    std::shared_ptr<Resource> getSharedResource() {
        return sharedResource;  // 返回 shared_ptr
    }

    std::unique_ptr<Resource> releaseUniqueResource() {
        return std::move(uniqueResource);  // 移动 unique_ptr
    }
};

int main() {
    MyClass obj;
    obj.useResources();

    // 共享 shared_ptr 资源
    std::shared_ptr<Resource> sharedRes1 = obj.getSharedResource(); // 拷贝赋值，ref count会+1
    std::shared_ptr<Resource> sharedRes2 = sharedRes1;//  拷贝赋值，ref count会+1

    std::cout << "sharedRes1 use count: " << sharedRes1.use_count() << std::endl; // 输出: 3
    std::cout << "sharedRes2 use count: " << sharedRes2.use_count() << std::endl; // 输出: 3

    // 尝试共享 unique_ptr 资源（会产生编译错误）
    // std::unique_ptr<Resource> uniqueRes1 = obj.releaseUniqueResource();
    // std::unique_ptr<Resource> uniqueRes2 = uniqueRes1; // 编译错误：unique_ptr 不可复制

    // 转移 unique_ptr 资源所有权
    std::unique_ptr<Resource> uniqueRes1 = obj.releaseUniqueResource();
    if (uniqueRes1) {
        uniqueRes1->doSomething();
    }

    // uniqueRes2 获取 uniqueRes1 的所有权
    std::unique_ptr<Resource> uniqueRes2 = std::move(uniqueRes1);
    if (uniqueRes2) {
        uniqueRes2->doSomething();
    }

    std::cout << "End of main" << std::endl;

    return 0;
}
