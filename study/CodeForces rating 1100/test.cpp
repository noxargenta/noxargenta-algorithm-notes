#include<bits/stdc++.h>
using namespace std;
map <int,bool> k;
int n,m,a[100100],s[100100],l;
int main()
{
	cin>>n>>m;
	for(int x=1;x<=n;x++)cin>>a[x];
	for(int x=n;x>0;x--){//从后向前枚举 
		if(!k[a[x]])s[x]=s[x+1]+1;//优化
		else s[x]=s[x+1];
		k[a[x]]=1;
	}
	for(int x=1;x<=m;x++)cin>>l,cout<<s[l]<<endl;
	return 0;
}
