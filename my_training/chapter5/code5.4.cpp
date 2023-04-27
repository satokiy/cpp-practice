#include <bits/stdc++.h>;
using namespace std;

// カエル問題を動的計画法によってとく
// 配る遷移方式
// n-1番目へのいき方は、n-2 + 差分 or n-3 + 差分 の最小値

template <class T>
void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    int N;
    vector<int> h, dp;
    const INF = 1LL << 60;
    // 初期化
    cin >> N;
    for (int i = 0; i < N; i++) cin >> h[i];
    dp.assign(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N, i++) {
        if (i == 0) {
            dp[i + 1] = abs(h[i] - h[i + 1]);
        } else {
            dp[i+1] = chmin(dp[i+1], dp[i] + abs(h[i] - h[i + 1]),
                        dp[i] + abs(h[i] - h[i - 2]))
        }
    }

    cout << dp[N - 1] << endl;
}