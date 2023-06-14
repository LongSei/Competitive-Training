#include<bits/stdc++.h>
using namespace std;
 
int main() {
string s,s2,s3;
cin>>s>>s2;
int len=s.length();
 
for(int i=len-1;i>=0;i--){
	if(s[i]=='z') {
		s[i]='a';
	}
	else{
		s[i]=s[i]+1;
		break;
	}
}
 
if(s<s2){
	cout<<s;
}
else{
	cout<<"No such string";
}
return 0;
}
