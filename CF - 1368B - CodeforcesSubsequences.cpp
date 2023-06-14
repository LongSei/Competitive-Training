#include<bits/stdc++.h>
using namespace std;
#define LONG_SEI_DEP_TRAI_VAI_LUA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
int n, cnt[11];
int sqr(int x) {
    return x*x;
}
int pow(int a, int b) {
    if (b == 0) return 1;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b/2));
        else
            return a * (sqr(pow(a, b/2)));
}

signed main() {
	LONG_SEI_DEP_TRAI_VAI_LUA;
	cin >> n;
	int sum=1;
	string s="codeforces";
	int l=1;
	while(pow(l+1,10)<=n){
		l++;
	}
	for(int i=0;i<10;i++){
		cnt[i]+=l;
		sum*=cnt[i];
	};
	for(int i=0;sum<n;i=((i+1)%10)){
		sum/=cnt[i];
		cnt[i]++;
		sum*=cnt[i];
	}
	for(int i=0;i<10;i++){
		while(cnt[i]--){
			cout<<s[i];
		}
	}
}