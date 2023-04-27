#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter";
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    // big value
    int result = 2147483647;
    
    // find minimum value
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = a[i] + b[j];
            if (value < K) continue;
            if (value < result) result = value;
        }

    cout << "result is " <<  result << endl;
}