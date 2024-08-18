## CMake principal
Targets and Properties,Imagine Targets as Objects

https://www.hahack.com/codes/cmake/
https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/

### • Constructors:
• add_executable()
• add_library()

### • Member variables:
• BINARY_DIR
• COMPILE_DEFINITIONS
• COMPILE_FEATURES
• COMPILE_FLAGS
• COMPILE_OPTIONS
• CXX_STANDARD

### • Member functions:
• get_target_property()
• set_target_properties()
• get_property(TARGET)
• set_property(TARGET)
• target_compile_definitions()
• target_compile_features()
• target_compile_options()
• target_include_directories()
• target_link_libraries()
• target_sources()


## CMake 常用命令
### 最基础的6个命令
`cmake_minimum_required`
`project`
`add_executable` `add_library`
`set`
`message`

```c
cmake_minimum_required(VERSION 3.0.0)
project(code VERSION 0.1.0)
add_executable()
```

### 多个文件，且文件分布在不同的文件夹
`file`
`target_include_directories`
`target_link_libraries`
`target_sources`

https://juejin.cn/post/6844903634170298382

```cmake
cmake_minimum_required(VERSION 3.5.1)
project(vfc)

## 打包文件成VFC_INCLUDE
file(GLOB_RECURSE VFC_INCLUDE
include/*.hpp
include/*.inl
)

## 暂时不知道需要的文件
add_library(vfcHeaders INTERFACE)

## 头文件查找路径
target_include_directories(vfcHeaders INTERFACE include)

## 后续再将文件添加到target中
target_sources(vfcHeaders
INTERFACE
  ${VFC_INCLUDE}
)
```
obsolete
`include_directories` 已经被淘汰了 

### 编译选项相关
`target_compile_definitions`
target_compile_definitions(${PROJECT_NAME} PUBLIC USE_ROS)

`target_compile_features`
target_compile_features(jsonutils PRIVATE cxx_auto_type)

`target_compile_options`
target_compile_options(jsonutils PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Wall -Wextra -Wpedantic>)

### 如何适配不同操作系统(windows linux)，编译器(gcc clang msvc)
if(WIN32)
if(UNIX)
if(NOT MSVC10)
set(CMAKE_CXX_COMPILER ${DC_CUSTOM_COMPILER_PATH}/clang++)
set(CMAKE_C_COMPILER ${DC_CUSTOM_COMPILER_PATH}/clang)

### 涉及到其他的第三方库，打包成lib，并在应用它的项目中需要添加lib

`find_package`
https://zhuanlan.zhihu.com/p/97369704

1. solution 1 --> multi CMakeList.txt
`add_subdirectory`
`CMakeLists.txt`

2. solution 2 --> .cmake 文件
`include`
`XXX.cmake`

3. solution 3 --> Conan 包管理

### 单元代码怎么构建(单元测试库，生成)
gtest

### advanced 函数和宏
`function`
`macro`


## SELENA project practice
https://inside-docupedia.bosch.com/confluence/display/CCD/CMake+--+Best+Practices
selena 构建实例,构建一个target需要哪些事情
1. 内部依赖
   - 静态链接库
   - 动态链接库

2. 外部依赖
   - 基础库 `vfc` `stl` `boost`
   - 中间层 `daddy`
   - GUI `qt5`find package
   - Unit Test `gtest`

3. target 
   - selena
   - unit test executable

集成VFC
https://inside-docupedia.bosch.com/confluence/display/CCDAEHS/Integration+of+VFC+library

集成GTEST
https://github.com/google/googletest/tree/main/googletest
https://inside-docupedia.bosch.com/confluence/display/CCDAEHS/Integration+of+GoogleTest
https://www.youtube.com/watch?v=Lp1ifh9TuFI

## 文件结构的设计
* custom
  * src
  * test
    * CMakeLists.txt
  * CMakeLists.txt

## 封装CMake脚本
1. 编写CMakeLists.txt
2. 通过python call cmake
3. 通过shell 来执行python


## useful link
good article
http://derekmolloy.ie/hello-world-introductions-to-cmake/#Introduction

头文件Include
https://www.jianshu.com/p/e7de3de1b0fa
https://zhuanlan.zhihu.com/p/82244559

Effective Modern CMake
https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
https://llvm.org/docs/CMakePrimer.html
https://raw.githubusercontent.com/boostcon/cppnow_presentations_2017/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf
https://www.youtube.com/watch?v=bsXLMQ6WgIk


## 参考资料汇总
https://inside-docupedia.bosch.com/confluence/display/CCD/CMake+--+Best+Practices