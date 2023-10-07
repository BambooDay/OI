#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N],cnt;
map<int,int>has;
int find(int w){
	if(has.count(w))	return has[w];
	return has[w]=++cnt;
}
bool cmp(int a,int b){
	return a>b;
}
vector<int>t[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=cnt;i++)	t[i].clear();
		has.clear();
		cnt=0;
		for(int i=1;i<=n;i++)	scanf("%d",&a[i]),t[find(a[i]-i)].push_back(a[i]);
		long long ans=0;
		for(int i=1;i<=cnt;i++){
			sort(t[i].begin(),t[i].end(),cmp);
			for(int j=1;j<t[i].size();j+=2){
				int a=t[i][j-1],b=t[i][j];
				if(a+b>0)	ans+=a+b;
				else break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
