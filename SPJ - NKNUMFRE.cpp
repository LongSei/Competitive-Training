#include<bits/stdc++.h>
using namespace std;
#define MAX 30000
#define int long long
int st, en, ans = 0;
int isPrime[MAX] = {0};
void build() {
	isPrime[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i] == 0) {
			isPrime[i] = i;
			for (int q = i * 2; q <= MAX; q += i) {
				isPrime[q] = i; 
			}
		}
	}
}

void solve(int k) {
	int x = k;
	int nd = 0;
	while (x > 0) {
		nd = nd * 10 + (x % 10);
		x = (x - (x % 10)) / 10; 
	}
	//cout << "S: " << k << " ND: " << nd << endl;
	int check = min(k ,nd);
	int sl = max(k, nd);
	while (sl % isPrime[check] != 0 && check > 1) {
		check = check / isPrime[check];
	} 
	//cout << "CHECK" << endl;
	if (isPrime[check] == 1) {
		ans++;
	}
}

signed main() {
	cin >> st >> en;
	build();
	for (int i = st; i <= en; i++) {
		solve(i);
	}
	cout << ans;
}
