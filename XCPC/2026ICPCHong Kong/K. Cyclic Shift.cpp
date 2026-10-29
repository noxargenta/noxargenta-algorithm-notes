#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000000
int n,a[N];
void solve(){
	cin>>n;
	int mn=n;
	for(int i=1;i<=n;++i){
		cin>>a[i];mn=min(mn,a[i]);
		a[i+n]=a[i];
	}
	vector<pair<int,int>>q,nq;
	for(int i=1;i<=n;++i)
		if(a[i]==mn)q.push_back({i,mn});
	int cnt;
	for(int i=1;i<n;++i){
		nq.clear();
		for(int j=0;j<q.size();++j)q[j].second=max(q[j].second,a[(q[j].first+i-1)%n+1]);
		mn=n;cnt=0;
		for(int j=0;j<q.size();++j)mn=min(mn,q[j].second);
		for(int j=0;j<q.size();++j)
			if(q[j].second==mn){
				if(cnt&&nq[cnt-1].first+i>=q[j].first&&nq[cnt-1].first+i<=n||cnt&&nq[cnt-1].first+i>n&&nq[cnt-1].first+i-n>=q[j].first)continue;
				++cnt;nq.push_back({q[j].first,mn});
			}
		q.clear();
		for(auto j:nq)q.push_back(j);
	}
	int t=q[0].first,mx=0;
	for(int i=1;i<=n;++i){
		mx=max(mx,a[t]);
		cout<<mx<<" ";
		t++;
		if(t>n)t=1;
	}
	cout<<endl;
}
signed main(){
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
} 