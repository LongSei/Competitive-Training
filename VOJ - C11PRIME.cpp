#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool is_prime(int p) {
    if (p < 2) return false;
    if (p == 2) return true;
    if (p % 2 == 0) return false;
    for (int d = 3; d * d <= p; d += 2) {
        if (p % d == 0) return false;
    }
    return true;
}

signed main() {
    faster;
    int n; cin >> n;
    for (int q = 2; q < 64; q++) {
        int p = round(exp(log(n) / q));
        int nn = 1;
        for (int i=0; i < q; i++) nn *= p;
        if (nn == n && is_prime(p)) {
            cout << p << ' ' << q;
            return 0;
        }
    }
    cout << 0;
}
