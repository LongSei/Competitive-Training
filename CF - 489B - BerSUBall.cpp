#include<bits/stdc++.h>
using namespace std;
int a,b;
int ans = 0;
int arra[101];
int arrb[101];

int main() {
	cin >> a;
	for (int i = 0 ; i < a; i++) {
		cin >> arra[i];
	}
	sort(arra, arra + a);
	cin >> b;
	for (int i = 0; i < b; i++) {
		cin >> arrb[i];
	}
	sort(arrb, arrb + b);
	for (int i = 0 ; i < a; i++) {
		for (int j = 0 ; j < b; j++) {
			if (abs(arra[i] - arrb[j]) <= 1) {
				ans++;
				arra[i] = 1000;
				arrb[j] = 1000;
			}
		}
	}
	cout << ans << endl;
}
