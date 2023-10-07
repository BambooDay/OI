#include <bits/stdc++.h>
#define int long long
const int N = 2e5+10;
using namespace std;
struct edge{
    int u, v, w,pos;
}e[N];
int m = 0;
bool cmp(edge x, edge y){
    return x.w < y.w;
}
bool ans[N];
int val[N];

int h[N],ne[N<<1],node[N<<1],idx = 0;
void add(int u, int v){
    node[++idx] = v;
    ne[idx] = h[u];
    h[u] = idx;
}
int L[N],R[N],cur = 0;
void dfs(int pos, int fa){
    bool f = 1;
    L[pos] = 1e9;
    for(int i = h[pos];i;i = ne[i]){
        int to = node[i];
        if(to == fa) continue;
        f = 0;
        dfs(to,pos);
        L[pos] = min(L[pos],L[to]),R[pos] = max(R[pos],R[to]);
    }
    if(f) L[pos] = R[pos] = ++cur;
    e[++m].u = L[pos],e[m].v = R[pos]+1,e[m].w = val[pos],e[m].pos = pos;
    
}

int fa[N];
int get(int x){
    return fa[x] == x ? fa[x] : fa[x] = get(fa[x]);
}
int n;
int tot = 0;
int sum = 0;
void kruskal(){
    for(int i = 1; i <= n+1; i++) fa[i] = i;
    sort(e+1,e+1+m, cmp);
    for(int l = 1; l <= n;){
        int r=l;
        while(r+1 <= n && e[r].w == e[r+1].w){
            r++;
        }
        for(int i = l; i <= r; i++){
            if(get(e[i].u) != get(e[i].v)){
                ans[e[i].pos] = 1;
                tot++;
            }
        }
        for(int i = l; i <= r; i++){
            int fu = get(e[i].u),fv = get(e[i].v);
            if(fu != fv){
                fa[fu] = fv;
                sum += e[i].w;
            }
        }
        l = r+1;
    }
    cout << sum <<" " << tot << endl;
}
signed main(){
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> val[i];
    }
    for(int i = 1;i <n; i++){
        int u, v;
        cin >> u >> v;
        add(u,v),add(v,u);
    }
    dfs(1,0);
    kruskal();
    for(int i = 1;i <= n; i++){
        if(ans[i]) cout << i << ' ';
    }
    return 0;
}