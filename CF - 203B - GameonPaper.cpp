#include<bits/stdc++.h>
using namespace std;

int xnow,ynow;
int size, point;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,+1,-1,0,1};
bool check[1000][1000];
int cnt[1000][1000];
int ans;
int a, b;
bool kiemtra(int x, int y) {
	int trash = 1;
	for (int i = 0; i < 8; i++) {
		xnow = dx[i] + x;
		ynow = dy[i] + y;
		if (check[xnow][ynow] == true) {
			trash++;
		}
	}
	if (trash == 9) {
		return true;
	}
	else {
		return false;
	}
}

void ketqua(int x, int y) {
	int ko = cnt[x][y];
	for (int i = 0 ; i < 8; i++) {
		xnow = dx[i] + x;
		ynow = dy[i] + y;
		if (cnt[xnow][ynow] > ko) {
			ko = cnt[xnow][ynow];
		}
	}
	if (ko < ans && cnt[x][y] != 0) {
		ans = ko;
	}
}
int main() {
	int counti = 0;
	cin >> size >> point;
	ans = point;
	for (int i = 0; i < point; i++) {
		cin >> a >> b;
		counti++;
		check[a][b] = true;
		cnt[a][b] = counti;
	}
	int exist = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (kiemtra(i,j) == true) {
				exist = 1; 
				ketqua(i,j);
			}
		}
	} 	
	if (exist == 1) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}
