#include <bits/stdc++.h>
const int N = 2e4+10;
using namespace std;
int n, m;
vector<int> T[N];
int h[N],ne[N],node[N],idx = 0;
void add(int u, int v){
    node[++idx] = v;
    ne[idx] = h[u];
    h[u] = idx;
}
int in[N];
void solve1(){
    int D[N];
    copy(in+1,in+1+n,D+1);
    // for(int i = 1; i <= n; i++){
    //     cout << D[i] << ' ';
    // }
    // cout << endl;
    stack<int> ans;
    queue<int> q;
    int tot = 1;
    for(int i : T[tot]) D[i]--;
    for(int i = 1;i <= n; i++) {
        if(!D[i]){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        ans.push(t);
        tot++;
        for(int i : T[tot]){
            D[i]--;
            if(!D[i]) q.push(i);
        } 
        
        for(int i = h[t];i;i = ne[i]){
            int u = node[i];
            D[u]--;
            if(!D[u]) q.push(u);
        }
    }
    while(!ans.empty()){
        cout <<ans.top() << ' ';
        ans.pop();
    }
    // cout << 111;
    cout << endl;
    return;
}
void solve2(int x){
    int D[N];
    copy(in+1,in+1+n,D+1);
    queue<int> q;
    int tot = 1;
    for(int i : T[tot]) D[i]--;
    for(int i = 1;i <= n; i++) {
        if(!D[i]){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t == x && !q.empty()){
            q.push(t);
            t = q.front();
            q.pop();
        }
        if(t == x){
            cout << n-tot+1 << " ";
            return;
        }
        tot++;
        for(int i : T[tot]){
            D[i]--;
            if(!D[i]) q.push(i);
        } 
        
        for(int i = h[t];i;i = ne[i]){
            int u = node[i];
            D[u]--;
            if(!D[u]) q.push(u);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        k = n-k+1;
        in[i]++;
        T[k].push_back(i);
    }
    for(int i = 1;i <= m; i++){
        int a, b;
        cin >> a >> b;
        add(b,a);
        in[a]++;
    }
    solve1();
    for(int i = 1; i <= n; i++){
        solve2(i);
    }
    return 0;
}