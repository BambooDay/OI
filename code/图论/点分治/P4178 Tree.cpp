#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 1e5+10;
#define int long long
using namespace std;
int n,m;
int h[N],ne[M],node[M],val[M],idx;
void add(int u,int v, int w){
	node[++idx] = v;
	val[idx] = w;
	ne[idx] = h[u];
	h[u] = idx;
}

bool st[N];
int p[N],q[N];
int get_size(int u, int fa){
	if(st[u]) return 0;
	int res = 1;
	for(int i = h[u];i;i = ne[i]){
		if(node[i] == fa) continue;
		res += get_size(node[i],u);
	}
	return res;
}
int get_center(int u, int fa, int tot, int &ans){
	if(st[u]) return 0;
	int sum = 1,ma = 0;
	for(int i = h[u]; i; i = ne[i]){
		int j = node[i];
		if(j == fa) continue;
		int t = get_center(j,u,tot,ans);
		ma = max(ma,t);
		sum += t;
	}
	ma = max(ma ,tot - sum);
	if(ma <= tot/2) ans = u;
	return sum;
}
void get_dis(int u, int fa, int d, int &qcnt){
	if(st[u]) return;
	q[++qcnt] = d;
	for(int i = h[u]; i; i = ne[i]){
		if(node[i] == fa) continue;
		get_dis(node[i],u,d+val[i],qcnt);
	}
} 
int get(int a[], int k){
	sort(a+1,a+k+1);
	int res = 0;
	for(int i = k,j = 0; i; i--){
		while(j+1 < i && a[j+1] + a[i] <= m) j++;
		j = min(j,i-1);
		res += j;
	}
	return res;
}
int calc(int u){
	if(st[u]) return 0;
	int res = 0;
	get_center(u,-1,get_size(u,0),u);
	st[u] = 1;
	int pcnt = 0;
	for(int i = h[u]; i; i = ne[i]){
		int j = node[i];
		int qcnt = 0;
		get_dis(j,0,val[i],qcnt);
		res -= get(q,qcnt);
		for(int k = 1; k <= qcnt; k++){
			if(q[k] <= m) res++;
			p[++pcnt] = q[k];
		}
	}
	res += get(p,pcnt);
	for(int i = h[u]; i; i = ne[i]) res += calc(node[i]);
	return res;
}
signed main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	cin >> m;
	cout << calc(1);
	return 0;
}
