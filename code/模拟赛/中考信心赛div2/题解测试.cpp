#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,ans;
int a[N],sum[N];
int fsmall[N],tsmall[N];

signed main(){
	freopen("6.in","r",stdin);
   	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		fsmall[i]=min(fsmall[i-1],sum[i]);
	for(int i=n;i>=1;i--)
		tsmall[i]=min(a[i],tsmall[i+1]+a[i]);
	for(int i=1;i<=n;i++){
		if( tsmall[i]>=0 ){
			if( sum[n]-sum[i-1]+fsmall[i-1]>=0 )
				ans++;
		}
	}
	cout<<ans;
    return 0; 
}
