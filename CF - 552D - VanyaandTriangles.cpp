#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2005;
struct Point {
	int x, y;
};
int n, ans = 0;
bool check(Point a, Point b, Point c) {
	int s1 = (b.y - a.y) * (c.x - b.x);
	int s2 = (c.y - b.y) * (b.x - a.x);
	return (s1 - s2 != 0);
}
Point arr[MAX];
signed main() {
	faster;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (check(arr[i], arr[j], arr[k]) == true) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}
