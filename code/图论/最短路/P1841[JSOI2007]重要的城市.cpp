#include <bits/stdc++.h>

using namespace std;
int n, m;
long long f[300][300];
bool ans[300];
int g[300][300];
int main(){
    cin >> n >> m;
    memset(f,0x3f,sizeof f);
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = w;
    }
    for(int k = 1;k <= n ; k++){
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j || j == k || i == k) continue;
                if(f[i][k] + f[k][j] < f[i][j]){
                    g[i][j] = k;
                    f[i][j] = f[i][k] + f[k][j];
                }else if(f[i][k]+f[k][j] == f[i][j]) {
                    g[i][j] = 0;
                }
            }
        }
    }
    bool flag = 1;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= n; j++){
            ans[g[i][j]] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(ans[i]){
            cout << i << ' ';
            flag = 0;
        } 
    }
    if(flag) cout << "No important cities.";
    return 0;
}
/*
5 5
1 3 1
2 3 1
2 5 3
3 5 2
3 4 1

*/