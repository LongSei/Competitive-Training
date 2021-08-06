#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int a, b, c;
signed main() {
    faster;
    while (cin >> a >> b >> c) {
        int range1 = b - a - 1;
        int range2 = c - b - 1;
        cout << max(range1, range2) << endl;
    }
}
