#include<bits/stdc++.h>
using namespace std;
#define int long long 
string matrix[51], line;
int test, pf[51];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> test;
	while (test--) {
		cin >> line;
		int l = line.size();
		matrix[0] = line;
		for (int i = 0; i < l; i++) {
			pf[i]= 0;
			if (i > 0) {
				cin >> matrix[i];
			}
		}
		for (int i = 0; i < l; i++) {
			for (int j = i + 1; j < l; j++) {
				if (matrix[i][j] == 'N') {
					for (int k = 0 ; k < l; k++) {
						if (matrix[i][k] == 'Y' && matrix[k][j] == 'Y') {
							pf[i]++;
							pf[j]++;
							break;
						}
					}
				}
			}
		}
		int id = 0, maxi = 0;
		for (int i = 0 ; i < l; i++) {
			if (pf[i] > maxi) {
				maxi = pf[i];
				id = i;
			}
		}
		cout << id << " " << maxi << endl;
	}
}