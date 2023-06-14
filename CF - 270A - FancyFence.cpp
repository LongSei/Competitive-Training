#include<bits/stdc++.h>
using namespace std;
#define int long long
int test, angle;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> test;
    while (test--) {
        cin >> angle;
        if (360 % (180 - angle) == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
