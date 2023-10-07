#include <bits/stdc++.h>
const int N = 2e5+10;
const int M = 6e5+10;
using namespace std;
int n, m;
int h[N],ne[M],node[M],idx = 0;
void add(int u, int v){
    node[++idx] = v;
    ne[idx] = h[u];
    h[u] = idx;
}
int fa[N];
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
int f[N][25],dep[N];
void dfs(int pos, int ff){
    dep[pos] = dep[ff]+1;
    f[pos][0] = ff;
    for(int i = 1; i <= 20; i++){
        f[pos][i] = f[f[pos][i-1]][i-1];
    }
    for(int i = h[pos]; i; i = ne[i]){
        int t = node[i];
        if(t == ff) continue;
        dfs(t,pos);
    }
}
int LCA(int x, int y){
    if(dep[x] < dep[y]) swap(x,y);
    for(int i = 20; i >= 0; i--){
        if(dep[f[x][i]] >= dep[y]) x = f[x][i];
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--){
        if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
struct edge{
    int u, v, w;
}e[M];
bool cmp(edge x, edge y){
    return x.w < y.w;
}
int val[N];
void kruskal(){
    int cnt = n,tot=0;
    for(int i = 1; i <= 2*n; i++) fa[i] = i;
    sort(e+1,e+1+m,cmp);
    for(int i = 1; i <= m;i++){
        int fu = get(e[i].u),fv = get(e[i].v);
        if(fu != fv){
            fa[fu] = fa[fv] = ++cnt;
            val[cnt] = e[i].w;
            add(cnt,fu),add(cnt,fv);
            tot++;
        }
        if(tot==n-1) break;
    }
    for(int i = 1; i <= n; i++){
        if(!dep[i]){
            dfs(get(i),0);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        if(get(x) != get(y)){
            cout << "impossible" << endl;
            continue;
        }
        int lca = LCA(x,y);
        // cout << lca << " ";
        cout << val[lca] << endl;
    }
    return 0;
}