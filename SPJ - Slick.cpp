#include<bits/stdc++.h>
using namespace std;

int N,M,x,y;
int cnt = 1;
int ans = 0;
int vetloang[150000];
int board[251][251];
vector<int> giatri;
bool check[150000];
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};

void dfs(int x,int y) {
	board[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			if (board[nx][ny] == 1) {
				cnt++;
				dfs(nx,ny);
			}
		}
	}
}

int main() {
	while (cin >> N >> M && N != 0 && M != 0) {
		giatri.clear();
		memset(vetloang, 0, sizeof vetloang);
		memset(check, 0, sizeof check);
		for (int i = 0; i < N; i++) {
			for (int j = 0 ; j < M; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0 ; i < N; i++) {
			for (int j = 0 ; j < M; j++) {
				if (board[i][j] == 1) {
					dfs(i,j);
					vetloang[cnt]++;
					ans++;
					if (check[cnt] == false) {
						giatri.push_back(cnt);
						check[cnt] = true;
					}
					cnt = 1;
				}
			}
		}
		sort(giatri.begin(), giatri.end());
		cout << ans << endl;
		ans = 0;
		for (int i = 0 ; i < giatri.size(); i++) {
			cout << giatri[i] << " " << vetloang[giatri[i]] << endl;
		}
	}
}
