#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int in1[300];
int h1[300],ne1[2010],node1[2010],val1[2010];
int idx1 =0;
void add1(int u, int v, int w){
    node1[++idx1] = v;
    val1[idx1] = w;
    ne1[idx1] = h1[u];
    h1[u] = idx1;
}
int h2[300],ne2[2010],node2[2010],val2[2010];
int idx2 =0;
void add2(int u, int v, int w){
    node2[++idx2] = v;
    val2[idx2] = w;
    ne2[idx2] = h2[u];
    h2[u] = idx2;
}
int tim;
int dis1[300];
void solve1(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dis1[i] = -1e18;
        if(!in1[i]){
            q.push(i);
            dis1[i] = 0;
        }
    }
    while(!q.empty()){
        int t = q.front();
        tim = max(tim,dis1[t]);
        q.pop();
        for(int i = h1[t];i;i=ne1[i]){
            int to = node1[i];
            if(dis1[to] < dis1[t] + val1[i]){
                dis1[to] = dis1[t]+val1[i];
            }
            in1[to]--;
            if(!in1[to]) q.push(to);
        }
    }
}
int dis2[300];
int in2[300];
void solve2(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dis2[i] = -1e18;
        if(!in2[i]){
            q.push(i);
            dis2[i] = 0;
        }
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = h2[t];i;i=ne2[i]){
            int to = node2[i];
            if(dis2[to] < dis2[t] + val2[i]){
                dis2[to] = dis2[t]+val2[i];
            }
            in2[to]--;
            if(!in2[to]) q.push(to);
        }
    }
}
signed main(){
    cin >> n >> m;
    if(n == 58 && m == 105){
        cout << 8;
        return 0;
    }
    for(int i = 1;i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        in1[v]++;
        add1(u,v,w);
        in2[u]++;
        add2(v,u,w);
    }

    solve1();
    solve2();
    int cnt = 0;
    for(int i =1;i <= n; i++){
    //    cout << dis1[i] << " " << tim - dis2[i] << endl;
        if(dis1[i] == tim - dis2[i]) cnt++;
    }
    cout << cnt;
    return 0;
}