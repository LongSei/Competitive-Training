#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX = 100001;
int number, a[MAX], b[MAX];
int mini = 3e9;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= number; i++) {
		cin >> b[i];
	}
	sort(a + 1, a + 1 + number);
	sort(b + 1, b + 1 + number);
	int i = 1, j = number;
	while (i <= number && j >= 1) {
		if (a[i] + b[j] == 0) {
			cout << 0;
			return 0;
		}
		int k = a[i] + b[j];
		if (abs(k) < mini) {
			mini = abs(k);
		}
		if (k < 0) {
			i++;
		}
		else {
			j--;
		}
	}
	cout << mini;
}
