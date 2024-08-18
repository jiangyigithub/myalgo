Definitions of function templates and member functions of class templates are ordinarily put into header files.

## .inl 文件的作用
模板的申明和实现都要放在头文件中，为了保持头文件的干净，可以将模板实现定义在 `xxx.inl`文件中，在头文件的最后`#include xxx.inl` 

Create an .inl file and #include it at the end of your header file

From <https://www.oreilly.com/library/view/c-cookbook/0596007612/ch02s06.html> 