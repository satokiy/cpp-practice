# 配列とポインタ

## 配列の先頭アドレス

- 配列の要素0番のアドレスのことを「配列の先頭アドレス」と呼ぶ
- 配列の先頭アドレスは、配列名を指定することで取得できる

```c:sample.c
#include <stdio.h>

int main() {
    char array[] = {1, 2, 3, 4, 5};
    char a = array[0];

    // 下記は同じ
    char* ptr = &array[0];
    char* ptr2 = array;
}
```

## 配列とポインタの関係

```c:sample.c
#include <stdio.h>

int main() {
    char array[] = {1, 2, 3, 4, 5};
    char* ptr = array;

    // 下記は同じ
    ptr[2]; // 3
    *(ptr + 2);
}
```
