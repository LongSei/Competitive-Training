#include<bits/stdc++.h>
using namespace std;

int sizex, sizey;
char chr;
int board[501][501];
bool check[501][501] = {false};
int startx, starty, endx, endy;
//(x,y+1)(x,y-1)(x+1,y)(x-1,y)
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void flf(int x, int y) {
	if (board[x][y] == 0) {
		check[x][y] = true;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= sizex && ny >= 1 && ny <= sizey) {
			if (check[nx][ny] == false) {
				board[nx][ny]--;
				if (board[nx][ny] > 0 || (nx == endx && ny == endy)) {
					flf(nx,ny);
				}
			}
		}
	}
}

int main() {
	cin >> sizex >> sizey;
	for (int i = 1; i <= sizex; i++) {
		for (int j = 1; j <= sizey; j++) {
			cin >> chr;
			if (chr == 'X') {
				board[i][j] = 1;
			}
			else {
				board[i][j] = 2;
			}
		}
	}
	cin >> startx >> starty >> endx >> endy;
	board[startx][starty] = 1;
	flf(startx,starty);
	if (board[endx][endy] == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

