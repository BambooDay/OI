#include <bits/stdc++.h>
#include <queue>
#define ll long long
const int N = 5e4+10;
const int M = 2e5+10;

using namespace std;
int n, m;
int h[N],ne[M],node[M],idx = 0;
ll val[M];
void add(int u, int v, ll w){
    node[++idx] = v;
    val[idx] = w;
    ne[idx] = h[u];
    h[u] = idx;
}
ll dis[8][N];
bool v[N];
void dij(int st,int id){
    for(int i = 0; i <= n; i++){
        dis[id][i] = 1e18;
        v[i] = 0;
    }
    dis[id][st] = 0;
    priority_queue<pair<ll,int> > q;
    q.push(make_pair(-dis[id][st],st));
    while(!q.empty()){
        int t = q.top().second;
        q.pop();
        if(v[t]) continue;
        v[t] = 1;
        for(int i = h[t]; i; i = ne[i]){
            int u = node[i];
            if(dis[id][u] > dis[id][t] + val[i]){
                dis[id][u] = dis[id][t] + val[i];
                q.push(make_pair(-dis[id][u],u));
            }
        }
    }
}
ll ans = 1e18;
bool vis[10];
int c[10];
void dfs(int now, int step,ll res){
    // cout <<now << endl;
    if(step == 5){
         //cout << 1 << endl;
        ans = min(ans, res);
        return;
    }
    if(res >= ans) return;
    for(int i = 1; i <= 5; i++){
        if(vis[i]) continue;
        //cout << i << endl;
        vis[i] = 1;
        dfs(i,step+1,dis[now][c[i]]+res);
        vis[i]=0;
    }
}
int main(){
    cin >> n >> m;

    cin >> c[1]>> c[2] >> c[3] >> c[4] >> c[5];
    //    cout << n << endl;
    for(int i = 1; i <= m; i++){
        int x, y;
        ll w;
        //cout << n << endl;
        cin >> x >> y >> w;
        add(x,y,w);
        add(y,x,w);
    }
  
    dij(1,0),dij(c[1],1),dij(c[2],2),dij(c[3],3),dij(c[4],4),dij(c[5],5);
    //for(int i = 1;i <= n; i++){
    //    cout << dis[0][i] << " 111 ";
    //}
    //cout << endl;
    dfs(0,0,0);
    cout << ans << endl;
    return 0;
}