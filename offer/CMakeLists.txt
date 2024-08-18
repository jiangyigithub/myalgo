cmake_minimum_required(VERSION 3.0.0)
project(code VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(code32a cpp/algorithm/32tree_a.cpp)
add_executable(code32b cpp/algorithm/32tree_b.cpp)
add_executable(code32c cpp/algorithm/32tree_c.cpp)
add_executable(code38 cpp/algorithm/38tree.cpp)
add_executable(code47dp cpp/algorithm/47dp.cpp)
add_executable(code48dp cpp/algorithm/48dp.cpp)
add_executable(code01stl cpp/demos/complex_test.cpp)
add_executable(code11modern cpp/modern/constexpr.cpp)
add_executable(code17 cpp/algorithm/17array.cpp)
add_executable(code22 cpp/algorithm/22pointer.cpp)
add_executable(code25 cpp/algorithm/25linked.cpp)
add_executable(code57 cpp/algorithm/57array.cpp)
add_executable(code58-1 cpp/algorithm/58string1.cpp)
add_executable(codebacktrack  cpp/algorithm/backtrack1.cpp)

aux_source_directory(. PROBLEMS)
foreach(PROBLEM ${PROBLEMS})
    get_filename_component(PROBLEM_NAME ${PROBLEM} NAME_WE)
    add_executable(${PROBLEM_NAME} ${PROBLEM})
endforeach()
# cpp/demos/string_test.cpp
# cpp/algorithm/32tree_a.cpp

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)