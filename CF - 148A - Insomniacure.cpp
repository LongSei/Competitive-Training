#include<bits/stdc++.h>
using namespace std;
#define int long long
int k, l, m, n, d;
const int MAX = 1e5 + 1;
int isPrime[MAX], ans = 0;

void build(int a, int b) {
    isPrime[a] = a;
    int q = a * 2;
    while (q <= b) {
        isPrime[q] = a;
        q += a;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k >> l >> m >> d >> n;
    memset(isPrime, 0, sizeof isPrime);
    build(k, n);
    build(l, n);
    build(m, n);
    build(d, n);
    for (int i = 1; i <= n; i++) {
        if (isPrime[i] == 0) {
            ans++;
        }
    }
    cout << n - ans;
}