#include <bits/stdc++.h>
#define int long long
const int N = 1e6+10;
using namespace std;
inline int read(){
	int ans=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n, m;
int h1[N], ne1[N], node1[N],val1[N];
int idx1 = 0;
void add1(int u, int v, int w){
    node1[++idx1] = v;
    val1[idx1] = w;
    ne1[idx1] = h1[u];
    h1[u] = idx1;
}
int h2[N], ne2[N], node2[N];
int idx2 = 0;
void add2(int u, int v){
    node2[++idx2] = v;
    ne2[idx2] = h2[u];
    h2[u] = idx2;
}

struct Node{
    int ans,h;
}node[N];
struct edge{
    int u,v,h;
}e[N];
bool cmp(edge x, edge y){
    return x.h > y.h;
}

int dis[N];
bool vis[N];
void dij(){
    fill(dis,dis+n+1,1e18);
    fill(vis,vis+1+n,0);
    dis[1] = 0;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(-dis[1],1));
    while(!q.empty()){
        int t = q.top().second;
        q.pop();
        if(vis[t]) continue;
        vis[t] = 1;
        for(int i = h1[t]; i; i = ne1[i]){
            int v = node1[i];
            if(dis[v] > dis[t]+val1[i]){
                dis[v] = dis[t] + val1[i];
                q.push(make_pair(-dis[v],v));
            }
        }
    }
    for(int i =1 ;i <= n; i++){
        node[i].ans = dis[i];
    }
}

int fa[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int kruskal(){
    int cnt = n,tot = 0;
    for(int i =1; i <= n*2; i++) fa[i] = i;
    sort(e+1,e+1+m, cmp);
    for(int i =1 ; i <= m; i++){
        int u = e[i].u, v = e[i].v, h = e[i].h;
        int fu = get(u),fv = get(v);
        if(fu != fv){
            fa[fu] = fa[fv] = ++cnt;
            node[cnt].h = h;
            add2(cnt,fu),add2(cnt,fv);
            tot++;
        }
        if(tot == n-1) return cnt;
    }
    return cnt;
    
}

int dep[N],f[N][25];
void dfs(int pos, int father){
    dep[pos] = dep[father]+1;
    f[pos][0] = father;
    for(int i = 1; i <= 19; i++){
        f[pos][i] = f[f[pos][i-1]][i-1];
    }
    for(int i = h2[pos]; i; i= ne2[i]){
        int to = node2[i];
        dfs(to,pos);
        node[pos].ans = min(node[pos].ans,node[to].ans);
    }
}

void solve(){
    //return;
    n=read(),m=read();
    fill(h1,h1+n+1,0);
    fill(h2,h2 + n*2+1, 0);
    idx1 = idx2 = 0;
    for(int i = 0; i <= n*2+1; i++) node[i].ans = 1e18;
    //return;
    memset(f,0,sizeof f);
    memset(e,0,sizeof e);
    for(int i = 1; i <= m; i++){
        int u, v, l, a;
        u=read(), v=read(), l=read() , a=read();
        add1(u,v,l);
        add1(v,u,l);
        e[i].u = u,e[i].v = v,e[i].h = a;
    }
    //return;
    dij();
    //return;
    int cnt = kruskal();
    dfs(cnt,0);
    //return;
    int q, k, s;
    int lastans = 0;
    q=read() ,k =read(), s = read();
    while(q--){
        int v0,p0;
        v0 =read(), p0 = read();
        int st = (v0+k*lastans-1)%n+1,p = (p0+k*lastans)%(s+1);
        for(int i = 19; i >=0 ; i--){
            if(dep[st] - (1 << i) > 0 && node[f[st][i]].h > p) st = f[st][i];
        }
        write(lastans = node[st].ans);
        puts("");
    }
}
signed main(){
    //freopen("return6.in","r",stdin);
    //return 0;
    int t;
    t = read();
    while(t--) solve();
    return 0;
}