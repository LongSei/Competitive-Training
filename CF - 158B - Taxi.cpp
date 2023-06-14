#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 1;
int n, arr[MAX], cnt[5], ans = 0;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    // for (int i = 1; i <= 4; i++) {
    //     cout << "CNT: " << cnt[i] << endl;
    // }
    //with 2, 4
    ans += cnt[4];
    ans += cnt[2] / 2;
    cnt[2] = cnt[2] % 2;

    //with 3, 1
    int mini, maxi;
    if (cnt[3] < cnt[1]) {
        mini = 3;
        maxi = 1;
    }
    else {
        mini = 1;
        maxi = 3;
    }
    ans += cnt[mini];
    cnt[maxi] -= cnt[mini];
    if (maxi == 3) {
        ans += cnt[maxi] + cnt[2];
    }
    else {
        int sct = cnt[1];
        if (cnt[2] == 1) {
            ans += 1;
            cnt[1]-= 2;
        }
        if (cnt[1] < 0) {
            cnt[1] = 0;
        }
        if (cnt[1] % 4 != 0)
            sct = (cnt[1] + (4 - (cnt[1] % 4)));
        ans += sct / 4;
    }
    cout << ans;
}
