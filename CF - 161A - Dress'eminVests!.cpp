#include<bits/stdc++.h>
using namespace std;
 
int n,m,x,y;
int a[100000], b[100000];
int cnt = 0;
bool checkb[100000], checka[100000];
int main() {
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (checkb[j] == false && checka[i] == false && a[i] - x <= b[j] && a[i] + y >= b[j]) {
				cnt++;
				a[cnt] = i;
				b[cnt] = j;
				checkb[j] = true;
				checka[i] = true;
			}
		} 
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) {
		cout << a[i] << " " << b[i] << endl;
	}
}
