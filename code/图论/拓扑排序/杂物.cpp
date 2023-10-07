#include <bits/stdc++.h>
const int N = 4e4+10;
#define int long long
using namespace std;
int n;
int val[N];
int tim[N];
int h[N],ne[100*N],node[100+N];
int idx = 0;
void add(int u, int v){
    node[++idx] = v;
    ne[idx] = h[u];
    h[u] = idx;
}
int in[N];
void solve(){
    queue<int> q;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        val[u] += tim[u];
        q.pop();
        ans = max(ans,val[u]);
        for(int i = h[u];i;i = ne[i]){
            int to = node[i];
            in[to]--;
            tim[to]= max(val[u],tim[to]);
            if(!in[to]) q.push(to);
        }
    }
    cout << ans << endl;
}
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int id;
        cin >> id;
        cin >> val[id];
        int x;
        while(cin >> x && x){
            add(x,id);
            in[id]++;
        }
    }
    solve();
    return 0;
}