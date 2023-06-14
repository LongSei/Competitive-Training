#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a, x, y;
signed main(){
	cin >> n >> k >> a;
	x = n / a;
	y = k / a;
	if(k%a){y++;}
	if(n%a){x++;}
	cout <<x*y;
}