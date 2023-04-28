//
// グラフ探索の実装
//

#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// search start by s for graph G
void search(const Graph &G, ins s) {
    // 頂点数
    int N = (int)G.size();

    // data structure for Graph search
    // seen: 見つかっている頂点
    // todo: 見つかっているが、未訪問の頂点
    vector<bool> seen(N, false);  // すべての頂点に対して、未訪問で初期化
    // queueはFIFO。つまり幅優先探索になる。stackにすればLIFOなので深さ優先探索
    queue<int> todo;  // 初期は空

    // 初期条件
    seen[s] = true;  // 頂点は見つかっている
    todo.push(s);    // 頂点は訪問済み

    // 探索
    while (todo.empty()) {
        // todoから取り出す
        int v = todo.front();
        todo.pop();

        // 現在の頂点に連結する頂点でループ
        for (int x : G[v]) {
            // すでに見つかっている場合はスキップ
            if (seen[x]) {
                continue;
            } else {
                // 見つかった印をつける
                seen[x] = true;
                // todoに追加する
                todo.push(x);
            }
        }
    }
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
    }

    // search
    search(G, 0)
}
