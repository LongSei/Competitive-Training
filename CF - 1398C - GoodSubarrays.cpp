#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 1e5 + 1;
int test, n, arr[MAX];
string s;

signed main() {
    faster;
    cin >> test;
    while (test--) {
        map<int, int> cnt;
        cin >> n >> s;
        int sum = 0, ans = 0;
        cnt[0] ++;
        for (int i = 0; i < n; i++) {
            sum += (s[i] - '0') - 1;
            ans += cnt[sum];
            cnt[sum]++;
        }
        cout << ans << endl;
    }
}