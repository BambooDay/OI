#include<bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=200;

int n,m,k;
int r[N],d[N];
int have[N],cnt=0;
bool f[60];
int ans=0;
int dist[N];

struct ss{
	int to,nxt,v;
}edge[N*2];
int first[N],ct=0;
void add(int a,int b,int c){
	edge[++ct]={b,first[a],c};
	first[a]=ct;	
}

double Rand(){
	return rand()*1.0/RAND_MAX;
}

bool flag[N];

int fgt(){
	memset(dist,0x3f,sizeof dist);
	memset(flag,0,sizeof flag);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
	for(int i=0;i<n;i++)
		if(f[i]) dist[i]=0,Q.push({0,i});
	while(!Q.empty()){
		int t=Q.top().second;Q.pop();
		if(flag[t]) continue;
		flag[t]=1;
		for(int i=first[t];i;i=edge[i].nxt){
			int y=edge[i].to;
			if(dist[y]>dist[t]+edge[i].v){
				dist[y]=dist[t]+edge[i].v;
				Q.push({dist[y],y});
			}
		}
	}
	int mx=-2e9;
	for(int i=0;i<n;i++)
		if(!f[i]) mx=max(dist[i],mx);
	return mx;
}

void SA(){
	for(double t=200007;t>=1e-8;t*=0.999){
		int x=have[rand()%cnt+1],y=have[rand()%cnt+1];
		while(x==y||f[x]==f[y]) y=have[rand()%cnt+1];
		f[x]^=1,f[y]^=1;
		int nas=fgt();
		f[x]^=1,f[y]^=1;
		double delta=nas-ans;
		ans = min(ans,nas);
		if(exp(-delta/t)>Rand()){
			f[x]^=1,f[y]^=1;
		}
	}
}

int main(){
	double st = clock();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>r[i];
	for(int i=0;i<n;i++) cin>>d[i],add(i,r[i],d[i]),add(r[i],i,d[i]);
	for(int i=1;i<=m;i++){
		int t;cin>>t;
		f[t]=1;
	}
	for(int i=0;i<n;i++) if(!f[i]) have[++cnt]=i;
	for(int i=1;i<=k;i++) f[have[i]]=1;
	if(k+m==n){
		cout<<0<<'\n';
		return 0;
	}
	ans=fgt();
	while(double(clock()-st)/CLOCKS_PER_SEC < 0.6) SA();
	cout<<ans<<'\n';
	return 0;
}
