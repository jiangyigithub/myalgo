#pragma once

#include "vector.hpp"
int main()
{
    MyList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    vector<int> vec = list.toVector();
    std::cout << list.numsCapacity;
    for (auto elem : vec)
    {
        std::cout << elem << std::endl;
    }
}
