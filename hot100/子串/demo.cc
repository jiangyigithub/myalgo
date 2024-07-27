#include <stdio.h>

int main() {
    char c = 'A';
    int ascii_value = c;  // 隐式转换
    printf("The ASCII value of %c is %d\n", c, ascii_value);  // 输出: The ASCII value of A is 65
    return 0;
}