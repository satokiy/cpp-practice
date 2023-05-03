# 構造体ポインタ

## 構造体の型の宣言

```c:sample.c
// 型の宣言
typedef int SAMPLE

// 構造体の型の宣言
typedef struct point {
    int x;
    int y;
} POINT;
```

## アロー演算子



```c:sample.c
int main() {
    // 構造体変数の宣言
    POINT position;
    
    // 構造体ポインタの宣言
    POINT* ptr;
    ptr = &position;
    
    ptr->x = 50;
    position.x = 100;
}
```

- 構造体ポインタのメンバー変数にアクセスする場合は、`->` を使う
  - アロー演算子と呼ぶ

## 構造体ポインタを使うメリット

```c:sample.c
POINT position;
void SetPosition(POINT pos) {
    position = pos;
}

POINT GetPosition() {
    return position;
}


int main() {
    POINT pt={10, 20};
    SetPosition(pt);
}
```

- 上記のコードは構造体をそのまま渡している
- 構造体が小さければ問題ないが、大きい場合はコピーに時間がかかる

```c:sample.c
POINT position;

void SetPosition(POINT* pos) {
    position = *pos;
}

POINT* GetPosition() {
    return &position;
}
```

- 上記のコードではポインタ変数を通じて構造体をやりとりしている
- ポインタ変数は8バイト程度なので、コピーに時間がかからない

```c:sample.c
void SetPosition2(const POINT* pos) {
    position = *pos; // エラー
}
```

- constをつけると、関数内で構造体の値を変更できなくなる

## 構造体ポインタの足し算

```c:sample.c
typedef struct human {
    short age;
    short weight;
    short height;
} HUMAN;

HUMAN student[2];

int main() {
    HUMAN* p_person = student;
    p_person->weight = 50; // student[0].weight = 50;
    p_person++; // student[1]
}
```

- 構造体ポインタの足し算は、構造体のサイズ分だけ足される
  - 上記ではHUMAN構造体のサイズ分だけインクリメントされるので、`student[1]`が取得される
  - これは配列のポインタと同じ

## 構造体ポインタの注意点

```c:sample.c
int main() {
    // short型の例
    short number = 5;
    char* ptr = (char*)&number;
    ptr++;

    // 構造体でやると
    HUMAN human;
    char* ptr2 = (char*)&human;
    ptr2 ++;
}
```

- 上記のように、型をcharにキャストすると、インクリメントをしても1バイト分しかアドレスが移動しない
- short型の例では、2バイト分のメモリを確保しているnumberという変数に対して、アドレスが1バイト分しか移動しない
- 構造体においても同様で、構造体のメンバー変数のアドレスが1バイト分しか移動しない
  - 結果的にバグにつながる
- 構造体でポインタを利用する際には、必ず構造体ポインタを用い、アロー演算子`->`を使ってメンバー変数にアクセスすること

### 構造体のサイズについて

```c:sample.c
typedef struct human {
    char age;
    short weight;
    short height;
} HUMAN;

sizeof(HUMAN); // 5とは限らない。6の場合もある。
```

- 例えば上記のHUMAN構造体について、sizeof(HUMAN)を実行すると、5とは限らない
  - 単純計算するとchar(1 byte) + short(2 byte) *2 = 5 byteになるが、コンピューターによっては奇数番目からメモリを確保することが禁止されているケースがある
  - その場合、HUMAN構造体のサイズは6になる
