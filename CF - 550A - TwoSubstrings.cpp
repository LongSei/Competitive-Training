#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector <int> AB;
    vector <int> BA;
    for (int i=0;i<n-1;i++)
    {
        if (s[i]=='A'&&s[i+1]=='B')
        {
            AB.push_back(i);
 
        }
        if (s[i]=='B'&&s[i+1]=='A')
        {
            BA.push_back(i);
        }
    }
    int flag=-1;
    for (int i=0;i<AB.size();i++)
    {
        for (int j=0;j<BA.size();j++)
        {
            int temp=AB[i]-BA[j];
            if (abs(temp)>=2)
            {
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            break;
        }
    }
    //cout<<endl;
    if (flag==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}