#include<bits/stdc++.h>
const int mod = 1e9 + 7; 
#define int long long
using namespace std;
int n, f1, f2, f3, c, ans;

struct Matrix {
    int size;
    int mat[6][6];
    
    Matrix(int x) {
        size = x;
        memset(mat, 0, sizeof (mat));
    }
    inline friend Matrix operator*(Matrix a, Matrix b) {//???? 
        Matrix c(a.size);
        for (int i = 1; i <= c.size; ++i)
            for (int k = 1; k <= c.size; ++k)
                for (int j = 1; j <= c.size; ++j)
                    c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % (mod - 1);
                    //??? f(p) ?? 
        return c;
    }
} baseA(3), x(3), y(3), z(3), baseB(5), w(5);

void buildfirst() {
	x.mat[3][1] = y.mat[2][1] = z.mat[1][1] = 1;
	w.mat[5][1] = 2;
	baseA.mat[1][1] = baseA.mat[1][2] = baseA.mat[1][3] = baseA.mat[2][1] = baseA.mat[3][2] = 1;
	for (int i = 1; i <= 5; i++) {
		baseB.mat[1][i] = 1;
	}
    baseB.mat[2][1] = baseB.mat[3][2] = baseB.mat[4][4] = 
    baseB.mat[4][5] = baseB.mat[5][5] = 1;
}

Matrix MatrixPow(Matrix x, int p) {//????? 
    Matrix res(x.size);
    for (int i = 1; i <= res.size; ++i) {
	 	res.mat[i][i] = 1;//???? 
    }
	for (; p; p >>= 1, x = x * x) {
        if (p & 1) res = res * x;
    }
    return res;
}

int NumPow(int x, int p) {//??? 
    int res = 1;
    for (; p; p >>= 1, x = x * x % mod)
        if (p & 1) res = res * x % mod;
    return res;
}

signed main() {
	cin >> n >> f1 >> f2 >> f3 >> c;
	buildfirst();
	baseA = MatrixPow(baseA, n - 3);
	baseB = MatrixPow(baseB, n - 3);
	w = baseB * w;
	x = baseA * x;
	y = baseA * y;
	z = baseA * z;
	ans = NumPow(c, w.mat[1][1]) % mod * NumPow(f1, x.mat[1][1]) % mod * NumPow(f2, y.mat[1][1]) % mod * NumPow(f3, z.mat[1][1]) % mod;
	cout << ans;
}

