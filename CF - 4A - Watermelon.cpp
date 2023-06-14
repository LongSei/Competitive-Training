#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n == 2)
    {
       cout<<"no";
    }
    if(n % 2 ==  0 && n!=2)
    {
       cout<<"yes";
    }     
    if(n % 2 != 0)
    {
       cout<<"no"; 
    }    
 
}