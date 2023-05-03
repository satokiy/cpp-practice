# 文字列とポインタ

- 英語は1バイトで表す
  - シングルバイト文字
  - char型
- 日本語は2バイトで表す
  - マルチバイト文字
  - char型

## C言語における文字列

```c:sample.c
char str[] = {'a', 'b', 'c', '\0'};
```  

- 文字列は、文字の配列
- 文字列の最後には必ず終端文字がつく
  - 終端文字は、`\0` と表す

```c:sample.c
// text, text2は同じ
char text[] = "abc";
char* text2 = "abc";

text2 = text; // OK
text = text2; // NG
```

- 文字列は配列なので、ポインタ変数でも文字列を扱える
- text2はポインタ変数で、"a"の先頭アドレスが入っている。その中身には、"a"が入っている。
- text2の書き方では、charの配列に加え、ポインタ変数も同時に宣言している
- text2はポインタ変数なので、他の文字列の先頭アドレスを代入できる
- textは配列なので、アドレスではないので、ポインタ型変数の値を代入することはできない

## 文字列コピー

```c:sample.c
char text[] = "hello";
char* text2 = "thanks";

strcopy( text, text2 ); // エラーが発生する可能性あり
```

- C言語では文字列の上書きをする時、strcpy関数を使う
- 文字列は配列なので、上書きをすると配列の範囲外に書き込む可能性がある
  - 上記では、textの配列の長さが5で、text2の配列の長さが6なので、textの配列の範囲外に書き込む

## ポインタ型変数で宣言する場合

```c:sample.c
char* text = "hello";
text = "good morning"; // やってはいけない
```

- textはポインタ変数なので、あくまで先頭アドレスが入っている
- その値を上書きした場合、書き換えているのはポインタ変数の値なので、元の文字列の先頭アドレスが参照できなくなる  
  - 結果的に参照不能な値ができる