#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 1e5 + 1;
int test, n, arr[MAX];
typedef pair<int, int> ii;
vector<pair<int, int> > gt;
 
signed main() {
    faster;
    cin >> test;
    while (test--) {
        gt.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++) {
            int l = i, r = i;
            while (arr[r + 1] <= arr[l] && r + 1 <= n) {
                r++;
            }
            gt.push_back(ii(l, r));
            //cout << "I: " << i << " L: " << l << " R: " << r << endl;
            i = r;
        }
        for (int i = gt.size() - 1; i >= 0; i--) {
            ii vu = gt[i];
            int l = vu.first;
            int r = vu.second;
            //cout << i << "GT: " << l << " " << r << endl;
            for (int i = l; i <= r; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}