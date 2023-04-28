//
// 重み付きグラフの作成
//

#include <iostream>
#include <vector>
using namespace std;

// 辺の定義
struct Edge {
    int to;            // 隣接する頂点
    long long weight;  // 重み
    Edge(int to, long long weight) : to(to), w(w) {}
}

using Graph = vector<vector<Edge>>;

int main() {
    int N, M;
    cin >> N >> M;

    // graph
    for (int i = 0; i < M, i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
}