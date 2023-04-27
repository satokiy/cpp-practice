#include <bits/stdc++.h>
using namespace std;

// 問題
// a0, a1, a2,
// ...an-1の整数の組合せによってWを満たすことができるかどうかを判定する

// 考え方
// an - 1を選択する場合 * an - 2までの整数で「W - an-1」が成立すればOK
// an - 1を選択しない場合 * an -2までの整数で「W」が成立すればOK

vector<vector<int>> memo;

bool function(int N, int W, vector a(N)) {
    if (N == 0) {
        if (w == 0)
            return true;
        else
            return false;
    }
    if (memo[i][w] != -1) return memo[i][w];

    if function (N - 1, W, a) return true;
    if function (N - 1, W - a[N - 1], a) return true;
    return false;
}

int main() {
    int N, W;
    cin >> N, W;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    bool result = function(N, W, a);
}
