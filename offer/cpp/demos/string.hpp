#ifndef __MYSTRING__
#define __MYSTRING__
#include <cstring>
#include <iostream>
using namespace std;

class String
{
public:                                 
   String(const char* cstr=0);                     
   String(const String& str);                    
   String& operator=(const String& str);         
   ~String();                                    
   char* get_c_str() const { return m_data; }
private:
   char* m_data;// 4 bite
};

/*
* 构造函数内部调用new，创建的内存不是string对象所占空间，而是string对象中成员m_data指针指向的内存空间，指针自身的内存大小是固定的
* 并非成员变量是指针的类，在其构造函数中都需要调用new来让该指针指向一段内存，string类的例子中，string内的指向需要指向一片动态内存，因为字符串的内存大小是不确定的。
* 而对于链表，成员包含指针，但其构造函数中没有用new来让其指针指向一块内存区域，而是让其指向nullptr
*/

inline
String::String(const char* cstr)
{
   if (cstr) {
      // 初始化时，字符串大小是不确定的
      m_data = new char[strlen(cstr)+1];
      strcpy(m_data, cstr);
   }
   else {   
      m_data = new char[1];
      *m_data = '\0';
   }
}

//析构函数调用delete[], 删除m_data指向的内容，而m_data属于对象的成员，对象的内存释放由该对象是在堆中生成还是在栈中生成有关
// 无论对象是在栈中还是在堆中，都会调用构造和析构函数
inline
String::~String()
{
   delete[] m_data;
}

// 拷贝赋值必须重写
// 通常赋值操作符是通过拷贝构造函数来实现 的（ copy-and-swap 技术，详见《Exceptional C++》一书
inline
String& String::operator=(const String& str)
{
   if (this == &str)
      return *this;

   delete[] m_data;
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
   return *this;
}

//拷贝构造必须重写，不然编译器默认生成的是浅拷贝，字符串的内容不是类的组成部分，
//String s1("hello"), "hello"不是对象s1的成员变量，s1的成员变量m_data是一个指针，指向"hello"
inline
String::String(const String& str)
{
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
}


// 不可以是成员函数，需是全局函数
ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}

class DefaultString
{
public:                                 
   DefaultString(const char* cstr=0);                          
   ~DefaultString();                                    
   char* get_c_str() const { return m_data; }
private:
   char* m_data;// 4 bite
};


inline
DefaultString::DefaultString(const char* cstr)
{
   if (cstr) {
      m_data = new char[strlen(cstr)+1];
      strcpy(m_data, cstr);
   }
   else {   
      m_data = new char[1];
      *m_data = '\0';
   }
}

//析构函数调用delete[], 删除m_data指向的内容，而m_data属于对象的成员，对象的内存释放由该对象是在堆中生成还是在栈中生成有关
// 无论对象是在栈中还是在堆中，都会调用构造和析构函数
inline
DefaultString::~DefaultString()
{
   delete[] m_data;
}

// 不可以是成员函数，需是全局函数
ostream& operator<<(ostream& os, const DefaultString& str)
{
   os << str.get_c_str();
   return os;
}

#endif