#include<bits/stdc++.h>
using namespace std;

int n,a,b;
int arr[2001];

void xep() {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n ;j++) {
			if (arr[i] > arr[j]) {
				int p = arr[i];
				arr[i] = arr[j];
				arr[j] = p;
			}
		}
	}
}

int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	xep();
	cout << arr[n - a + 1] - arr[b];
}
