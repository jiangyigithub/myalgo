#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__
#include <iostream>
#include <cmath>
using namespace std;

/*
 * 1. 前置声明 declaration
 */
class complex;
complex &
__doapl(complex *ths, const complex &r);

/*
 * 2. 类的声明 declaration
 */
class complex
{
public:
  // 构造函数，初始化列表
  complex(double r = 0, double i = 0) : re(r), im(i) {}

  // 成员函数，操作符重载
  complex &operator+=(const complex &);

  // const 成员函数
  double real() const { return re; }
  double imag() const { return im; }

private:
  double re, im;
  // 友元非成员函数
  friend complex &__doapl(complex *, const complex &);
};

/*
 * 3. 函数定义
 * 3.1 成员函数
 * 3.2 全局函数
 */
inline complex &
__doapl(complex *ths, const complex &r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}

inline complex &
complex::operator+=(const complex &r)
{
  return __doapl(this, r);
}

// 取实部，虚部
inline double
imag(const complex &x)
{
  return x.imag();
}

inline double
real(const complex &x)
{
  return x.real();
}

// 复数加法 - 函数重载
inline complex
operator+(const complex &x, const complex &y)
{
  // 临时对象
  return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator+(const complex &x, double y)
{
  return complex(real(x) + y, imag(x));
}

inline complex
operator+(double x, const complex &y)
{
  return complex(x + real(y), imag(y));
}

// 复数减法
inline complex
operator-(const complex &x, const complex &y)
{
  return complex(real(x) - real(y), imag(x) - imag(y));
}

inline complex
operator-(const complex &x, double y)
{
  return complex(real(x) - y, imag(x));
}

inline complex
operator-(double x, const complex &y)
{
  return complex(x - real(y), -imag(y));
}


inline complex
operator+(const complex &x)
{
  return x;
}
// 复数取反
inline complex
operator-(const complex &x)
{
  return complex(-real(x), -imag(x));
}

// 复数打印
ostream &
operator<<(ostream &os, const complex &x)
{
  return os << '(' << real(x) << ',' << imag(x) << ')';
}

#endif //__MYCOMPLEX__