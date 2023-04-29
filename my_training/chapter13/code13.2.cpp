//
// 幅優先探索で
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// search start by s for graph G
vector<int> bfs(const Graph &G, int s) {
    int N = (int)G.size();
    vector<int> dist(N, -1);
    queue<int> que;

    dist[0] = 0;
    que.push(0);

    // 探索
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int x : G[v]) {
            // -1ではない => すでに探索済なのでスキップ
            if (dist[x] != -1) continue;
            // v に連結する頂点への距離は,vまでの距離+1
            dist[x] = dist[v] + 1;
            // 次の探索対象に追加
            que.push(x)
        }
    }
    return dist;
}

int main() {
    // 頂点数、辺数
    int N, M;
    cin >> N >> M;

    // create Graph
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);  // 無向グラフ
    }

    // 幅優先探索
    vector<int> dist = bfs(G, 0);
}
