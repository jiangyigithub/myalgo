// Introduction of STL: https://www.youtube.com/watch?v=ltBdTiRgSaw&list=PL5jc9xFGsL8G3y3ywuFSvOuNm3GjBwdkb&index=2
// Effective STL 阅读笔记: https://zhuanlan.zhihu.com/p/458156007

/**
 * 1. How containers, algorithms and iterators work together as a team
 * 2. there are many pitfalls and traps（cout<<*vec.end()<<endl;//Ouch！）
 *
 *
 * **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // containers
    vector<int> vec; // in heap
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8); // vec:{4,1,8}

    // iterators
    vector<int>::iterator itr1 = vec.begin(); // half-open: [begin,end)
    vector<int>::iterator itr2 = vec.end();

    // print vector elements before sorting
    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // algorithms
    sort(itr1, itr2); // vec:{1,4,8}

    // print vector elements after sorting
    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
    {
        cout << *itr << " ";
    }
    return 0;
}
