#include<bits/stdc++.h>
using namespace std;
const int MAX = 51;
#define int long long
char board[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0, dem = 0, n, m;
int dx[8] = {-1,-1,0,1,1, 1, 0,-1};
int dy[8] = { 0, 1,1,1,0,-1,-1,-1};
 

void ff(int x, int y, int len) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (board[nx][ny] == char(board[x][y] + 1) && visited[nx][ny] == false) {
                ff(nx, ny, len + 1);
            }
        }
    } 
    if (len > ans) {
        ans = len;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < m; j++) {
                cin >> board[i][j];
             }
         }
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++) {
                if (board[i][j] == 'A') {
                   ff(i, j, 1);
                 }
              }
        }
        cout << ans;
    }
    return 0;
}
