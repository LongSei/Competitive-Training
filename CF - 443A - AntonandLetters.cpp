#include<bits/stdc++.h>
using namespace std;
#define LONG_SEI_DEP_TRAI_VAI_LUA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
int check[123], cnt = 0;

signed main() {
	LONG_SEI_DEP_TRAI_VAI_LUA;
	getline(cin, s);
	for (int i = 0 ; i < s.size(); i++) {
		if (s[i] >= 97 && s[i] <= 122 && check[int(s[i])] == false) {
			cnt++;
			check[int(s[i])] = true;
		}
	}
	cout << cnt;
}