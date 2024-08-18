#include "string.hpp"
#include <iostream>

using namespace std;

int main()
{
  String s1("hello");
  String s2("world");

  String s3(s1);
  String s4 = s2;

  String *p = new String("hello");
  delete p;

  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  cout << s4 << endl;
  
  // 默认的拷贝构造和拷贝赋值为浅拷贝
  DefaultString s5("hello_d");
  DefaultString s6("world_d");
  DefaultString s7(s5);// s5 s7 中指针m_data地址相同
  DefaultString s8 = s6;// s6 s8

  cout << s5 << endl;
  cout << s6 << endl;
  cout << s7 << endl;
  cout << s8 << endl;
  // 函数退出时，析构函数调用了两次，所以软件会报错
  return 0;
}