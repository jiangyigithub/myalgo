#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> // some numeric algorithm
#include <functional>
using namespace std;

bool isOdd(int i)
{
    return i % 2;
}

int main()
{

    vector<int> vec = {4, 2, 5, 1, 3, 9};
    vector<int>::iterator itr = min_element(vec.begin(), vec.end()); // itr -> 1

    // Note 1: Algorithm always process ranges in a half-open way: [begin, end)
    sort(vec.begin(), itr); // vec: { 2, 4, 5, 1, 3, 9}

    reverse(itr, vec.end()); // vec: { 2, 4, 5, 9, 3, 1}   itr => 9

    // Note 2: more than one range loop case
    vector<int> vec2(3);
    copy(itr, vec.end(), // Source
         vec2.begin());  // Destination
                         // vec2 needs to have at least space for 3 elements.

    // Note 3:
    vector<int> vec3;
    copy(itr, vec.end(), back_inserter(vec3)); // Inserting instead of overwriting
                                               // back_insert_iterator      Not efficient --> copy one by one

    vec3.insert(vec3.end(), itr, vec.end()); // Efficient and safe --> insert once
    
    
    // Note 4: Algorithm with function
    vector<int> vec4 = {2, 4, 5, 9, 2};
    vector<int>::iterator itr4 = find_if(vec4.begin(), vec4.end(), isOdd);
    // itr4 -> 5


    // Note 5: Algorithm with native C++ array --> array is a pointer, so it is a iterator,algorithm operate on iterator level
    int arr[4] = {6, 3, 7, 4};
    sort(arr, arr + 4);
    return 0;
}