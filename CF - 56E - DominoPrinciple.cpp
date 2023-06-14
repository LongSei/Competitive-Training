#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
stack<int> st;
pii A[MAX];
int n, ans[MAX]; 

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x,h;
        cin >> x >> h;
        A[i] = make_pair(x, ii(h, i));
    }    
    sort(A + 1, A + 1 + n);
    for (int i = n; i >= 1; i--) {
        ans[A[i].second.second] = 1;
        while (st.empty() == false && A[i].first + A[i].second.first > A[st.top()].first) {
            ans[A[i].second.second] += ans[A[st.top()].second.second];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    faster;
    input();
}
