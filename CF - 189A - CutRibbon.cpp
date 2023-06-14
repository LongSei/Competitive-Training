#include<bits/stdc++.h>
using namespace std;

int n,a,b,c;
int main() {
	cin >> n >> a >> b >> c;
	int pieces = 0;
	for (int i = 0 ; i * a <= n; i++) {
		for (int j = 0 ; j * b <= n; j++) {
			if ((n - (i * a) - (j * b)) % c == 0 && (n - (i * a) - (j * b)) >= 0) {
				int check = i + j + ((n - (i * a) - (j * b)) / c);
				if (check > pieces) {
					pieces = check;
				}
			}
		}
	}
	cout << pieces;
}
