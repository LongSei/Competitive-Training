#include<bits/stdc++.h>
using namespace std;

int M,N,sx,sy,ex,ey;

char board[21][21];
bool visited[21][21] = {false};

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int searchse(){
	int cnt = 0;
	for (int i=0;i<M;i++)
		for (int j =0;j<N;j++)
			if ((i==0||i==M-1||j==0||j==N-1)&&board[i][j]=='.'){
	            if (cnt==0){
	                sx = i;
	                sy = j;
	            }
	            else if (cnt==1){
	                ex = i;
	                ey = j;
	            }
	            else {
					return 0;
	            }
				cnt++;
	        }
    if (cnt==2)
        return 1;
    else return 0;
}

bool dfs(int x, int y) {
	if (x == ex && y == ey) {
		return true;
	}
	if (visited[x][y] == true) {
		return false;
	}
	if (board[x][y] == '#') {
		return false;
	}
	visited[x][y] = true;
	for (int i = 0 ; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (board[nx][ny] == '.' && nx >= 0 && nx < M && ny >= 0 && ny < N) {
			if (dfs(nx,ny) == true) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		cin >> M >> N;
		for (int i = 0 ; i < M; i++) {
			for (int j = 0 ; j < N; j++) {
				cin >> board[i][j];
				visited[i][j] = false;
			}
		}
		if (searchse() == 1 && dfs(sx,sy) == true) {
			cout << "valid" << endl;
		}
		else {
			cout << "invalid" << endl;
		}
	}
}
