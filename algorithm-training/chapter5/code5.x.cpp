#include <bits/stdc++.h>;
using namespace std;

// カエル問題を動的計画法によってとく
// n-1番目へのいき方は、n-2 + 差分 or n-3 + 差分 の最小値

int func(int n, vector<int> h) {
    if (n == 0) return 0;
    return min(func(n - 1) + abs(h[n - 1] - h[n - 2]),
               func(n - 2) + abs(h[n - 1] - h[n - 3]))
}

int main() {
    int N;
    vector<int> h, dp;
    const INF = 1LL << 60;
    // 初期化
    cin >> N;
    for (int i = 0; i < N; i++) cin >> h[i];
    dp.assign(N, INF);

    for (int i = 0; i < N, i++) {
        if (i == 0) {
            dp[i] = 0;
        } else if (i == 1) {
            dp[i] = abs(h[i] - h[i - 1]);
        } else {
            dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                        dp[i - 2] + abs(h[i] - h[i - 2]))
        }
    }

    cout << dp[N - 1] << endl;
}