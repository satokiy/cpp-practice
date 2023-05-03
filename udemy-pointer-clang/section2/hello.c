#include <stdio.h>

int main() {
    char value = 5;
    // ポインタ変数の宣言
    char* ptr = &value;
    // 間接演算子
    *ptr = 100;
    printf("value: %d\n", value);
    printf("ptr: %p\n", ptr);

}