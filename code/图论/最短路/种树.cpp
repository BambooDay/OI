#include <bits/stdc++.h>
#include <queue>
const int N = 6e5+10;
const int M = 2e6+10;
#define int long long
using namespace std;
int n, m;
int sum[N];
int h[N],ne[M],node[M],val[M],idx = 0;
void add(int u, int v, int w){
    node[++idx] = v;
    val[idx] = w;
    ne[idx] = h[u];
    h[u] = idx;
}
int dis[N];
bool in[N];
void spfa(){
    queue<int> q;
    for(int i=1;i<=n;i++)
    dis[i]=-0x3f3f3f3f;
    dis[0]=0;in[0]=1;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        in[u]=0;
        for(int i=h[u];i;i=ne[i]){
            int v=node[i];
            if(dis[v]<dis[u]+val[i]){
                dis[v]=dis[u]+val[i];
                if(!in[v]){
                    q.push(v);
                    in[v]=1;
                }
            }
        }
    }
}

signed main(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        int k;
        cin >> k;
        //sum[i] = sum[i-1]+k;
        //add(0,i,0);
        add(i,i-1,-k);
        add(i-1,i,0);
    }
    for(int i = 1; i <= m; i++){
        int l,r,w;
        cin >> l >> r >> w;
        add(l-1,r,w);
    }
    spfa();
    cout << dis[n];
    return 0;
}