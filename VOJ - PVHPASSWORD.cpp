#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2005;
int label[MAX];
string s; 
int n;

signed main() {
    faster;
    cin >> s >> n;
    int nw = n;
    for (int i = 97; i <= 122; i++) {
        label[i] = nw % 26;
        nw++;
    }
    int ans = 0;
    for (char v : s) {
        ans += label[v];
    }
    cout << ans;
}
