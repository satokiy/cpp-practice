#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Enter!";
  int N, v;
  cin >> N >> v;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  bool exist = false;

  for (int i = 0; i< N; i++) {
    if (a[i] == v) {
      exist = true;
      break;
    }
  }
  
  // result
  if (exist) cout << "Exist" << endl;
  else cout << "Not Exist" << endl;
}
