#include<bits/stdc++.h>
using namespace std;
#define int long long 
int test, p, a, b, c, ans = 0;
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> test;
    while(test--) {
        cin >> p >> a >> b >> c;
        if (p % a == 0 || p % b == 0 || p % c == 0) {
            cout << 0 << endl;
        }
        else {
            int x = a - (p % a);
            int y = b - (p % b);
            int z = c - (p % c);
            ans = min(x, min(y, z));
            cout << ans << endl;
        }
    }
}
