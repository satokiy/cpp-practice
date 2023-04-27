#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
    if (n == 0) return m;
    int r = m % n;
    return gcd(n, r);
}

int main() { cout << gcd(120, 64) << endl; }