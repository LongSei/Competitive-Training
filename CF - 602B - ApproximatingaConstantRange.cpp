#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
#define ll long long
/*ll min(ll a , ll b){
    return a < b?a:b;
}
ll max(ll a , ll b) {
    return (a>b?a:b);
}*/
int main()
{
    //cout << "Hello World!" << endl;
    ll n , x;
    cin >> n;
    ll a[n];
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }//cout << a[0];
    ll lmin = a[0] , lmax = a[0] , cnt = 1 , ans = -1;
    for(ll i = 1 ; i < n  ; i++)
    {

        if(abs(a[i] - lmin) <= 1 && abs(a[i] - lmax) <= 1)
        {
            lmin = min(a[i] , lmin);
            lmax = max(a[i] , lmax);
            ++cnt;
        }
        else
        {
            //cout << cnt << " ";
            ans = max(cnt , ans);
            lmin = a[i];
            lmax = a[i];
            cnt = 0;
            for(ll j = i ; j >= 0 ; j--)
            {
                if(abs(a[j] - lmin) <= 1 && abs(a[j] - lmax) <= 1)
                {
                    lmin = min(a[j] , lmin);
                    lmax = max(a[j] , lmax);
                    cnt++;
                }
                else
                    break;
            }
            //ans = max(cnt , ans);
        }
    }
    cout << max(ans,cnt);
    return 0;
}
