#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 6666666 + 10;
const int M = 2e6 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;


int node[N],ne[N],h[N],val[N],h1[N];
int idx=1,n,m,q,in1,in2,cnt,tt,tot;
int dfn[N],rnk[N],son[N],top[N],siz[N],dep[N],fa[N];
int low[N],dfnt[N],sk[N];
int sum[N];

void add(int h[],int u,int v){idx++;node[idx]=v;ne[idx]=h[u];h[u]=idx;}

stack<int> st;
void tarjan(int pos,int e){
	dfn[pos] = ++cnt;
	low[pos] = dfn[pos];
	st.push(pos);
	int son = 0;
	for(int i = h[pos];i;i = ne[i]){
		if(i == (e^1)) continue;
		int to = node[i];
		if(!dfn[to]){
			son++;
			tarjan(to,i);
			low[pos] = min(low[pos],low[to]);
			if(dfn[pos] <= low[to]){
				tot++;
				val[pos] = 1;
				add(h1,tot,pos);
				add(h1,pos,tot);
				while(st.top() != to){
					add(h1,tot,st.top());
					add(h1,st.top(),tot);
					val[st.top()] = 1;
					st.pop();
				}
				st.pop();
				add(h1,tot,to);
				add(h1,to,tot);
				val[to] = 1;
			}
		}else low[pos]= min(low[pos],dfn[to]);
	}

}

void dfs_1(int s,int gr){//常规树剖
    dep[s]=dep[gr]+1;fa[s]=gr;
    siz[s]=1;son[s]=-1;
    for(int i=h1[s];i;i=ne[i]){
        int v=node[i];
        if(v==gr) continue;
        dfs_1(v,s);
        siz[s]+=siz[v];
        if(son[s]==-1||siz[v]>siz[son[s]]) son[s]=v;
    }
}

void dfs_2(int s,int tp){
    top[s]=tp;
    if(son[s]==-1) return ;
    dfs_2(son[s],tp);
    for(int i=h1[s];i;i=ne[i]){
        int v=node[i];
        if(v==fa[s]||v==son[s]) continue;
        dfs_2(v,v);
    }
}

void dfs3(int s){//常规预处理
    sum[s]=sum[fa[s]]+val[s];
    for(int i=h1[s];i;i=ne[i]){
        int v=node[i];
        if(v==fa[s]) continue;
        dfs3(v);
    }
}

int LCA(int x,int y){//常规lca
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]>dep[y]?y:x;
}


int main() {
//	freopen("P4320_11.in","r",stdin);
	int n, m;
	cin >> n >> m;
	for(int i =1; i <= m ;i++){
		int x, y;
		cin >> x >> y;
		add(h,x,y);
		add(h,y,x);
	}
	tot = n;
	tarjan(1,0);
	cnt = 0;
	dfs_1(1,0),dfs_2(1,1),dfs3(1);
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		int lca = LCA(x,y);
		cout << sum[x] + sum[y] - sum[lca] - sum[fa[lca]]<< endl;
	}
	return 0;
}
