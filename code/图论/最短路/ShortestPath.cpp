#include <bits/stdc++.h>
const int N = 3010;
const int M = 4e4+10;
#define ull unsigned long long
#define int ull
using namespace std;
int n, m, k;
vector<ull> e[N];
int dis[N][N];
int fa[N][N];
void print(int pre, int now){
    if(now == 1){
        cout << 1 << " ";
        return;
    }
    print(fa[pre][now],pre);
    cout << now << " ";
}
unsigned long long hs(ull x, ull y, ull z){
    return x*1000000000+y*10000+z;
}
map<unsigned long long,bool > swear;
bool bfs(){
    queue<pair<ull,ull> > q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        pair<ull,ull> x = q.front();
        q.pop();
        ull pre = x.first,u = x.second;
        if(u == n){
            cout<< dis[pre][u] << endl;
            print(pre,u);
            return 0;
        }
        for(ull v: e[u]){
            if(!swear.count(hs(pre,u,v)) && !dis[u][v]){
                fa[u][v] = pre;
                dis[u][v] = dis[pre][u]+1;
                q.push(make_pair(u,v));
            }
        }
    }
    return 1;
}
signed main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int x,y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        //add(x,y),add(y,x);
    }
    for(int i = 1;i <= k; i++){
        ull a, b, c;
        cin >> a>> b >> c;
        swear[hs(a,b,c)] = 1;
    }
    
    if(bfs())  cout << -1 << endl;
    return 0;
}