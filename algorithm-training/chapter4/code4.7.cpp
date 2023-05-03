#include <bits/stdc++.h>
using namespace std;

// フィボナッチ数列。まずは普通に作成し、その後メモ化を活用して高速にする

vector<int> memo;

long long fibo(int n) {
    // 初期化
    
    memo[0] = 0;
    memo[1] = 1;

    if (n == 0) return memo[0];
    if (n == 1) return memo[1];
    if (memo[n] != -1) {
        return memo[n];
    } else {
        cout << "call fibo: " << n << endl;
        memo[n] = fibo(n - 1) + fibo(n - 2);
        return memo[n];
    };
    
    
}

int main() {
    memo.assign(50, -1);
    cout << fibo(50) << endl;
  }