#include <bits/stdc++.h>
#include <cstring>
#define ll long long
using namespace std;
int n, m;
ll w[400][400],f[400][400];
ll c[400];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> c[i];
    }
    memset(f, 0x3f, sizeof f);
    for(int i = 1;i <= m; i++){
        int u, v,ww;
        cin >> u >> v >> ww;
        f[u][v] = f[v][u] = ww;
    }
    for(int k = 1; k <= n; k++){
        for(int i =1;i <= n; i++){
            if(i == k) continue;
            for(int j = 1; j <= n; j++){
                if(j == i || j == k) continue;
                //cout << f[i][k] << ' ' << f[k][j] << endl;
                if(f[i][j] > f[i][k] + f[k][j] - min(w[i][k],w[k][j])){
                    //cout << i << " " << j << ' ' << f[i][j] << endl;
                    f[i][j] = f[i][k] + f[k][j] - min(w[i][k],w[k][j]);
                    
                    w[i][j] = max(w[i][k],w[k][j]);
                    //cout << w[i][j] << endl;
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int s,t;
        cin >> s >> t;
        cout << f[s][t] << endl;
    }
    return 0;
}