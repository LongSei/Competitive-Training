#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define real long double
#define ii pair<int, int> 
#define pii pair<int, ii> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 100005;
int arr[MAX], n, m;
map<int, int> phi;
int counting(int n) {
    if (phi.count(n)) {
        return phi[n];
    } 
    int result = n; int save = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return phi[save] = result;
}
 
int bpow(int n, int k, int mod) {
    int res = 1; int checking = n >= mod;
    while (k) {
        if (k & 1) {
            res = res * n;
            if (res >= mod) {
                checking = 1;
                res %= mod;
            }
        }
        n = n * n;
        if (n >= mod) {
            checking = 1;
            n %= mod;
        }
        k >>= 1;
    }
    return res + checking * mod;
} 

int solve(int left, int right, int mod) {     
    if (left == right) {
        return arr[left];
    }    
    if (mod == 1) {
        return 1;
    }    

    return bpow(arr[left], solve(left + 1, right, counting(mod)), mod);
}

signed main() {
    faster;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int test; cin >> test;
    while (test--) {
        int u, v; cin >> u >> v;
        cout << solve(u, v, m) % m << endl;
    }
}
