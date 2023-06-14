#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <map>
#include <set>
#include <list>

#define MP make_pair
#define PB push_back
#define INT_INF 0x3fffffff
#define LL_INF 0x3fffffffffffffff
#define EPS 1e-12
#define MOD 1000000007
#define PI 3.14159265358979323846
#define N 300010
#define E 100010

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef double DB;

int a[N];
int cnt;
bool vs[N];
int tot[N];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    cnt=0;
    memset(vs,0,sizeof(vs));
    memset(tot,0,sizeof(tot));
    int L=-1, R=-1, val=-1;
    for(int i=1; i<=n; i++)
    {
        tot[a[i]]++;
        if(vs[a[i]]) continue;
        vs[a[i]]=1;
        cnt++;
        if(cnt==k)
        {
            R=i;
            val=1;
            break;
        }
    }
    if(val==-1) printf("-1 -1\n");
    else
    {
        for(L=1; L<=R && tot[a[L]]!=1; L++) tot[a[L]]--;
        printf("%d %d\n",L,R);
    }
    return 0;
}
