#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    int  r=0,f,d,i;
    cin>>s;
    f=97;
    for(i=0;i<s.size();i++){
        d=abs(f-s[i]);
        if(d>13) d=26-d;
        r+=d;
        f=s[i];
    }
    cout<<r<<endl;
}
