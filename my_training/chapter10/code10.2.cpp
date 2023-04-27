//
// グラフの作成
//

#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

int main() {
  // 頂点数、辺数
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);

    // 無向グラフの場合、双方向にする
    G[b].push_back(a);
  }

}
