#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int test, n;
int ls[MAX + 1];
int maxa[MAX + 1];

void build() {
	ls[1] = 1;
	ls[0] = 0;
	maxa[0] = 0;
	maxa[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		ls[i] = ls[i/2] + i%2 * ls[i/2+1];
		maxa[i] = max(maxa[i-1], ls[i]);
	}
}

int main() {
	cin >> test;
	build();
	while (test--) {
		scanf("%d", &n);
		printf("%d\n", maxa[n]);
	}
}
