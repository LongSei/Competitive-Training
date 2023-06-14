#include<bits/stdc++.h>
using namespace std;

int main() {
	int prorequire, pret;
	cin >> prorequire >> pret;
	int arr[1000];
	int re[1000];
	for (int i = 1; i <= prorequire; i++) {
		cin >> re[i];
	}
	for (int i = 1; i <= pret; i++) {
		cin >> arr[i];
	}
	int o = prorequire;
	int cnt = 0;
	int j;
	for (int i = 1; i <= prorequire; i++) {
		while(j <= pret){
                if(arr[j]>=re[i])
                {
                    cnt++;
                    i++;
                }
                j++;
            }
	}
	if (prorequire - cnt > 0) {
		cout << prorequire - cnt;
	}
	else {
		cout << 0;
	}
}
