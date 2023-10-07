#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
int n;
int idx = 0;
struct edge{
    int u, v, val;
}e[10005];
bool cmp(edge x, edge y){
    return x.val < y.val;
}
int g[200][200];
int fa[200];
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
int cnt = 0,sum = 0;
int main(){
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i =1;i <= n; i++) fa[i] = i;
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
            if(i <= j){
                if(!g[i][j]){
                    int fi = get(i),fj = get(j);
                    if(fi != fj){
                        fa[fi] = fj;
                        cnt++;
                    }
                }else{
                    e[++idx].u = i,e[idx].v = j,e[idx].val = g[i][j];
                    //cout << e[idx].val << endl;
                }
            }
        }
    }
    cout << n-1-cnt << endl;
    sort(e+1,e+1+idx,cmp);
    // for(int i =1 ;i <= idx; i++){
    //     cout << e[i].val << " ";
    // }
    for(int i = 1; i <= idx; i++){
        int fu = get(e[i].u), fv = get(e[i].v), w = e[i].val;
        
        if(fu != fv){
           // cout << w << " ";
            cnt++;
            sum += w;
            fa[fu] = fv;
        }
        if(cnt == n-1) break;
    }
    cout << sum << endl;
    return 0;
}
