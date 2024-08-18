#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

unordered_map<char, string> day = {{'S',"Sunday"}, {'M',"Monday"}};
cout << day['S'] << endl;    // No range check
cout << day.at('S') << endl; // Has range check

vector<int> vec = {1, 2, 3};
cout << vec[2]<<endl;     // 3  (no range check)
cout << vec.at(2)<<endl;  // 3  (throw range_error exception of out of range)

vec[5] = 5;   // Compile Error, size() <5

day.insert(make_pair('F', "Friday"));  // Inserting {'F', "Friday"}
day['W'] = "Wednesday";  // Inserting {'W', "Wednesday}

day.insert(make_pair('M', "MONDAY"));  // Fail to modify, it's an unordered_map
day['M'] = "MONDAY";                   // Succeed to modify