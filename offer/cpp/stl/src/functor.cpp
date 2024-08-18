#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric> // some numeric algorithm
#include <functional>
using namespace std;

class X
{
    int val;

public:
    // ctor
    X() : val(0){};

    // functor
    void operator()(string str)
    {
        val++;
        cout << "Calling functor X with parameter " << str << endl;
        cout << "val = " << val << endl;
    }

    operator string() const { return "X"; } // type conversion function
};

void addVal(int i, int val)
{
    cout << i + val << endl;
}

double Pow(double x, double y)
{
    return pow(x, y);
}

bool needCopy(int x)
{
    return (x > 20) || (x < 5);
}

// set 传入参数为class类型 --> class _Pr = less<_Kty>
class Lsb_less
{
public:
    bool operator()(int x, int y)
    {
        return (x % 10) < (y % 10);
    }
};

class NeedCopy
{
public:
    bool operator()(int x)
    {
        return (x > 20) || (x < 5);
    }
};

int main()
{
    X foo;
    foo("Hello"); // Calling functor X with parameter Hi
    foo("World");

    /*
     * Build-in Functors
     */
    int x = multiplies<int>()(3, 4); //  x = 3 * 4

    if (not_equal_to<int>()(x, 10)) // if (x != 10)
        cout << x << endl;

    /*
     * Parameter Binding
     */
    set<int> myset = {2, 3, 4, 5};
    vector<int> vec;

    // Multiply myset's elements by 10 and save in vec:
    transform(myset.begin(), myset.end(),                     // source
              back_inserter(vec),                             // destination
              bind(multiplies<int>(), placeholders::_1, 10)); // functor
    // First parameter of multiplies<int>() is substituted with myset's element
    // vec: {20, 30, 40, 50}

    for_each(vec.begin(), vec.end(), bind(addVal, placeholders::_1, 2));

    /*
     * Convert a regular function to a functor --> std::function
     */
    set<int> myset2 = {3, 1, 25, 7, 12};
    deque<int> d;
    auto f = function<double(double, double)>(Pow); // C++ 11
    transform(myset2.begin(), myset2.end(),         // source
              back_inserter(d),                     // destination
              bind(f, placeholders::_1, 2));        // functor
                                                    //  d: {1, 9, 49, 144, 625}

    /*
     * Lambda
     */
    set<int> myset3 = {3, 1, 25, 7, 12};
    // when (x > 20) || (x < 5),  copy from myset to d
    deque<int> d2;

    transform(myset3.begin(), myset3.end(), // source
              back_inserter(d2),            // destination
              needCopy);

    // C++ 11 lambda function:
    transform(myset3.begin(), myset3.end(), // source
              back_inserter(d2),            // destination
              [](int x)
              { return (x > 20) || (x < 5); });
    /*
     * Why do we need functor in STL?
     */
    set<int, Lsb_less> myset4 = {3, 1, 25, 7, 12}; // myset: {1,12,3,25,7}
    deque<int> d3;

    /*
     * Predicate
     *
     * A functor or function that:
     * 1. Returns a boolean
     * 2. Does not modify data
     */

    transform(myset4.begin(), myset4.end(), // source
              back_inserter(d3),           // destination
              NeedCopy());

    // Predicate is used for comparison or condition check

    return 0;
}
